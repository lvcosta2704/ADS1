#define VAZIO -1
#define REMOVIDO -2
#include <stdio.h>
#include <stdlib.h>
int *tabela;
int m;

int funcao_hash (int chave, int m) {
	return chave % m;
}

void inserir (int chave, int m, int *tabela) {
	int h = funcao_hash(chave, m);
	int i = h;

	do {
		// verifica se a chave ja existe na tabela
		if (tabela[i] == chave) {
			return;
		}
		// encontrou um espaço vazio ou removido, insere
		if (tabela[i] == VAZIO || tabela[i] == REMOVIDO) {
			tabela[i] = chave;
			return;
		}

		i = (i+1) % m; // move para a proxima posicao de tentativa
	} while (i != h);
}

void remover (int chave, int m, int *tabela) {
	int h = funcao_hash(chave, m);
	int i = h;

	do {
		if (tabela[i] == chave) { // encontrou a chave a ser removida
			tabela[i] = REMOVIDO;
			return;
		}

		if (tabela[i] == VAZIO) {
			return;
		}

		i = (i+1) % m;


	} while (i != h);
}

void buscar (int chave, int m, int *tabela) {
	int h = funcao_hash(chave, m);
	int i = h;

	do {
		if (tabela[i] == chave) { // encontrou a chave buscada
			printf("%d ", i);
			return;
		}

		if (tabela[i] == VAZIO) {
			printf("-1 ");
			return;
		}

		i = (i+1) % m;

	} while (i != h);

	printf("-1 ");

}
int main () {
	int n, d, b, chave;

	if (scanf("%d", &m) != 1) return 1;
	tabela =(int *)malloc(m * sizeof(int)); // aloca a tabela com o tamanho m
	if (tabela == NULL) return -3; // checa se a tabela alocou

	for (int i = 0; i < m; i++) { // inicia a tabela
		tabela[i] = VAZIO;
	}
	// insercoes na tabela
	if (scanf("%d", &n) != 1) return 1;
	for (int i = 0; i < n; i++) {
		if (scanf("%d,", &chave) == 1) {
			inserir(chave, m, tabela);
		}
	}

	// remocoes agora
	if (scanf("%d", &d) != 1) return 1;
	for (int i = 0; i < d; i++) {
		if (scanf("%d", &chave) == 1) {
			remover(chave, m, tabela);
		}
	}

	// buscas agora na tabela
	
	if (scanf("%d", &b) != 1) return 1;
	for (int i = 0; i < b; i++) {
		if (scanf("%d", &chave) == 1) {
			buscar(chave, m, tabela);
		}
	}
	printf("\n");

	free(tabela);

	return 0;
}

