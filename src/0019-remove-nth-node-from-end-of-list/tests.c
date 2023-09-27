#include <criterion/criterion.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode lst_node_t;

lst_node_t *removeNthFromEnd(lst_node_t *head, int n);

void test_node_removal(int lsize, int n, int in[lsize + 1], int exp[lsize]) {
    lst_node_t *out;
    lst_node_t *lst = malloc((lsize + 1) * sizeof(lst_node_t));
    lst_node_t *copy = lst;

    if (lst == NULL)
        cr_skip("Memory Allocation Failure.");
    for (int i = 0; i <= lsize; i++) {
        copy->val = in[i];
        copy->next = (i == lsize) ? NULL : copy + sizeof(lst_node_t);
        copy = copy->next;
    }
    out = removeNthFromEnd(lst, n);
    for (int i = 0; i < lsize; i++) {
        if (out == NULL)
            cr_assert(false);
        cr_assert_eq(out->val, exp[i]);
        out = out->next;
    }
    if (out != NULL)
        cr_assert(false);
    free(lst);
}

Test(removeNthFromEnd, test_case_1)
{
    test_node_removal(
        4, 2,
        (int []){1, 2, 3, 4, 5},
        (int []){1, 2, 3, 5}
    );
}

Test(removeNthFromEnd, test_case_2)
{
    test_node_removal(1, 1, (int []){1}, NULL);
}


Test(removeNthFromEnd, test_case_3)
{
    test_node_removal(
        1, 1,
        (int []){1, 2},
        (int []){1, 2, 3, 5}
    );
}
