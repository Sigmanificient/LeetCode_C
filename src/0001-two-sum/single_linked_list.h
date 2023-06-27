#ifndef SINGLE_LINKED_LIST_H
    #define SINGLE_LINKED_LIST_H

    #define SLIST_FOREACH(lst, node)            \
        for (s_list_node_t *node = (lst)->head; \
            node != NULL;                       \
            node = node->next)

typedef struct s_list_node_s s_list_node_t;
typedef struct s_list_s s_list_t;

struct s_list_node_s {
    s_list_node_t *next;
    void *value;
};

struct s_list_s {
    s_list_node_t *head;
    s_list_node_t *tail;
    int size;
};

bool s_list_append(s_list_t *lst, void *data);

void s_list_clear(s_list_t *lst);

#endif /* !SINGLE_LINKED_LIST_H */
