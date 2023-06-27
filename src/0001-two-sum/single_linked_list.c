#include <stdbool.h>
#include <stdlib.h>

#include "single_linked_list.h"

bool s_list_append(s_list_t *lst, void *data)
{
    s_list_node_t *node = malloc(sizeof (*node));

    if (node == NULL)
        return false;
    node->value = data;
    node->next = NULL;
    if (lst->head == NULL)
        lst->head = node;
    if (lst->tail != NULL)
        lst->tail->next = node;
    lst->tail = node;
    lst->size++;
    return true;
}

void s_list_clear(s_list_t *lst)
{
    s_list_node_t *node = lst->head;
    s_list_node_t *next;

    lst->size = 0;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
}
