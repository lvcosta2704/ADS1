#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AED2.h"

int main () {
    int n_op;
    char op[10];
    char num1_txt[100];
    char num2_txt[100];
    BigInt *a = NULL, *b = NULL, *resultado = NULL;

    scanf("%d", &n_op); // colhe as informacoes de quantas operacoes iram rodas

    for (int i = 0; i < n_op; i++)
    {
        scanf("%s %s %s ", op, num1_txt, num2_txt);
        
        a = inicializar();
        b = inicializar();

        definir(a, num1_txt);
        definir(b, num2_txt);

        if (strcmp(op, "soma") == 0)
        {
            
        }

        else if (strcmp(op, "maior") == 0) {

        }

        else if (strcmp(op, "menor") == 0) {

        }

        else if (strcmp(op, "igual") == 0) {
            // as funções maior e menor retornam 0 se forem iguais
            if (!maior(a, b) && !menor(a, b)) {
                printf("Resultado:: 1\n");
            } else {
                printf("Resultado:: 0\n");
            }
        }

        destruir(&a);
        destruir(&b);
        
    }
    


}
