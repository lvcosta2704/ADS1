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

    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

void merge(int v[], int inicio, int meio, int fim){
    int n = fim - inicio +1;
    int tmp[n];
    int i = inicio, j = meio+1, k = 0;

    while((i<=meio)&&(j<=fim)) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= meio) {
        tmp[k++] = v[i++];
    }
    while (j<= fim) {
        tmp[k++] = v[j++];
    }
    for (int m = 0; m < n; m++) {
        v[inicio+m] = tmp[m];
    }

    printf("INTERCALACAO [%d,%d]: ", inicio, fim);
    print_subarray(v, inicio, fim);
}

int main (){
    int h;
    scanf("%d", &h);
    int numeros[h]; // Para bater com seu exemplo de 7 elementos

    for (int i = 0; i < h; i++) {
        scanf("%d", &numeros[i]);
    }
    mergesort(numeros, 0, h-1);
}