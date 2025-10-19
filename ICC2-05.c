#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long shellcount(int v[], int n)
{
    long long contador = 0;
    int gap = 1;
    while (gap <= n)
    {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int x = v[i];
            contador++; // cópia: x = v[i]
            int j = i - gap;
            while (j >= 0 && v[j] > x)
            {
                contador++; // comparação: v[j] > x
                v[j + gap] = v[j];
                contador++; // cópia: v[j + gap] = v[j]
                j -= gap;
            }
            if (j >= 0)
            {
                contador++; // comparação que falhou: v[j] > x
            }
            v[j + gap] = x;
            contador++; // cópia: v[j + gap] = x
        }
        gap /= 2;
    }
    return contador;
}

long long quickcount_rec(int v[], int f, int l, long long *contador)
{
    if (f >= l)
        return *contador;
    int m = (l + f) / 2;
    int pivot = v[m];
    (*contador)++; // cópia: pivot = v[m]
    int i = f;
    int j = l;
    while (1)
    {
        while (v[i] < pivot)
        {
            (*contador)++; // comparação: v[i] < pivot
            i++;
        }
        (*contador)++; // comparação que falhou: v[i] < pivot
        while (v[j] > pivot)
        {
            (*contador)++; // comparação: v[j] > pivot
            j--;
        }
        (*contador)++; // comparação que falhou: v[j] > pivot
        if (i >= j)
        {
            break;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        (*contador) += 3; // 3 cópias na troca
        i++;
        j--;
    }
    quickcount_rec(v, f, j, contador);
    quickcount_rec(v, j + 1, l, contador);
    return *contador;
}

long long quickcount(int v[], int f, int l) // função reseta o contador
{
    long long contador = 0;
    quickcount_rec(v, f, l, &contador);
    return contador;
}

int main()
{
    int N;
    scanf("%d", &N);
    int V[100], v1[100], v2[100];
    for (int i = 0; i < N; i++)
        scanf("%d", &V[i]);

    for (int k = 1; k <= N; k++)
    {
        memcpy(v1, V, k * sizeof(int));
        memcpy(v2, V, k * sizeof(int));
        long long ops_shell = shellcount(v1, k);
        long long ops_quick = quickcount(v2, 0, k - 1);

        if (ops_shell < ops_quick)
            printf("S ");
        else if (ops_quick < ops_shell)
            printf("Q ");
        else
            printf("- ");
    }
    printf("\n");
    return 0;
}