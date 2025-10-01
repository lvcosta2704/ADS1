#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
//definicao das estruturas do TAD
typedef struct node
{
    int data;
    struct node *next;
}Node;

struct linked_list
{
    Node *head;
    int size;
};

LinkedList *create_linked_list(void) {
    LinkedList *l = malloc(sizeof(LinkedList));
    // aloca memoria para a lista
    if (!l) {
        return NULL;
    }
    // se a lista estiver alocada corretamente preenche os campos e retorna 1 de sucesso
    l->head = NULL;
    l->size = 0;
    return l;
}

int insert_node(LinkedList *list, int pos, int value) {
    if (!list) {
        return -1; // lista nao alocada
    }

    if ((pos < 0) || (pos > list->size)) {
        // posicoes invalidas, maior que o tamanho da lista e menor que 0
        return 0;
    }

    // se tudo estiver correto, cria um novo NÓ
    Node *novo = malloc(sizeof(Node));
    if (!novo) {
        return -1; 
        //erro ao alocar
    }
    // se estiver tudo certo preenche os campos do novo Nó
    novo->data = value;
    novo->next = NULL;

    if (pos == 0){
        // se a posicao for 0 entao basta atribuir o endereco que o head aponta para o next do novo
        // e atribuir o endereço do novo node ao head
        novo->next = list->head;
        list->head = novo;
    } else {
        Node *tmp = list->head;
        for (int i = 0; i < pos-1; i++){
            tmp = tmp->next;
        }
        // atribui ao next do novo o endereço do node da frente dele
        novo->next = tmp->next;
        // atribui ao node de pos-1 o endereço no novo node ao seu campo next
        tmp->next = novo;
    }
    list->size++;
    return 1;
}

int remove_node(LinkedList *list, int pos, int *value) {
    if (!list) {
        return -1; // lista nao alocada
    }

    if ((pos < 0) || (pos >= list->size)) {
        // posicoes invalidas, maior ou igual que o tamanho da lista e menor que 0
        return 0;
    }

    Node *rem;
    if (pos == 0) {
        rem = list->head;
        list->head = rem->next;
    } else {
        Node *tmp = list->head;
        for (int i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }
        rem = tmp->next;
        tmp->next = rem->next;
    }
    if (value) {
        *value = rem->data;
    }
    free(rem);
    list->size--;
    return 1;
}

int get_node(const LinkedList *list, int pos, int *value){
    if (!list) {
        return -1; // lista nao alocada
    }

    if ((pos < 0) || (pos >= list->size)) {
        // posicoes invalidas, maior ou igual que o tamanho da lista e menor que 0
        return 0;
    }

    Node *rem;
    if (pos == 0) {
        //salva o node que o head aponta no ponteiro rem
        rem = list->head;
    } else {
        Node *tmp = list->head;
        // percorre com o temp ate chegar no node exatamente anterior ao desejado
		for (int i = 0; i < pos-1; i++) {
			tmp = tmp->next;
		}
        // salva o node no ponteiro rem
        rem = tmp->next;
    }
    // caso o usuario queira o valor é só acessar o endereço *value;
    if (value) {
		*value = rem->data;
	}
    return 1;
}

int is_empty_list(const LinkedList *list){
    if (!list) {
        return -1; // lista nao alocada
    }
    if (list->head == NULL) {
        return 1;
        //lista esta vazia pois o primeiro elemento nao existe no head
    }
    return 0; // lista nao esta vazia
}

int size_list(const LinkedList *list){
    if (!list) {
        return -1; // lista nao alocada
    }
    return list->size;
}

void free_linked_list(LinkedList **list) {
    if (!list || !(*list)) {
        return; // lista nao esta nem inicializada
    }
    Node *tmp = (*list)->head;
	while (tmp != NULL) {
		Node *rem = tmp; // salva o endereço do node tmp em um REM
		tmp = tmp->next; // atualiza o tmp para o proximo da lista
		free(rem); // libera o rem da memoria
	}
    free(*list);
	*list = NULL;
}