#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// variavel global para contar operacoes
long long contadorOperacoes = 0;

// busca sequencial com contador de operacoes
int buscaSequencial(int vetor[], int k, int alvo)
{
    contadorOperacoes = 0; // reseta o contador
    // busca sequencial do vetor
    for (int i = 0; i < k; i++)
    {
        contadorOperacoes++; // conta a comparacao
        if (vetor[i] == alvo)
        {
            return i;
        }
    }
    return -1;
}

// funcao para inverter numeros com contador
void inverteNumeros(int vetor[], int k)
{
    contadorOperacoes = 0; // reseta o contador
    // inversao dos numeros
    for (int i = 0; i < k / 2; i++)
    {
        contadorOperacoes += 3; // conta cada operacao da troca (tmp, vetor[i], vetor[k-1-i])
        int tmp = vetor[i];
        vetor[i] = vetor[k - 1 - i];
        vetor[k - 1 - i] = tmp;
    }
}

// busca binaria iterativa com contador
int buscaBinariaIterativa(int vetor[], int alvo, int tam)
{
    contadorOperacoes = 0; // reseta o contador
    int inicio = 0;
    int fim = tam - 1;

    // comeco do laco para buscar por divisao e conquista
    while (inicio <= fim)
    {
        // sempre que o laco rodar ele atualiza o meio para ficar ciente onde ele esta
        int meio = inicio + (fim - inicio) / 2;
        
        contadorOperacoes++; // conta a comparacao principal
        // se o meio for o numero procurado, retorna o indice do meio
        if (alvo == vetor[meio])
        {
            return meio;
        }
        
        // se o valor presente no vetor procurado indexado com o valor meio for menor, quer dizer que o valor procurado esta a direta do meio, logo atualiza o inicio
        if (vetor[meio] < alvo)
        {
            inicio = meio + 1;
        }
        // se o valor presente no vetor procurado indexado com o valor meio for maior, quer dizer que o valor procurado esta a esquerda do meio, logo atualiza o fim
        else
        {
            fim = meio - 1;
        }
    } // se nao achar retorna -1
    return -1;
}

// busca binaria recursiva com contador
int buscaBinariaRecursivaAux(int vetor[], int alvo, int inicio, int fim)
{
    if (fim >= inicio)
    {
        // sempre que o laco rodar ele atualiza o meio para ficar ciente onde ele esta
        int meio = inicio + (fim - inicio) / 2;
        
        contadorOperacoes++; // conta a comparacao principal
        // se o meio for o numero procurado, retorna o indice do meio
        if (vetor[meio] == alvo)
        {
            return meio;
        }
        
        // se o valor presente no vetor no indice meio for maior que o valor procurado, quer dizer que o alvo esta a esquerda do meio, logo chama recursivamente a funcao alterando o valor do fim para meio-1
        if (vetor[meio] > alvo)
        {
            return buscaBinariaRecursivaAux(vetor, alvo, inicio, meio - 1);
        }
        // se o valor presente no vetor no indice meio for menor que o valor procurado, quer dizer que o alvo esta a direita do meio, logo chama recursivamente a funcao alterando o valor do inicio para meio+1
        else
        {
            return buscaBinariaRecursivaAux(vetor, alvo, meio + 1, fim);
        }
    } // retorna -1 pois ele ja varreu todo o vetor
    return -1;
}

// wrapper para busca binaria recursiva que reseta contador
int buscaBinariaRecursiva(int vetor[], int alvo, int inicio, int fim)
{
    contadorOperacoes = 0; // reseta o contador antes de iniciar
    return buscaBinariaRecursivaAux(vetor, alvo, inicio, fim);
}

// funcao para gerar numeros aleatorios ordenados
void geraVetorOrdenado(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = i + 1; // gera numeros de 1 a tamanho
    }
}

// funcao para copiar vetor (necessario para resetar apos inversao)
void copiaVetor(int origem[], int destino[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        destino[i] = origem[i];
    }
}

// funcao para calcular tempo em microssegundos
long calcularTempo(struct timeval inicio, struct timeval fim)
{
    long segundos = fim.tv_sec - inicio.tv_sec;
    long microssegundos = fim.tv_usec - inicio.tv_usec;
    if (microssegundos < 0)
    {
        segundos -= 1;
        microssegundos += 1000000;
    }
    return segundos * 1000000 + microssegundos; // retorna tempo total em microssegundos
}

