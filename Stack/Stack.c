
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define MAX 100
struct stack
{
    int dados[MAX];
    int qtd;
};

Stack *create_stack(void)
{
    Stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->qtd = 0;
    return s;
}

int is_empty(const Stack *s)
{
    if (!s)
        return -1;
    return s->qtd == 0 ? 1 : 0;
}

int is_full(const Stack *s)
{
    if (!s)
        return -1;
    return s->qtd == MAX ? 1 : 0;
}

int push(Stack *s, int value)
{
    if (!s)
        return -1;
    if (is_full(s))
        return 0;
    s->dados[s->qtd] = value;
    s->qtd++;
    return 1;
}

int pop(Stack *s, int *value)
{
    if (!s)
        return -1;
    if (is_empty(s))
        return 0;
    if (value)
        *value = s->dados[s->qtd - 1];
    s->qtd--;
    return 1;
}

int peek(const Stack *s, int *value)
{
    if (!s || !value)
        return -1;
    if (is_empty(s))
        return 0;
    *value = s->dados[s->qtd - 1];
    return 1;
}

void print_stack(const Stack *s) {
    printf("[");
    for (int i = 0; i < s->qtd; i++) {
        printf("%d", s->dados[i]);
        if (i < s->qtd - 1) printf(", ");
    }
    printf("]\n");
}

void free_stack(Stack **s)
{
    if (s && *s)
    {
        free(*s);
        *s = NULL;
    }
}