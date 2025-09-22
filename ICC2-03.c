#include <stdio.h>
#include <stdlib.h>

long long trocas_globais;
long long comparacoes_globais;

void copiar_vetor(int *origem, int *destino, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        destino[i] = origem[i];
    }
}

void insertion_sort(int *vetor, int tamanho)
{
    trocas_globais = 0;
    comparacoes_globais = 0;
    int i, j, chave;

    for (i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        trocas_globais++;
        j = i - 1;

        while (j >= 0)
        {
            comparacoes_globais++;
            if (vetor[j] > chave)
            {
                vetor[j + 1] = vetor[j];
                trocas_globais++;
                j = j - 1;
            }
            else
            {
                break;
            }
        }
        vetor[j + 1] = chave;
        trocas_globais++;
    }
}

void merge_sort(int *vetor, int esquerda, int direita);

void merge(int *vetor, int esquerda, int meio, int direita)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        L[i] = vetor[esquerda + i];
        trocas_globais++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = vetor[meio + 1 + j];
        trocas_globais++;
    }

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2)
    {
        comparacoes_globais++;
        if (L[i] <= R[j])
        {
            vetor[k++] = L[i++];
            trocas_globais++;
        }
        else
        {
            vetor[k++] = R[j++];
            trocas_globais++;
        }
    }

    while (i < n1)
    {
        vetor[k++] = L[i++];
        trocas_globais++;
    }

    while (j < n2)
    {
        vetor[k++] = R[j++];
        trocas_globais++;
    }

    free(L);
    free(R);
}

void merge_sort_wrapper(int *vetor, int tamanho)
{
    trocas_globais = 0;
    comparacoes_globais = 0;
    if (tamanho > 1)
    {
        merge_sort(vetor, 0, tamanho - 1);
    }
}

void merge_sort(int *vetor, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}

int main()
{
    int Q; // Quantidade de vetores a serem lidos
    scanf("%d", &Q);

    if (Q <= 0)
    {
        return 0; // Se não houver vetores, termina.
    }

    int *tamanhos = (int *)malloc(Q * sizeof(int)); // == int tamanhos[Q]

    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &tamanhos[i]);
    }

    for (int i = 0; i < Q; i++)
    {
        int N = tamanhos[i]; // Pega o tamanho do vetor atual que foi lido previamente.

        int *vetor_original = (int *)malloc(N * sizeof(int));
        int *vetor_copia = (int *)malloc(N * sizeof(int));

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &vetor_original[j]);
        }

        copiar_vetor(vetor_original, vetor_copia, N);
        insertion_sort(vetor_copia, N);
        printf("I %d %lld %lld\n", N, trocas_globais, comparacoes_globais);

        copiar_vetor(vetor_original, vetor_copia, N);
        merge_sort_wrapper(vetor_copia, N);
        printf("M %d %lld %lld\n", N, trocas_globais, comparacoes_globais);

        free(vetor_original);
        free(vetor_copia);
    }

    free(tamanhos);

    return 0;
}