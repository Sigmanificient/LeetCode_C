struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stddef.h>

typedef struct ListNode list_node_t;

list_node_t *swapPairs(list_node_t *head)
{
    int tmp;
    list_node_t *ptr = head;

    while (head != NULL && head->next != NULL) {
        tmp = head->val;
        head->val = head->next->val;
        head->next->val = tmp;
        head = head->next->next;
    }
    return ptr;
}
