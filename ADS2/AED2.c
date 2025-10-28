/*
    ---------- TRABALHO 1 DE ALGORITMOS E ESTRUTURA DE DADOS -------------
    INTEGRANTES: LUCAS VINICIUS DA COSTA (16885265), HUMBERTO HENRIQUE DE AMORIM (16814612), EDUARDO MALAFRONTE ALVES DE SOUZA (16862798)
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AED2.h"

typedef struct node {
    char digitos[5];
    struct node *next;
}Node;

struct BigInt {
    Node *head;
    char sinal;
    int qtd_bloco;
};

BigInt *inicializar(void) {
    BigInt *N = malloc(sizeof(BigInt));
    if (!N)
    {
        return NULL; //alocacao falhou
    }
    N->head = NULL;
    return N;
}

int definir(BigInt *n, const char *decimal){
    if ((!n) || (!decimal)) {
        return -1; // erro de alocacao
    }

    //supoe que sinal é +
    n->sinal = '+';
    if (decimal[0] == '-')
    {
        n->sinal = '-';
        decimal++; // incrementa o ponteiro pra frente
    }
    else if (decimal[0] == '+'){
        decimal++; // incrementa o ponteiro pra frente
    }

    // esta parte se designa a tratar os zeros a esquerda do numero
    // se continuar encontrando zeros ele passa para frente para checar o proximo numero

    while (*decimal == '0' && strlen(decimal) > 1)
    {
        decimal++;
    }
    // se tudo for zero atribui o sinal positivo
    if (strcmp(decimal, "0") == 0) {
        n->sinal = '+';
    }

    int len = strlen(decimal);
    int posatual = len;
    // se certifica que a lista esta vazia
    n->head = NULL;
    // esta parte se designa a alocar corretamente os blocos e seus tamanhos
    n->qtd_bloco = 0;
    while (posatual > 0)
    {
        int tam_bloco, inicio_bloco;

        // se posicao for menor que o bloco de 4 digitos, isso quer dizer que o numero sera menor que 4 digitos
        if (posatual < 4) 
        {
            tam_bloco = posatual;
            inicio_bloco = 0;
        }
        // se for maior precisamos colocar em blocos diferentes
        else {
            tam_bloco = 4;
            inicio_bloco = posatual - tam_bloco;
        }

        Node *novo = malloc(sizeof(Node)); // aloca o novo node para colocar os digitos
        if (!novo) return -1; // nao foi alocado o nó

        strncpy(novo->digitos, decimal+inicio_bloco, tam_bloco); // copia o conteudo do ponteiro decimal para a estrutura digitos
        novo->digitos[tam_bloco] = '\0'; // adiciona o \0 no final da string

        novo->next = n->head; // insere o nó no numero grande
        n->head = novo;

        posatual -= tam_bloco; // atualiza a postual que esta percorrendo no ponteiro decimal
        n->qtd_bloco++;
    }
    return 1;    
}

BigInt *soma(const BigInt *a, const BigInt *b){
    if ((!a) || (!b)) return -1; // ponteiros de numeros invalidos

    BigInt *res = inicializar(); // inicializa uma lista(numero de resposta)

    Node *sa = a->head; //primeiro numero da esquerda pra direita do numero (EM FORMATO DE STRING AINDA)
    Node *sb = b->head; //mesma coisa do de cima
    int carry = 0;

    while (sa || sb || carry)
    {
        int na = sa ? atoi(sa->digitos) : 0; //usa-se ternario para ver a validade do ponteiro e converter com o atoi() para um inteiro
        int nb = sb ? atoi(sb->digitos) : 0;
        int sum = na + nb + carry;
        carry = sum / 10000; // divide por 10000 porque o maior numero que cada um tem é 9999, ou seja a soma pode ser maior do que 9999, ou seja, carry 0 ou 1
        int bloco = sum % 10000;

        Node *novo = malloc(sizeof(Node));
        if (!novo){
            Node *tmp; // cria um nó temporario para percorer o vetor 
            while (res->head) // enquanto head nao aponta pra NULL (ou seja chegou no final)
            {
                tmp = res->head; // antes de retornar NULL tem que dar free no res que ja foi alocado lá em cima
                res->head = res->head->next;
                free(tmp);
            }
            free(res);
            return NULL;
        }
        // arruma o offset de zeros com o snprintf
        snprintf(novo->digitos, 5, "%04d", bloco);
        // coloca o bloco de resposta na lista
        novo->next = res->head;
        res->head = novo;
        // recebe o proximo bloco da lista de digitos
        if (sa)
        {
            sa = sa->next;
        }
        if (sb)
        {
            sb = sb->next;
        } 
    }

    res->sinal = '+';
    return res;
}

int maior(const BigInt *a, const BigInt *b){
    if ((!a) || (!b)) return -1; // ponteiros nao alocados, retorna fracasso

    //checagem se sinais sao diferentes

    if (a->sinal != b->sinal) {
        return (a->sinal == '+') ? 1 : 0; // uso de ternario para determinar se o sinal de A é positivo e se for ele é maior do que B, pois os sinais sao diferentes nesse caso de if
    }
    
    //checagem da grandeza de blocos em cada numero
    //assumindo que ambos tem sinais iguais, pois nao entrou no if de cima
    if (a->qtd_bloco != b->qtd_bloco) {
        // se a é positivo entao quem tem mais blocos é o maior
        if (a->sinal == '+') {
            return (a->qtd_bloco > b->qtd_bloco) ? 1 : 0;
        } else {
        return (a->qtd_bloco < b->qtd_bloco) ? 1 : 0; // se a tem sinal negativo entao quem tem menos blocos é o maior
        }
    }

    // se a quantidade de blocos é igual entao é preciso analisar cada algarismo dos blocos
    int vet1[a->qtd_bloco];
    int vet2[b->qtd_bloco];
    Node *temp1 = a->head;
    Node *temp2 = b->head;

    for (int i = a->qtd_bloco-1; i >= 0 ; i--)
    {
        vet1[i] = atoi(temp1->digitos);
        temp1 = temp1->next;
    }

    for (int i = b->qtd_bloco-1; i >= 0 ; i--)
    {
        vet2[i] = atoi(temp2->digitos);
        temp2 = temp2->next;
    }

    for (int i = 0; i < a->qtd_bloco; i++)
    {
        if (vet1[i] != vet2[i])
        {
            if (a->sinal == '+')
            {
                return (vet1[i] > vet2[i]) ? 1 : 0;
            } else {
                return (vet1[i] < vet2[i]) ? 1 : 0;
            }
        }
    }
    return 0; // se for 0 eles sao iguais
    
    
}


int menor(const BigInt *a, const BigInt *b){
    if ((!a) || (!b)) return -1; // ponteiros nao inicializados
    // checagem da diferença de sinais entre os numeros, se for negativo o a entao ele ja é o menor por si só
    if (a->sinal != b->sinal) return (a->sinal == '-') ? 1 : 0;
    // checagem na quantidade de blocos que cada um tem para saber qual é o menor
    if (a->qtd_bloco != b->qtd_bloco) {
        if (a->sinal == '-') {
            return (a->qtd_bloco > b->qtd_bloco) ? 1 : 0;
            // se o sinal for negativo entao o menor tera a maior quantidade de blocos
        } else {
            return (a->qtd_bloco < b->qtd_bloco) ? 1 : 0;
            //se o sinal for positivo entao o com menos blocos é o menor
        }
    }
    
    // a partir daqui assume-se que a quantidade de blocos e o sinal sao iguais, logo compara-se algarismo a algarismo
    int vet1[a->qtd_bloco];
    int vet2[b->qtd_bloco];
    Node *temp1 = a->head;
    Node *temp2 = b->head;

    for (int i = a->qtd_bloco - 1; i >= 0 ; i--) {
        vet1[i] = atoi(temp1->digitos);
        temp1 = temp1->next;
    }
    for (int i = b->qtd_bloco - 1; i >= 0 ; i--) {
        vet2[i] = atoi(temp2->digitos);
        temp2 = temp2->next;
    }

    for (int i = 0; i < a->qtd_bloco; i++) {
        if (vet1[i] != vet2[i]) { 
            if (a->sinal == '+') { // se positivo quem tem o menor valor absoluto é o menor
                return (vet1[i] < vet2[i]) ? 1 : 0;
            } else { // se negativo, quem tem o maior valor absoluto é menor
                return (vet1[i] > vet2[i]) ? 1 : 0;
            }
        }
    }

    return 0; // sao iguais os numeros
}

void destruir(BigInt **n) {
    if (!n || !(*n)) {
        return; // lista nao esta nem inicializada
    }
    Node *tmp = (*n)->head;
	while (tmp != NULL) {
		Node *rem = tmp; // salva o endereço do node tmp em um REM
		tmp = tmp->next; // atualiza o tmp para o proximo da lista
		free(rem); // libera o rem da memoria
	}
    free(*n);
	*n = NULL; // aponta n pra NULL para evitar doublefree por exemplo
}