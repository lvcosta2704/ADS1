#include "LSD.h"
#include <stdio.h>

int main () {
	LSD l;
	l = *lsd_cria();
	int opcao;

	while (1) {
		if (scanf("%d", &opcao) != 1) break;
		if (opcao == 9 ) break;
		switch (opcao) {
			case 1:{
				int x;
				if (scanf("%d", &x) != 1) break;
				printf("%d\n", lsd_insere_final(&l, x));
				break;
				   }
			case 2: {
				int x, p;
				if (scanf("%d %d", &p, &x) != 2)break;
				printf("%d\n", lsd_insere_pos(&l, p, x));
				break;
					}
			case 3:{ 
				int p, removido;
				if (scanf("%d", &p) != 1 ) break;
				if (lsd_remove_pos(&l, p, &removido)){
					printf("%d\n", removido);
				} else {
					printf("ERRO\n");
				}
				break;
				   }
			case 4: {
				int p, elem;
				if (scanf("%d", &p) != 1) break;
				if (lsd_consulta_pos(&l, p, &elem) == 1){
					printf("%d\n", elem);
				} else {
					printf("ERRO\n");
				}
				break;
					}
			case 5: {
				int p, x;
				if (scanf("%d", &x) != 1) break;
				if (lsd_busca(&l, x, &p)){
					printf("%d\n", p);
				} else {
					printf("-1\n");
				}
					
				break;
					}
			case 6:{
				printf("%d\n", lsd_tamanho(&l));
				break;
				   }
			case 7: {
				lsd_imprime(&l);
				break;
					}
			case 8: {
				lsd_limpa(&l);
				break;}
		}
	}
}
