#include <stdio.h>
#include "Ponto.h"

int main() {
    float x1, y1, x2, y2;
    int opcao;
    Ponto *p1, *p2;

    // leitura dos pontos
    if (scanf("%f %f", &x1, &y1) != 2) return 1;
    if (scanf("%f %f", &x2, &y2) != 2) return 1;
    // criacao dos pontos
    p1 = criaPonto(x1, y1);
    p2 = criaPonto(x2, y2);

    while (1) {
        if (scanf("%d", &opcao) != 1) break;
        if (opcao == 9) break;

        switch (opcao) {
            case 1:
                imprimePonto(p1);
                printf("\n");
                break;
            case 2:
                imprimePonto(p2);
                printf("\n");
                break;
            case 3:
                printf("%.3f\n", distancia(p1, p2));
                break;
            case 4:
                printf("%.3f\n", distanciaOrigem(p1));
                break;
            case 5:
                printf("%.3f\n", distanciaOrigem(p2));
                break;
            case 6: {
                float newx, newy;
                if (scanf("%f %f", &newx, &newy) != 2) break;
                atribuiPonto(p1, newx, newy);
                break;
            }
            case 7: {
                float newx, newy;
                if (scanf("%f %f", &newx, &newy) != 2) break;
                atribuiPonto(p2, newx, newy);
                break;
            }
            case 8:
                printf("%d\n", pontosIguais(p1, p2));
                break;
            default:
                break;
        }
    }
    liberaPonto(p1);
    liberaPonto(p2);
    return 0;
}