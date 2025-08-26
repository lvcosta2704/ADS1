#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim);
void print_subarray(int v[], int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void mergesort(int arr[], int l, int r){
    if (l >= r) return;

    printf("DIVISAO [%d,%d]\n", l, r);

    int m = l + (r - l)/2;
    // divide o array ate chegar em 1 elemento somente no array
    // depois manda para a funcao merge ordenar
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

void merge(int v[], int inicio, int meio, int fim){
    int n = fim - inicio +1; // tamanho do array de copia
    int tmp[n];
    int i = inicio, j = meio+1, k = 0;
    // enquanto o i e o j forem menores do que o fim dos arrays que forem divididos no meio ele continua a comparacao
    while((i<=meio)&&(j<=fim)) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++]; // dessa forma k++ incrementa de forma antes de atribuir e poe o menor numero da vez dentro do array de copia tmp
        } else {
            tmp[k++] = v[j++];
        }
    }
    // ambos whiles de baixo fazem com que se sobrar um unico elemento a ser comparado ele ja adiciona no array tmp
    while (i <= meio) {
        tmp[k++] = v[i++];
    }
    while (j<= fim) {
        tmp[k++] = v[j++];
    }
    // for de copia dos elementos do tmp para o array V
    for (int m = 0; m < n; m++) {
        v[inicio+m] = tmp[m];
    }
    // debug
    printf("INTERCALACAO [%d,%d]: ", inicio, fim);
    print_subarray(v, inicio, fim);
}

int main (){
    int h;
    scanf("%d", &h);
    int numeros[h]; 

    for (int i = 0; i < h; i++) {
        scanf("%d", &numeros[i]);
    }
    mergesort(numeros, 0, h-1);
}