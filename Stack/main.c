#include <stdio.h>
#include "Stack.h"

int main()
{
    Stack *pilha = create_stack();
    int value, opcao;
    do
    {
        printf("Empilhar[1] / Desempilhar[2] / Sair[3] \n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (is_full(pilha))
                return 0; // pilha esta cheio nao da pra inserir mais
            scanf("%d", &value);
            push(pilha, value);
        }

        else if (opcao == 2)
        {
            if (is_empty(pilha))
                return 0; // pilha esta vazia nao da pra tirar nada
            pop(pilha, &value);
        }

    } while (opcao != 3);

    print_stack(pilha);
}