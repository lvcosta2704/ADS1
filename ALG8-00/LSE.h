#ifndef LSE_H
#define LSE_H
#define LSE_MAX 100 // capacidade máxima da lista
typedef int LSE_Tipo; // tipo dos elementos
// Estrutura da LSE
typedef struct {
LSE_Tipo dados[LSE_MAX];
int qtd; // quantidade atual de elementos
} LSE;
/* Protótipos */
// inicialização e estado
void lse_inicializa(LSE *l);
int lse_vazia(LSE *l);
int lse_cheia(LSE *l);
int lse_tamanho(LSE *l);
void lse_limpa(LSE *l);
// operações básicas
int lse_insere_final(LSE *l, LSE_Tipo elem);
int lse_insere_pos(LSE *l, int pos, LSE_Tipo elem);
int lse_remove_pos(LSE *l, int pos, LSE_Tipo *removido);
int lse_consulta_pos(LSE *l, int pos, LSE_Tipo *elem);
int lse_busca(LSE *l, LSE_Tipo elem, int *pos);
// saída
void lse_imprime(LSE *l);
#endif // LSE_H
