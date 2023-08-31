#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node_t;

list_node_t *mergeTwoLists(list_node_t *list1, list_node_t *list2)
{
    list_node_t tmp = { 0 };
    list_node_t *node = &tmp;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    if (list1 != NULL)
        node->next = list1;
    if (list2 != NULL)
        node->next = list2;
    return tmp.next;
}
