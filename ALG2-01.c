#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main () {
   int opcao;
   int *array = NULL;
   int size = 0;
   int number;
   
   
   do {
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1: 
            scanf("%d", &number);
            array = realloc(array, (size+1)*sizeof(int));
            array[size] = number;
            size++;
            break;
        case 2:
            size--;
            array = realloc(array, size*sizeof(int));
            break;
        case 3:
            if (size == 0) {
                break;
            }
            else {
            for (int i = 0; i < size; i++) {
                printf("%d ", array[i]);
            }    
            }
            printf("\n");
            break;
        case 4:
        int soma=0;
            for(int i = 0; i < size; i++) {
                soma += array[i];
            }
            float media = (float)soma/size;
            printf("Soma = %d, Média = %.2f\n", soma, media);
            break;
        case 5:
            qsort(array, size, sizeof(int), comparar);
            break;
        case 6:
            free(array);
            return 0;
        default: 
            break;
    }
    
   } while (opcao != 6);
   
}