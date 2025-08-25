#include <stdio.h>
int buscaSequencial(int vetor[], int k) {
  // captura do target para procura
  int target;
  scanf("%d", &target);
  // busca sequencial do vetor
  for (int i = 0; i < k; i++)
  {
    if (vetor[i] == target)
    {
      return 1;
    }
  }
}
void inverteNumeros(int vetor[], int k){
  // inversao dos numeros
  for (int i = 0; i < k/2; i++)
  {
    int tmp = vetor[i];
    vetor[i] = vetor[k-1-i];
    vetor[k-1-i] = tmp;
  }
}
int buscaBinariaIterativa(int vetor[], int target, int tam) {
  int inicio = 0;
  int fim = tam-1;
  
  // começo do laço para buscar por divisao e conquista
  while (inicio <= fim) {
    // sempre que o laço rodar ele atualiza o meio para ficar ciente onde ele está
    int meio = inicio + (fim - inicio)/2; 
    // se o meio for o numero procurado, retorna o indice do meio
    if (target == vetor[meio]){
      return meio;
    }
    // se o valor presente no vetor procurado indexado com o valor meio for menor, quer dizer que o valor procurado está a direta do meio, logo atualiza o inicio
    if (vetor[meio] < target) {
      inicio = meio+1;
    }
    // se o valor presente no vetor procurado indexado com o valor meio for maior, quer dizer que o valor procurado está a esquerda do meio, logo atualiza o fim
    else {
      fim = meio-1;
    }
} //se nao achar retorna -1
      return -1;
}
int buscaBinariaRecursiva(int vetor[], int target, int inicio, int fim) {
  if (fim >= inicio)
  {
    // sempre que o laço rodar ele atualiza o meio para ficar ciente onde ele está
    int meio = inicio + (fim - inicio)/2; 
    // se o meio for o numero procurado, retorna o indice do meio
    if (vetor[meio] == target)
    {
      return meio;
    }
    // se o valor presente no vetor no indice meio for maior que o valor procurado, quer dizer que o target está a esquerda do meio, logo chama recursivamente a funcao alterando o valor do fim para meio-1
    if (vetor[meio] > target)
    {
      return buscaBinariaRecursiva(vetor, target, inicio, meio-1);
    }
    // se o valor presente no vetor no indice meio for menor que o valor procurado, quer dizer que o target está a direita do meio, logo chama recursivamente a funcao alterando o valor do inicio para meio+1
    if (vetor[meio] < target)
    {
      return buscaBinariaRecursiva(vetor, target, meio+1, fim);
    } 
  } // retorna -1 pois ele já varreu todo o vetor
  return -1;
}
int main () {
  int n;
  // captura do tamanho do array de numeros
  scanf("%d", &n);
  // captura dos numeros
  int numeros[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &numeros[i]);
  }
}