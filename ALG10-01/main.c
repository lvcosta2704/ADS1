#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h" // Inclui o cabeçalho da sua pilha

// --- Função para processar a expressão e a pilha ---
void processa_expressao(const char *linha, Stack *pilha)
{
    char buf[256];
    strncpy(buf, linha, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *tok = strtok(buf, " ");
    int value; // Declaração da variável value
    while (tok != NULL)
    {
        if (isdigit(tok[0]))
        {
            int valor = atoi(tok);
            push(pilha, valor);
        }
        else
        {
            // Se for um operador, precisamos de dois operandos da pilha
            pop(pilha, &value);
            int operando2 = value; // O primeiro a ser retirado é o segundo operando
            pop(pilha, &value);
            int operando1 = value; // O segundo a ser retirado é o primeiro operando
            int resultado;

            switch (tok[0])
            {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                // Verificação simples para evitar divisão por zero
                if (operando2 != 0)
                {
                    resultado = operando1 / operando2;
                }
                else
                {
                    printf("ERRO");
                    resultado = 0;
                    free_stack(&pilha); // Evita uso de variável não inicializada
                }
                break;
            default:
                printf("Erro: Operador desconhecido: %c\n", tok[0]);
                resultado = 0;
                free_stack(&pilha);
            }

            push(pilha, resultado);
        }

        tok = strtok(NULL, " ");
    }
}

// --- Função principal ---
int main()
{
    // Inicializa a pilha
    Stack *pilha = create_stack();
    char expressao[256];
    int value; // Declaração da variável value
    // Lê a linha de entrada, incluindo espaços
    if (fgets(expressao, sizeof(expressao), stdin) == NULL)
    {
        printf("Erro ao ler entrada.\n");
        free_stack(&pilha);
        return 1;
    }
    // Remove o '\n' que o fgets adiciona
    expressao[strcspn(expressao, "\n")] = '\0';

    processa_expressao(expressao, pilha);

    // No final, deve sobrar apenas um valor na pilha
    pop(pilha, &value);
    printf("%d\n", value);
    free_stack(&pilha);

    return 0;
}