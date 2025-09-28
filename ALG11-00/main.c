#include <stdio.h>
#include "Queue.h"

int main () {
    Queue *fila1, *fila2;
    fila1 = create_queue();
    fila2 = create_queue();
    int opcao;

    while (scanf("%d", &opcao) == 1)
    {   
        if (opcao==0) break;
        else if (opcao == 1) {
            int x;
            if (scanf("%d", &x) != 1) break;
            enqueue(fila1, x);
        }
        else if (opcao == 2) {
            int y;
            if (scanf("%d", &y) != 1) break;
            enqueue(fila2, y);
        }
        else if (opcao == 3){
            int removido;
            if (dequeue(fila2, &removido)) {
                printf("%d\n", removido);
            } else if (dequeue(fila1, &removido)){
                printf("%d\n", removido);
            }
            if (dequeue(fila2, &removido)) {
                printf("%d\n", removido);
            } else if (dequeue(fila1, &removido)){
                printf("%d\n", removido);
            }
            if (dequeue(fila1, &removido)) {
                printf("%d\n", removido);
            } else if (dequeue(fila2, &removido)){
                printf("%d\n", removido);
            }
        }
    }
    
}