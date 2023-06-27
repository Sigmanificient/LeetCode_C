#include <stdlib.h>
#include <criterion/criterion.h>
#include "list_node.h"

list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2);

typedef struct {
    int *a;
    int *b;
    int a_size;
    int b_size;
    int *expected;
    int exp_size;
} test_data_t;

void test_add_two_numbers(test_data_t *td)
{
    size_t list_count = (td->a_size + td->b_size);
    list_node_t *l2 = malloc(list_count * sizeof (list_node_t));
    list_node_t *node = NULL;
    list_node_t *l1;

    if (l2 == NULL)
        cr_skip("Allocation Failure.");
    for (int i = 0; i < td->b_size; i++) {
        node = l2 + i * sizeof(list_node_t);
        node->next = node + sizeof (list_node_t);
        node->val = td->b[i];
    }
    node->next = NULL;
    node += sizeof (list_node_t);
    l1 = node;
    for (int i = 0; i < td->a_size; i++) {
        node = l1 + i * sizeof(list_node_t);
        node->next = node + sizeof (list_node_t);
        node->val = td->a[i];
    }
    node = add_two_numbers(l1, l2);
    free(l2);
    if (node == NULL)
        cr_skip("Allocation Failure.");
    for (int i = 0; i < td->exp_size; i++) {
        cr_assert_not_null(node);
        cr_assert_eq(node->val, td->expected[i]);
        l2 = node->next;
        free(node);
        node = l2;
    }
    free(node);
}

Test(add_two_numbers, test_case_1)
{
    test_add_two_numbers(&(test_data_t){
        .a = (int []){2, 4, 3},
        .a_size = 3,
        .b = (int []){5, 6, 4},
        .b_size = 3,
        .expected = (int []){7, 0, 8},
        .exp_size = 3
    });
}

Test(add_two_numbers, test_case_2)
{
    test_add_two_numbers(&(test_data_t){
        .a = (int []){0},
        .a_size = 1,
        .b = (int []){0},
        .b_size = 1,
        .expected = (int []){0},
        .exp_size = 1,
    });
}

Test(add_two_numbers, test_case_3)
{
    test_add_two_numbers(&(test_data_t){
        .a = (int []){9, 9, 9, 9, 9, 9, 9},
        .a_size = 7,
        .b = (int []){9, 9, 9, 9},
        .b_size = 4,
        .expected = (int []){8, 9, 9, 9, 0, 0, 0, 1},
        .exp_size = 8,
    });
}
