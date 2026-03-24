#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Eduardo Malafronte Alves de Souza (nusp: 16862798)
// Humberto Henrique de Amorim (nusp: 16814612)
// Lucas Vinicius da Costa (nusp: 16885265)


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int h[MAX][MAX];
    int v[MAX][MAX];
    int dp[MAX][MAX];

    // inicia tudo com 0 e -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            h[i][j] = 0;
            v[i][j] = 0;
            dp[i][j] = -1;
        }
    }

    int total = n * (m - 1) + m * (n - 1);

    // le as arestas
    for (int k = 0; k < total; k++)
    {
        int u, x, amg;
        scanf("%d %d %d", &u, &x, &amg);

        int r = u / m;
        int c = u % m;

        if (x == u + 1)
            h[r][c] = amg;
        else
            v[r][c] = amg;
    }

    dp[0][0] = 0;

    // percorre a grade e atualiza os valores
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
                continue;

            // vai pra direita
            if (j + 1 < m)
            {
                int novo = dp[i][j] + h[i][j];
                if (novo > dp[i][j + 1])
                    dp[i][j + 1] = novo;
            }

            // vai pra baixo
            if (i + 1 < n)
            {
                int novo = dp[i][j] + v[i][j];
                if (novo > dp[i + 1][j])
                    dp[i + 1][j] = novo;
            }
        }
    }

    printf("%d\n", dp[n - 1][m - 1]);

    return 0;
}