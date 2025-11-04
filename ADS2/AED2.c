/*
    ---------- TRABALHO 2 DE ALGORITMOS E ESTRUTURA DE DADOS -------------
    INTEGRANTES: LUCAS VINICIUS DA COSTA (16885265), HUMBERTO HENRIQUE DE AMORIM (16814612), EDUARDO MALAFRONTE ALVES DE SOUZA (16862798)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AED2.h"
// definicao do nó que guardará 4 digitos em char (+1 para terminador)
typedef struct node
{
    char digitos[6];
    struct node *next;
} Node;
// definicao da estrutura de numero, que é semelhante a uma lista ligada
struct BigInt
{
    Node *head;
    char sinal;
    int qtd_bloco;
};
// funcao responsável por inicializar uma lista de algarismos = numero grande
BigInt *inicializar(void)
{
    BigInt *N = malloc(sizeof(BigInt));
    if (!N)
    {
        return NULL; // alocacao falhou
    }
    N->head = NULL;
    return N;
}
// esta funcao fica encarregada de transformar strings de numeros em uma lista ligada de numeros
int definir(BigInt *n, const char *decimal)
{
    if ((!n) || (!decimal))
    {
        return -1; // erro de alocacao
    }

    // supoe que sinal é +
    n->sinal = '+';
    if (decimal[0] == '-')
    {
        n->sinal = '-';
        decimal++; // incrementa o ponteiro pra frente
    }
    else if (decimal[0] == '+')
    {
        decimal++; // incrementa o ponteiro pra frente
    }

    // esta parte se designa a tratar os zeros a esquerda do numero
    // se continuar encontrando zeros ele passa para frente para checar o proximo numero

    while (*decimal == '0' && strlen(decimal) > 1)
    {
        decimal++;
    }
    // se tudo for zero atribui o sinal positivo
    if (strcmp(decimal, "0") == 0)
    {
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
        else
        {
            tam_bloco = 4;
            inicio_bloco = posatual - tam_bloco;
        }

        Node *novo = malloc(sizeof(Node)); // aloca o novo node para colocar os digitos
        if (!novo)
            return -1; // nao foi alocado o nó

        strncpy(novo->digitos, decimal + inicio_bloco, tam_bloco); // copia o conteudo do ponteiro decimal para a estrutura digitos
        novo->digitos[tam_bloco] = '\0';                           // adiciona o \0 no final da string

        novo->next = n->head; // insere o nó no numero grande
        n->head = novo;

        posatual -= tam_bloco; // atualiza a postual que esta percorrendo no ponteiro decimal
        n->qtd_bloco++;
    }
    return 1;
}
// funcao de somar dois numeros BigInts
BigInt *soma(const BigInt *a, const BigInt *b)
{
    if ((!a) || (!b))
        return NULL; // ponteiros de numeros invalidos

    // copia blocos de cada BigInt para vetores inteiros, onde index 0 é o bloco mais significativo
    int na = a->qtd_bloco;
    int nb = b->qtd_bloco;

    int *vetA = NULL;
    int *vetB = NULL;
    if (na > 0)// se o numero tem mais de 1 bloco este if aloca um vetor de ints para colocar os numeros
    {
        vetA = malloc(sizeof(int) * na);
        if (!vetA)
            return NULL; // tratamento dos endereços nao alocados
    }
    if (nb > 0) // se o numero tem mais de 1 bloco este if aloca um vetor de ints para colocar os numeros
    {
        vetB = malloc(sizeof(int) * nb);
        if (!vetB)
        {
            free(vetA); // tratamento dos endereços nao alocados
            return NULL;
        }
    }

    Node *tmp = a->head;
    // esses dois for's sao resposaveis por encher os vetores com os numeros convertidos para int pela funcao atoi()
    for (int i = 0; i < na; i++)
    {
        vetA[i] = atoi(tmp->digitos);
        tmp = tmp->next;
    }
    tmp = b->head;
    for (int i = 0; i < nb; i++)
    {
        vetB[i] = atoi(tmp->digitos);
        tmp = tmp->next;
    }

    BigInt *res = inicializar(); // inicializa uma lista(numero de resposta)
    if (!res)
    {
        free(vetA);
        free(vetB);
        return NULL;
    }
    res->head = NULL;
    res->qtd_bloco = 0;

    int carry = 0;
    int ia = na - 1;
    int ib = nb - 1;
    // dentro desse while acontecem as somas e tratamentos dos carrys
    while (ia >= 0 || ib >= 0 || carry)
    {
        int va = (ia >= 0) ? vetA[ia] : 0;
        int vb = (ib >= 0) ? vetB[ib] : 0;
        int sum = va + vb + carry;
        carry = sum / 10000;
        int bloco = sum % 10000;

        Node *novo = malloc(sizeof(Node));
        if (!novo) // se o novo nao for alocado entao temos que liberar todo os numeros criados ate agora
        {
            // libera lista res alocada até aqui
            Node *t;
            while (res->head)
            {
                t = res->head;
                res->head = res->head->next;
                free(t);
            }
            free(res);
            free(vetA);
            free(vetB);
            return NULL;
        }
        // a funcao snprintf é resposavel por tratar os paddings de zeros nos numeros que necessitam
        snprintf(novo->digitos, sizeof(novo->digitos), "%04d", bloco);
        // insere o bloco novo na lista BigInt res
        novo->next = res->head;
        res->head = novo;
        res->qtd_bloco++;

        ia--;
        ib--;
    }

    res->sinal = '+';
    free(vetA);
    free(vetB);
    return res;
}
// imprime um BigInt no stdout
void imprimir(const BigInt *n)
{
    if (!n)
    {
        printf("0");
        return;
    }
    if (!n->head)
    {
        printf("0");
        return;
    }
    Node *tmp = n->head;
    // imprime sinal se for negativo
    if (n->sinal == '-')
        printf("-");
    // imprime primeiro bloco sem padding (pode ter menos de 4 digitos)
    int primeiro = atoi(tmp->digitos);
    printf("%d", primeiro);
    tmp = tmp->next;
    // os blocos seguintes devem ter 4 digitos com padding de zeros à esquerda
    while (tmp)
    {
        printf("%04d", atoi(tmp->digitos));
        tmp = tmp->next;
    }
}
// funcao resposável por determinar entre dois numeros BigInts qual deles é o maior
int maior(const BigInt *a, const BigInt *b)
{
    if ((!a) || (!b))
        return -1; // ponteiros nao alocados, retorna fracasso

    // checagem se sinais sao diferentes

    if (a->sinal != b->sinal)
    {
        return (a->sinal == '+') ? 1 : 0; // uso de ternario para determinar se o sinal de A é positivo e se for ele é maior do que B, pois os sinais sao diferentes nesse caso de if
    }

    // checagem da grandeza de blocos em cada numero
    // assumindo que ambos tem sinais iguais, pois nao entrou no if de cima
    if (a->qtd_bloco != b->qtd_bloco)
    {
        // se a é positivo entao quem tem mais blocos é o maior
        if (a->sinal == '+')
        {
            return (a->qtd_bloco > b->qtd_bloco) ? 1 : 0;
        }
        else
        {
            return (a->qtd_bloco < b->qtd_bloco) ? 1 : 0; // se a tem sinal negativo entao quem tem menos blocos é o maior
        }
    }

    // se a quantidade de blocos é igual entao é preciso analisar cada algarismo dos blocos
    int vet1[a->qtd_bloco];
    int vet2[b->qtd_bloco];
    Node *temp1 = a->head;
    Node *temp2 = b->head;

    /* preenche vetores de blocos com o bloco mais significativo em vet[0] */
    for (int i = 0; i < a->qtd_bloco; i++)
    {
        vet1[i] = atoi(temp1->digitos);
        temp1 = temp1->next;
    }

    for (int i = 0; i < b->qtd_bloco; i++)
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
            }
            else
            {
                return (vet1[i] < vet2[i]) ? 1 : 0;
            }
        }
    }
    return 0; // se for 0 eles sao iguais
}

