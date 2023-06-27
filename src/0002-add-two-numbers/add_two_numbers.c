#include <stdlib.h>
#include <stdbool.h>
#include "list_node.h"

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

list_node_t *destroy_list_node(list_node_t *node)
{
    list_node_t *next;

    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
    return NULL;
}

list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2)
{
    bool carry = false;
    list_node_t *node = malloc(sizeof (*node));
    list_node_t *ptr = node;

    while (node) {
        node->val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = (node->val > 9);
        if (carry)
            node->val -= 10;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        if (!l1 && !l2 && !carry)
            break;
        node->next = malloc(sizeof(*node));
        node = node->next;
    }
    if (node == NULL)
        return destroy_list_node(ptr);
    node->next = NULL;
    return ptr;
}

int *addTwoNumbers() USED ALIAS("add_two_numbers");
