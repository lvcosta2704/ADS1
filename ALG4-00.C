#include <stdio.h>
void hanoi (int n, char origem, char destino, char aux) {
    if (n==1)
    {
        printf("Mova o disco 1 de %c para %c\n", origem, destino);
        return;
    }
 
    hanoi(n-1, origem, aux, destino);

    printf("Mova o disco %d de %c para %c\n", n, origem, destino);

    hanoi(n-1, aux, destino, origem);
}
int main () {
    int numero;
    scanf("%d", &numero);

    hanoi(numero, 'A', 'C', 'B');
}