// funcao resposável por determinar entre dois numeros BigInts qual deles é o menor
int menor(const BigInt *a, const BigInt *b)
{
    if ((!a) || (!b))
        return -1; // ponteiros nao inicializados
    // checagem da diferença de sinais entre os numeros, se for negativo o a entao ele ja é o menor por si só
    if (a->sinal != b->sinal)
        return (a->sinal == '-') ? 1 : 0;
    // checagem na quantidade de blocos que cada um tem para saber qual é o menor
    if (a->qtd_bloco != b->qtd_bloco)
    {
        if (a->sinal == '-')
        {
            return (a->qtd_bloco > b->qtd_bloco) ? 1 : 0;
            // se o sinal for negativo entao o menor tera a maior quantidade de blocos
        }
        else
        {
            return (a->qtd_bloco < b->qtd_bloco) ? 1 : 0;
            // se o sinal for positivo entao o com menos blocos é o menor
        }
    }

    // a partir daqui assume-se que a quantidade de blocos e o sinal sao iguais, logo compara-se algarismo a algarismo
    int vet1[a->qtd_bloco];
    int vet2[b->qtd_bloco];
    Node *temp1 = a->head;
    Node *temp2 = b->head;

    /* preenche vetores de blocos com o bloco mais significativo em vet[0] */
    for (int i = 0; i < a->qtd_bloco; i++)
    {
        vet1[i] = atoi(temp1->digitos);
        temp1 = temp1->next;
    }
    for (int i = 0; i < b->qtd_bloco; i++)
    {
        vet2[i] = atoi(temp2->digitos);
        temp2 = temp2->next;
    }

    for (int i = 0; i < a->qtd_bloco; i++)
    {
        if (vet1[i] != vet2[i])
        {
            if (a->sinal == '+')
            { // se positivo quem tem o menor valor absoluto é o menor
                return (vet1[i] < vet2[i]) ? 1 : 0;
            }
            else
            { // se negativo, quem tem o maior valor absoluto é menor
                return (vet1[i] > vet2[i]) ? 1 : 0;
            }
        }
    }

    return 0; // sao iguais os numeros
}

void destruir(BigInt **n)
{
    if (!n || !(*n))
    {
        return; // lista nao esta nem inicializada
    }
    Node *tmp = (*n)->head;
    while (tmp != NULL)
    {
        Node *rem = tmp; // salva o endereço do node tmp em um REM
        tmp = tmp->next; // atualiza o tmp para o proximo da lista
        free(rem);       // libera o rem da memoria
    }
    free(*n);
    *n = NULL; // aponta n pra NULL para evitar doublefree por exemplo
}