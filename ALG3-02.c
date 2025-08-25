#include <stdio.h>

int somaparesrecursivo(int n[], int k) {
  if (k==0) {return 0;}
  int soma = somaparesrecursivo(n, k - 1);
    if (n[k - 1] % 2 == 0) {
        soma += n[k - 1];
    }
    return soma;
}

int main () {
  int tamanho;
  scanf("%d", &tamanho);
  int vetor[tamanho];

  for (int i = 0; i < tamanho; i++)
  {
    scanf("%d", &vetor[i]); 
  }

  printf("Soma dos pares: %d\n", somaparesrecursivo(vetor, tamanho));
  
}