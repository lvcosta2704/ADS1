/*
    ---------- TRABALHO 2 DE ALGORITMOS E ESTRUTURA DE DADOS -------------
    INTEGRANTES: LUCAS VINICIUS DA COSTA (16885265), HUMBERTO HENRIQUE DE AMORIM (16814612), EDUARDO MALAFRONTE ALVES DE SOUZA (16862798)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AED2.h"

int main(void)
{
    int n_op;
    char op[16];
    // buffers grandes para aceitar números longos
    char num1_txt[10010];
    char num2_txt[10010];
    BigInt *a = NULL, *b = NULL, *resultado = NULL;

    if (scanf("%d", &n_op) != 1)
        return 0; // quantidade de operacoes

    for (int i = 0; i < n_op; i++)
    {
        if (scanf("%15s %10009s %10009s", op, num1_txt, num2_txt) != 3)
        // sintaxe desse scanf é para limitar o tamanho da entrada que cada variavel vai receber
            break;

        a = inicializar();
        b = inicializar();
        resultado = NULL;

        if (!a || !b) // erro de alocacao em algum dos numeros a e b
        {
            destruir(&a);
            destruir(&b);
            return -1;
        }

        if (definir(a, num1_txt) != 1 || definir(b, num2_txt) != 1) // se a definicao de algum dos numeros der errado esta funcao destroi os dois numeros e retorna fracasso
        {
            destruir(&a);
            destruir(&b);
            return 0;
        }
        // a partir daqui assume-se que todas as definicoes e alocações deram certo e podem seguir para a atribuição em funcoes e comparações
        if (strcmp(op, "soma") == 0)
        {
            resultado = soma(a, b);
            if (resultado)
            {
                printf("Resultado :: ");
                imprimir(resultado);
                printf("\n");
                destruir(&resultado);
                resultado = NULL;
            }
        }
        else if (strcmp(op, "maior") == 0)
        {
            int r = maior(a, b);
            if (r == 1)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        }
        else if (strcmp(op, "menor") == 0)
        {
            int r = menor(a, b);
            if (r == 1)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        }
        else if (strcmp(op, "igual") == 0)
        {
            // igual se não for maior e não for menor
            if (maior(a, b) == 0 && menor(a, b) == 0)
                printf("Resultado :: True\n");
            else
                printf("Resultado :: False\n");
        }
        // trata de destriur os dois numeros e apontar os ponteiros para NULL como boa prática
        destruir(&a);
        destruir(&b);
        a = b = resultado = NULL;
    }

    return 0;
}
