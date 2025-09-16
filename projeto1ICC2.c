#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void selectionSort(int vetor[], int n) {
  for (int i = 0; i < n - 1; i++) {
    // define um minimo para ir comparando no vetor adiante
    int minimo = i;
    for (int j = i + 1; j < n; j++) {
      // debug
      printf("C %d %d\n", minimo, j);
      // se encontra um minimo menor do que o minimo atual, atualiza o minimo
      if (vetor[j] < vetor[minimo]) {
        minimo = j;
      }
    }
      // troca de posicao o valor que esta na posicao que guarda o menor numero com o numero mais a esquerda da parte do vetor que ainda nao esta ordenada
      int tmp = vetor[i];
      vetor[i] = vetor[minimo];
      vetor[minimo] = tmp;
      printf("T %d %d\n", i, minimo); // debug
  }
}
void bubbleSort(int vetor[], int n) {
    int i = n-1;

    while (i > 0)
    {
      int sentinela = -1;
      for (int j = 0; j < i; j++)
      {
        printf("C %d %d\n", j, j+1);
        if (vetor[j] > vetor[j+1])
        {
          printf("T %d %d\n", j, j+1);
          int tmp = vetor[j];
          vetor[j] = vetor[j+1];
          vetor[j+1] = tmp;

          sentinela = j;
        }
      }
      i = sentinela;
    } 
}
void printaVetor(int vetor[], int n) { // funcao que printa o vetor
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", vetor[i]);
  }
  printf("\n");
}
int main () {
  char *opcao = (char *)malloc(10*sizeof(char)); // aloca memoria para a string
  int tam;
  // captura a opcao e o tamanho do vetor de numeros
  scanf("%s", opcao);
  scanf("%d", &tam);
  int *numeros = (int *)malloc(tam * sizeof(int));
  for (int i = 0; i < tam; i++)
  {
    scanf("%d", &numeros[i]);
  }
  // cada comparacao analisa a opcao e depois executa o que foi pedido e printa os vetores ordenados
  if (strcmp(opcao, "selecao")==0)
  {
    selectionSort(numeros, tam);
    printaVetor(numeros, tam);
  }
  
  else if (strcmp(opcao, "bolha")==0)
  {
    bubbleSort(numeros, tam);
    printaVetor(numeros, tam);
  }
  free(numeros);
  free(opcao); // libera a memoria alocada para o ponteiro de char
  return 0;
}