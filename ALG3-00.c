#include <stdio.h>

int fatorial(int n) {
    printf("Entrando em fatorial(%d)\n", n);

    if (n == 1 || n == 0) {
        printf("Caso base atingido: fatorial(%d) = 1\n", n);
        return 1;
    }

    int resultado = n * fatorial(n - 1);
    printf("Retornando de fatorial(%d) = %d\n", n, resultado);
    return resultado;
}

int main() {
    int numero;
    if (scanf("%d", &numero) != 1) {
      numero = 0;
    }

    printf("Calculando fatorial de %d...\n", numero);
    int resultado = fatorial(numero);
    printf("Resultado final: %d\n", resultado);

    return 0;
}
