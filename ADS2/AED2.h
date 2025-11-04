/*
    ---------- TRABALHO 2 DE ALGORITMOS E ESTRUTURA DE DADOS -------------
    INTEGRANTES: LUCAS VINICIUS DA COSTA (16885265), HUMBERTO HENRIQUE DE AMORIM (16814612), EDUARDO MALAFRONTE ALVES DE SOUZA (16862798)
*/

#ifndef BIGINT_H
#define BIGINT_H
// tipo opaco que vai ser definido no .c
typedef struct BigInt BigInt;
// cria um espaço para alocar digitos
BigInt *inicializar(void);
// traduz as strings de numeros para numeros propriamente
int definir(BigInt *n, const char *decimal);
// retorna a soma de a + b
BigInt *soma(const BigInt *a, const BigInt *b);
// retorna o maior entre a e b
int maior(const BigInt *a, const BigInt *b);
// retorna o menor entre a e b
int menor(const BigInt *a, const BigInt *b);
// imprime o numero BigInt no stdout
void imprimir(const BigInt *n);
// destroi o numero bigint
void destruir(BigInt **n);

#endif