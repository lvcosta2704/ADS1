#include <stdlib.h>
#include "SparseMatrix.h"

typedef struct node {
    int linha;               // índice da linha
    int coluna;              // índice da coluna
    double valor;            // valor não zero
    struct node *direita;    // próximo na mesma linha
    struct node *abaixo;     // próximo na mesma coluna
} Node;

struct SparseMatrix {
    Node **linhas;           // cabeças das listas por linha
    Node **colunas;          // cabeças das listas por coluna
    int nr_linhas;           // total de linhas
    int nr_colunas;          // total de colunas
};

SparseMatrix *criar_matriz(int n, int m) {
    if (n <= 0 || m <= 0) {
        return NULL;         // dimensões inválidas
    }

    SparseMatrix *mat = malloc(sizeof(SparseMatrix));
    if (!mat) {
        return NULL;         // falha de alocação
    }

    mat->linhas = malloc(sizeof(Node*) * n);   // vetor de linhas
    mat->colunas = malloc(sizeof(Node*) * m);  // vetor de colunas
    mat->nr_linhas = n;
    mat->nr_colunas = m;

    if (!mat->linhas || !mat->colunas) {
        free(mat->linhas);                    // libera parcial
        free(mat->colunas);
        free(mat);
        return NULL;                          // falha de alocação
    }

    for (int i = 0; i < mat->nr_linhas; i++) {
        mat->linhas[i] = NULL;                // lista vazia
    }
    for (int i = 0; i < mat->nr_colunas; i++) {
        mat->colunas[i] = NULL;               // lista vazia
    }

    return mat;                                // matriz criada
}

void destruir_matriz(SparseMatrix **mat) {
    if (!mat || !(*mat)) {
        return;                                 // nada a fazer
    }

    // percorre cada linha e libera nós
    for (int i = 0; i < (*mat)->nr_linhas; i++) {
        Node *p = (*mat)->linhas[i];
        while (p != NULL) {
            Node *prox = p->direita;            // salva próximo
            free(p);                             // libera atual
            p = prox;                            // avança
        }
        (*mat)->linhas[i] = NULL;               // zera cabeça
    }

    free((*mat)->linhas);                        // libera vetores
    free((*mat)->colunas);
    free(*mat);                                  // libera struct
    *mat = NULL;                                 // zera ponteiro externo
}

double get(const SparseMatrix *mat, int l, int c) {
    if (!mat) {
        return 0.0;                               // matriz nula
    }
    if (l < 0 || l >= mat->nr_linhas) {
        return 0.0;                               // fora da faixa
    }
    if (c < 0 || c >= mat->nr_colunas) {
        return 0.0;                               // fora da faixa
    }

    // busca pela coluna c
    Node *tmp = mat->colunas[c];
    while (tmp != NULL) {
        if (tmp->linha == l) {
            return tmp->valor;                    // encontrado
        }
        tmp = tmp->abaixo;                        // desce
    }
    return 0.0;                                   // ausente
}

int set(SparseMatrix *m, int l, int c, double v) {
    if (!m) {
        return -1;                                // erro
    }
    if (l < 0 || l >= m->nr_linhas) {
        return 0;                                 // fora da faixa
    }
    if (c < 0 || c >= m->nr_colunas) {
        return 0;                                 // fora da faixa
    }

    // procura na coluna c até linha >= l
    Node *q = m->colunas[c];
    Node *qa = NULL;                              // anterior na coluna
    while (q != NULL && q->linha < l) {
        qa = q;
        q = q->abaixo;
    }
    if (q != NULL && q->linha == l) {
        q->valor = v;                             // atualização
        return 1;                                 // sucesso
    }

    // cria novo nó
    Node *novo = malloc(sizeof(Node));
    if (!novo) {
        return -1;                                // sem memória
    }
    novo->linha = l;
    novo->coluna = c;
    novo->valor = v;
    novo->direita = NULL;
    novo->abaixo = q;                             // liga abaixo

    // insere na coluna
    if (qa == NULL) {
        m->colunas[c] = novo;                     // novo é cabeça
    } else {
        qa->abaixo = novo;                        // liga anterior
    }

    // insere na linha l na posição ordenada por coluna
    q = m->linhas[l];
    qa = NULL;                                    // anterior na linha
    while (q != NULL && q->coluna < c) {
        qa = q;
        q = q->direita;
    }
    novo->direita = q;                            // encadeia à direita
    if (qa == NULL) {
        m->linhas[l] = novo;                      // novo é cabeça
    } else {
        qa->direita = novo;                       // liga anterior
    }

    return 1;                                     // inserção ok
}
