#include <stdio.h>
#include "Stack.h"

int main()
{
	int decimal;
	Stack *pilhaBinaria = create_stack();

	if (scanf("%d", &decimal) != 1)
		return 1;
	if (decimal == 0)
	{
		printf("0\n");
		free_stack(&pilhaBinaria);
		return 0;
	}

	while (decimal > 0)
	{
		int resto = decimal % 2;
		push(pilhaBinaria, resto);
		decimal = decimal / 2;
	}

	int value;
	while (!is_empty(pilhaBinaria))
	{
		pop(pilhaBinaria, &value);
		printf("%d", value);
	}
	printf("\n");
	free_stack(&pilhaBinaria);
	return 0;
}
