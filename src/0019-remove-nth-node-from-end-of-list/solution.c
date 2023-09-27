#include <stddef.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode lst_node_t;

lst_node_t *removeNthFromEnd(lst_node_t *head, int n)
{
    int target = 0;
    int ls_size = 0;
    struct ListNode *copy = head;

    while (copy != NULL) {
        copy = copy->next;
        ls_size++;
    }
    if (n > ls_size)
        return NULL;
    target = ls_size - n - 1;
    if (target < 0)
        return head->next;
    copy = head;
    for (int i = 0; i < target; i++)
        copy = copy->next;
    if (copy->next == NULL)
        return head;
    copy->next = copy->next->next;
    return head;
}
