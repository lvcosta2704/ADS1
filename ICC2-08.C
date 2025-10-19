#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int v[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Se o filho da esquerda é maior que a raiz
    if (esquerda < n && v[esquerda] > v[maior])
        maior = esquerda;

    // Se o filho da direita é maior que o maior até agora
    if (direita < n && v[direita] > v[maior])
        maior = direita;

    // Se o maior não é a raiz
    if (maior != i) {
        trocar(&v[i], &v[maior]);
        
        heapify(v, n, maior);
    }
}

void ordenavetor(int v[], int n) {
    // fazendo a heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        // ordena jogando pro final
        trocar(&v[0], &v[i]);
        //chama heapify na árvore reduzida
        heapify(v, i, 0);
    }
}

int buscabinaria (int v[], int alvo, int n){
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio)/2;

        if (alvo == v[meio])
        {
            return 1;
        }
        else if (alvo < v[meio])
        {
            fim = meio - 1;
        }
        else // alvo > v[meio]
        {
            inicio = meio + 1;
        }
    }
    return 0;
}

int main() {
    int N, K;
    scanf("%d", &N);

    int vetor[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }
    ordenavetor(vetor, N);

    scanf("%d", &K);

    int procurados[K];

    for (int j = 0; j < K; j++)
    {
        scanf("%d", &procurados[j]);
    }

    for (int l = 0; l < K; l++)
    {
        printf("%d\n", buscabinaria(vetor, procurados[l], N));
    }
    
    return 0;
}

