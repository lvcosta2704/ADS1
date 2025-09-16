#include <stdio.h>
#include "LSE.h"

int main () {
    LSE lista;
    lse_inicializa(&lista);

    int opcao;
    while (scanf("%d", &opcao) == 1)
    {
        if (opcao == 1) {
            int x;
            if (scanf("%d", &x) != 1) return 1;
            printf("%d\n", lse_insere_final(&lista, x));
        }
        else if (opcao == 2) {
            int p, x;
            if (scanf("%d %d", &p, &x) != 2) return 1;
            printf("%d\n", lse_insere_pos(&lista, p, x));
        }
        else if (opcao == 3) {
            int p, removido;
            if (scanf("%d", &p) != 1) return 1;
            if (lse_remove_pos(&lista, p, &removido))
                printf("%d\n", removido);
            else
                printf("ERRO\n");
        }
        else if (opcao == 4) {
            int p, elem;
            if (scanf("%d", &p) != 1) return 1;
            if (lse_consulta_pos(&lista, p, &elem))
                printf("%d\n", elem);
            else
                printf("ERRO\n");
        }
        else if (opcao == 5) {
            int x, pos;
            if (scanf("%d", &x) != 1) return 1;
            if (lse_busca(&lista, x, &pos))
                printf("%d\n", pos);
            else
                printf("-1\n");
        }
        else if (opcao == 6) {
            printf("%d\n", lse_tamanho(&lista));
        }
        else if (opcao == 7) {
            lse_imprime(&lista);
        }
        else if (opcao == 8) {
            lse_limpa(&lista);
        }
        else if (opcao == 9) {
            break;
        }
    }
    return 0;
}