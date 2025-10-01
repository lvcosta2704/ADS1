#include <stdio.h>
#include "LinkedList.h"

int main()
{
    int opcao;
    LinkedList *l1, *l2;
    l1 = create_linked_list();
    l2 = create_linked_list();

    while (scanf("%d", &opcao) == 1)
    {
        if (opcao == 9)
            break;
        else if (opcao == 1)
        {
            int x, p;
            if (scanf("%d %d", &x, &p) != 2)
                break;
            insert_node(l1, p, x);
        }
        else if (opcao == 2)
        {
            int x, p;
            if (scanf("%d %d", &x, &p) != 2)
                break;
            insert_node(l2, p, x);
        }
        else if (opcao == 3)
        {
            int p, value;
            if (scanf("%d", &p) != 1)
                break;
            remove_node(l1, p, &value);
        }
        else if (opcao == 4)
        {
            int p, value;
            if (scanf("%d", &p) != 1)
                break;
            remove_node(l2, p, &value);
        }
        else if (opcao == 5)
        {
            int tam2 = size_list(l2);
            for (int i = 0; i < tam2; i++)
            {
                int value;
                get_node(l2, i, &value);
                insert_node(l1, size_list(l1), value);
            }
        }
        else if (opcao == 6)
        {
            int tam1 = size_list(l1);
            for (int i = 0; i < tam1; i++)
            {
                int value;
                get_node(l1, i, &value);
                insert_node(l2, size_list(l2), value);
            }
        }
        else if (opcao == 7)
        {
            int len1 = size_list(l1);
            for (int i = 0; i < len1; i++)
            {
                int value;
                get_node(l1, i, &value);
                if (i == 0)
                {
                    printf("[");
                }
                printf("%d", value);
                if (i < len1 - 1)
                {
                    printf(" ");
                }
            }
            printf("]\n");
        }
        else if (opcao == 8)
        {
            int len2 = size_list(l2);
            for (int i = 0; i < len2; i++)
            {
                int value;
                get_node(l2, i, &value);
                if (i == 0)
                {
                    printf("[");
                }
                printf("%d", value);
                if (i < len2 - 1)
                {
                    printf(" ");
                }
            }
            printf("]\n");
        }
    }
    free_linked_list(&l1);
    free_linked_list(&l2);
}