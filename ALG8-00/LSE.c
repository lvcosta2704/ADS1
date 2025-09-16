#include "LSE.h"
#include <stdio.h>

void lse_inicializa(LSE *l) {
  l->qtd = 0;
}

int lse_vazia(LSE *l) {
  return l->qtd == 0;
}

int lse_cheia(LSE *l) {
  return l->qtd == LSE_MAX;
}

int lse_tamanho(LSE *l) {
  return l->qtd;
}

void lse_limpa(LSE *l) {
  l->qtd = 0;
}

int lse_insere_final(LSE *l, LSE_Tipo elem) {
  if (lse_cheia(l)) return 0;
  l->dados[l->qtd]= elem;
  l->qtd++;
  return 1;
}

int lse_insere_pos(LSE *l, int pos, LSE_Tipo elem) {
  if (lse_cheia(l) || pos < 0 || pos > l->qtd) return 0;
  for (int i = l->qtd; i > pos ; i--)
  {
    l->dados[i] = l->dados[i-1]; // desloca todo mundo a direita da pos para uma casa a mais para a direita 
  }
  l->dados[pos] = elem; //coloca o elemento na pos desejada
  l->qtd++;
  return 1;
}

int lse_remove_pos(LSE *l, int pos, LSE_Tipo *removido) {
  if (lse_cheia(l) || pos < 0 || pos >= l->qtd) return 0;
  *removido = l->dados[pos];
  for (int i = pos; i < l->qtd-1; i++)
  {
    l->dados[i] = l->dados[i+1];
  }
  l->qtd--;
  return 1;
}

int lse_consulta_pos(LSE *l, int pos, LSE_Tipo *elem) {
  if (pos < 0 || pos >= l->qtd) return 0;
  *elem = l->dados[pos];
  return 1;
}

int lse_busca(LSE *l, LSE_Tipo elem, int *pos) {
  for (int i = 0; i < l->qtd; i++)
  {
    if (l->dados[i] == elem)
    {
      *pos = i;
      return 1; // se encontrar o numero desejado atribui a variavel pos o index dele
    }
  }
  *pos = -1; // se nao encontrar no loop atribui -1, para saber que nao foi encontrado
  return 0;
}

void lse_imprime(LSE *l) {
  printf("[");
  for (int i = 0; i < l->qtd; i++)
  {
    if (i > 0) printf(", ");
    printf("%d", l->dados[i]);
  }
  printf("]\n");
}




