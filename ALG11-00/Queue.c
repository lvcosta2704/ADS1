#include "Queue.h"                // Interface do TAD Fila
#include <stdlib.h>               // malloc e free

#define MAX 100                   // Capacidade máxima da fila (tamanho do vetor fixo)

struct queue
{
	int dados[MAX];
	int inicio;
	int fim;
	int qtd;
};

Queue* create_queue() {
	Queue *q = malloc(sizeof(Queue));
	if (!q) return NULL;
	q->fim=0;
	q->inicio=0;
	q->qtd=0;

	return q;
}

int is_empty(const Queue *q) {
	if (!q) return -1;
	if (q->qtd==0) return 1;
	return 0;
}

int is_full(const Queue *q) {
	if (!q) return -1;
	if (q->qtd==MAX) return 1;
	return 0;
}

int size(const Queue *q) {
	if (!q) return -1;
	return q->qtd;
}

int enqueue(Queue *q, int value) {
	if (!q) return -1;
	if (is_full(q)) return 0;
	else {
		q->dados[q->fim] = value;
		q->fim++;
		if (q->fim == MAX) q->fim = 0;
	}
	q->qtd++;
	return 1;
}

int dequeue(Queue *q, int *value) {
	if ((!q) || (!value)) return -1;
	if (is_empty(q)) return 0;
	else {
		*value = q->dados[q->inicio];
		q->inicio++;
		if (q->inicio == MAX) { 
			q->inicio = 0;          
		}
	}
	q->qtd--;
	return 1;
}

int front(const Queue *q, int *value) {
	if ((!q) || (!value)) return -1;
	if (is_empty(q)) return 0;
	else {
		*value = q->dados[q->inicio];
		return 1;
	}
}

void free_queue(Queue **q) {
	if (q) {
		free (*q);
		*q = NULL;
	}
}