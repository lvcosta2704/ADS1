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
    }
    
    
    
}