// funcao para testar um algoritmo especifico
void testaAlgoritmo(FILE *arquivo, const char *nomeAlgoritmo, int tipoAlgoritmo, 
                   int vetor[], int vetorBackup[], int tamanho, int numeroTestes)
{
    struct timeval inicio, fim;
    long tempoTotal = 0;
    long long operacoesTotal = 0;
    
    printf("testando %s com tamanho %d...\n", nomeAlgoritmo, tamanho);
    
    // realiza os testes
    for (int teste = 0; teste < numeroTestes; teste++)
    {
        // escolhe um alvo aleatorio para cada teste
        int alvo;
        if (tipoAlgoritmo == 1) // inversao nao precisa de alvo
        {
            alvo = 0;
            copiaVetor(vetorBackup, vetor, tamanho); // reseta o vetor
        }
        else
        {
            // gera um numero aleatorio entre 1 e tamanho+10
            // isso inclui elementos que existem e alguns que nao existem
            alvo = 1 + rand() % (tamanho + 10);
        }
        
        gettimeofday(&inicio, NULL);
        
        switch (tipoAlgoritmo)
        {
            case 1: 
                inverteNumeros(vetor, tamanho);
                break;
            case 2: 
                buscaSequencial(vetor, tamanho, alvo);
                break;
            case 3:
                buscaBinariaIterativa(vetor, alvo, tamanho);
                break;
            case 4:
                buscaBinariaRecursiva(vetor, alvo, 0, tamanho - 1);
                break;
        }
        
        gettimeofday(&fim, NULL);
        
        tempoTotal += calcularTempo(inicio, fim);
        operacoesTotal += contadorOperacoes;
    }
    
    // calcula as medias
    double tempoMedio = (double)tempoTotal / numeroTestes;
    double operacoesMedio = (double)operacoesTotal / numeroTestes;
    
    fprintf(arquivo, "%s,%d,%.2f,%.2f\n", nomeAlgoritmo, tamanho, tempoMedio, operacoesMedio);
    
    printf("  tempo medio: %.2f microssegundos\n", tempoMedio);
    printf("  operacoes media: %.2f\n", operacoesMedio);
}

int main()
{
    int tamanhos[] = {10, 100, 1000, 5000};
    int numTamanhos = 4;
    int numeroTestes = 100; 
    
    FILE *arquivo = fopen("resultados_testes.csv", "w");
    if (arquivo == NULL)
    {
        printf("erro ao criar arquivo csv\n");
        return 1;
    }
    
    fprintf(arquivo, "algoritmo,tamanho_entrada,tempo_medio_us,operacoes_medio\n");
    
    printf("iniciando testes dos algoritmos...\n");
    printf("cada teste sera executado %d vezes para calcular a media\n\n", numeroTestes);
    
    // seed para numeros aleatorios
    srand(time(NULL));
    
    // testa cada tamanho
    for (int i = 0; i < numTamanhos; i++)
    {
        int tamanho = tamanhos[i];
        printf("=== testando com entrada de tamanho %d ===\n", tamanho);
        
        // aloca memoria para os vetores
        int *vetor = (int*)malloc(tamanho * sizeof(int));
        int *vetorBackup = (int*)malloc(tamanho * sizeof(int));
        
        if (vetor == NULL || vetorBackup == NULL)
        {
            printf("erro ao alocar memoria\n");
            return 1;
        }
        
        // gera vetor ordenado
        geraVetorOrdenado(vetor, tamanho);
        copiaVetor(vetor, vetorBackup, tamanho);
        
        // testa cada algoritmo
        testaAlgoritmo(arquivo, "inversao", 1, vetor, vetorBackup, tamanho, numeroTestes);
        
        // para os algoritmos de busca, sempre reseta o vetor para manter ordenacao
        copiaVetor(vetorBackup, vetor, tamanho);
        testaAlgoritmo(arquivo, "busca_sequencial", 2, vetor, vetorBackup, tamanho, numeroTestes);
        
        copiaVetor(vetorBackup, vetor, tamanho);
        testaAlgoritmo(arquivo, "busca_binaria_iterativa", 3, vetor, vetorBackup, tamanho, numeroTestes);
        
        copiaVetor(vetorBackup, vetor, tamanho);
        testaAlgoritmo(arquivo, "busca_binaria_recursiva", 4, vetor, vetorBackup, tamanho, numeroTestes);
        
        printf("\n");
        
        // libera memoria
        free(vetor);
        free(vetorBackup);
    }
    
    fclose(arquivo);
    
    printf("testes concluidos! resultados salvos em 'resultados_testes.csv'\n");
    printf("voce pode abrir o arquivo no excel ou qualquer editor de planilhas\n");
    
    return 0;
}