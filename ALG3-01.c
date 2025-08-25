#include <stdio.h>

int fibonacci(int n) {
    printf("Entrando em fibonacci(%d)\n", n);

    if (n == 0) {
        printf("Caso base atingido: fibonacci(0) = 0\n");
        return 0;
    }
    if (n == 1) {
        printf("Caso base atingido: fibonacci(1) = 1\n");
        return 1;
    }

    int resultado = fibonacci(n - 1) + fibonacci(n - 2);
    printf("Retornando de fibonacci(%d) = %d\n", n, resultado);
    return resultado;
}

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        n = 0;
    }

    printf("Calculando fibonacci de %d...\n", n);
    int resultado = fibonacci(n);
    printf("Resultado final: %d\n", resultado);

    return 0;
}
