#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

typedef struct SparseMatrix SparseMatrix;

/* Cria matriz n x m vazia. Retorna ponteiro ou NULL. */
SparseMatrix* criar_matriz(int n, int m);

/* Define M[lin][col] = valor. Retorna 1 sucesso, 0 fora da faixa, −1 erro de memória. */
int set(SparseMatrix* M, int lin, int col, double valor);

/* Retorna M[lin][col]. Fora da faixa retorna 0.0 e não acessa memória. */
double get(const SparseMatrix* M, int lin, int col);

/* Libera a matriz. Usa ponteiro duplo porque zera o ponteiro do chamador. */
void destruir_matriz(SparseMatrix** M);

#endif
