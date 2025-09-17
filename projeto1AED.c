#include <stdio.h>
#include <sys/time.h>

// busca sequencial agora recebe o alvo como argumento
int buscaSequencial(int vetor[], int k, int alvo)
{
  // busca sequencial do vetor
  for (int i = 0; i < k; i++)
  {
    if (vetor[i] == alvo) // roda ate encontrar o elemento procurado
    {
      return i;
    }
  }
  return -1; // se nao achar, retorna falha
}
void inverteNumeros(int vetor[], int k)
{
  // apenas imprime o vetor invertido, sem modificá-lo na memória
  for (int i = k - 1; i >= 0; i--)
  {
    if (i < k - 1) // arruma o espaçamento no final 
      printf(" ");
    printf("%d", vetor[i]);
  }
  printf("\n");
}
int buscaBinariaIterativa(int vetor[], int alvo, int tam)
{
  int inicio = 0;
  int fim = tam - 1;

  // começo do laço para buscar por divisao e conquista
  while (inicio <= fim)
  {
    // sempre que o laço rodar ele atualiza o meio para ficar ciente onde ele está
    int meio = inicio + (fim - inicio) / 2;
    // se o meio for o numero procurado, retorna o indice do meio
    if (alvo == vetor[meio])
    {
      return meio;
    }
    // se o valor presente no vetor procurado indexado com o valor meio for menor, quer dizer que o valor procurado está a direta do meio, logo atualiza o inicio
    if (vetor[meio] < alvo)
    {
      inicio = meio + 1;
    }
    // se o valor presente no vetor procurado indexado com o valor meio for maior, quer dizer que o valor procurado está a esquerda do meio, logo atualiza o fim
    else
    {
      fim = meio - 1;
    }
  } // se nao achar retorna -1
  return -1;
}
int buscaBinariaRecursiva(int vetor[], int alvo, int inicio, int fim)
{
  if (fim >= inicio)
  {
    // sempre que o laço rodar ele atualiza o meio para ficar ciente onde ele está
    int meio = inicio + (fim - inicio) / 2;
    // se o meio for o numero procurado, retorna o indice do meio
    if (vetor[meio] == alvo)
    {
      return meio;
    }
    // se o valor presente no vetor no indice meio for maior que o valor procurado, quer dizer que o alvo está a esquerda do meio, logo chama recursivamente a funcao alterando o valor do fim para meio-1
    if (vetor[meio] > alvo)
    {
      return buscaBinariaRecursiva(vetor, alvo, inicio, meio - 1);
    }
    // se o valor presente no vetor no indice meio for menor que o valor procurado, quer dizer que o alvo está a direita do meio, logo chama recursivamente a funcao alterando o valor do inicio para meio+1
    if (vetor[meio] < alvo)
    {
      return buscaBinariaRecursiva(vetor, alvo, meio + 1, fim);
    }
  } // retorna -1 pois ele já varreu todo o vetor
  return -1;
}
int main()
{
  struct timeval inicio, fim;
  long segundos, microssegundos;
  int n, alvo;
  // captura do tamanho do array de numeros
  scanf("%d", &n);
  // captura dos numeros
  int numeros[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &numeros[i]);
  }
  // inicializa uma variavel escolha
  int escolha = 0;
  while (scanf("%d", &escolha) == 1)
  {
    if (escolha == 5)
      break;

    switch (escolha)
    {
    case 1:
    {
      // ATENCAO: para todos os switch cases a documentação vai ser a mesma na parte do calculo de tempo, logo basta essa documentacao do case 1

      gettimeofday(&inicio, NULL); // calcula o tempo decorrido da funcao entre as funcoes gettimeofday
      inverteNumeros(numeros, n);  // funcao a ser calculada o tempo
      gettimeofday(&fim, NULL);
      segundos = fim.tv_sec - inicio.tv_sec;         // calculo dos segundos
      microssegundos = fim.tv_usec - inicio.tv_usec; // calculo dos microssegundos
      if (microssegundos < 0)                        // recalcula a precisao se o tempo for menor que 0
      {
        segundos -= 1;
        microssegundos += 1000000;
      }
      // printf("Tempo decorrido: %ld.%06ld segundos\n", segundos, microssegundos);
      // os printf's estao comentados para passar nos testes do RUNCODES
      break;
    }
    case 2:
    {
      if (scanf("%d", &alvo) != 1)
        break;
      gettimeofday(&inicio, NULL);
      int resultadobuscaSeq = buscaSequencial(numeros, n, alvo);
      // uso de um operador ternário
      gettimeofday(&fim, NULL);
      segundos = fim.tv_sec - inicio.tv_sec;
      microssegundos = fim.tv_usec - inicio.tv_usec;
      if (microssegundos < 0)
      {
        segundos -= 1;
        microssegundos += 1000000;
      }
      // printf("Tempo decorrido: %ld.%06ld segundos\n", segundos, microssegundos);
      resultadobuscaSeq == -1 ? printf("NAO\n") : printf("SIM\n");
      break;
    }
    case 3:
    {
      if (scanf("%d", &alvo) != 1)
        break;
      gettimeofday(&inicio, NULL);
      int resultadobuscaBinIt = buscaBinariaIterativa(numeros, alvo, n);
      gettimeofday(&fim, NULL);
      segundos = fim.tv_sec - inicio.tv_sec;
      microssegundos = fim.tv_usec - inicio.tv_usec;
      if (microssegundos < 0)
      {
        segundos -= 1;
        microssegundos += 1000000;
      }
      // printf("Tempo decorrido: %ld.%06ld segundos\n", segundos, microssegundos);
      resultadobuscaBinIt == -1 ? printf("NAO\n") : printf("SIM\n");
      break;
    }
    case 4:
    {
      if (scanf("%d", &alvo) != 1)
        break;
      gettimeofday(&inicio, NULL);
      int resultadobuscaBinRec = buscaBinariaRecursiva(numeros, alvo, 0, n - 1);
      gettimeofday(&fim, NULL);
      segundos = fim.tv_sec - inicio.tv_sec;
      microssegundos = fim.tv_usec - inicio.tv_usec;
      if (microssegundos < 0)
      {
        segundos -= 1;
        microssegundos += 1000000;
      }
      // printf("Tempo decorrido: %ld.%06ld segundos\n", segundos, microssegundos);
      resultadobuscaBinRec == -1 ? printf("NAO\n") : printf("SIM\n");
      break;
    }
    case 5:
      break; // Sai do programa
    default:
      break;
    }
  }
  return 0;
}