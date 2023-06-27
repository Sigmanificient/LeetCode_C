#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashmap.h"

static
int hashmap_get_index(hashmap_t *hm, hm_key_t key)
{
    if (key < 0)
        key = -key;
    if (key >= hm->bucket_size)
        key %= hm->bucket_size;
    return key;
}

hashmap_t *hashmap_create(int size)
{
    hashmap_t *hm = malloc(sizeof(*hm));

    if (hm == NULL)
        return NULL;
    hm->bucket_size = size;
    hm->bucket = calloc(size, sizeof (s_list_t));
    if (hm->bucket == NULL) {
        free(hm);
        return NULL;
    }
    return hm;
}

hm_pair_t *hashmap_get_pair(hashmap_t *hm, hm_key_t key)
{
    int hash_val = hashmap_get_index(hm, key);
    s_list_t *lst = &hm->bucket[hash_val];
    hm_pair_t *pair;

    if (lst == NULL || lst->head == NULL || !lst->size)
        return NULL;
    SLIST_FOREACH(lst, node) {
        pair = node->value;
        if (pair == NULL)
            return NULL;
        if (key == pair->key)
            return pair;
    }
    return NULL;
}

hm_val_t hashmap_get(hashmap_t *hm, hm_key_t key, hm_val_t sentinel)
{
    hm_pair_t *pair = hashmap_get_pair(hm, key);

    if (pair == NULL)
        return sentinel;
    return pair->val;
}

bool hashmap_insert(hashmap_t *hm, hm_key_t key, hm_val_t value)
{
    int hash_val;
    hm_pair_t *pair = hashmap_get_pair(hm, key);

    if (pair != NULL) {
        pair->val = value;
        return true;
    }
    pair = malloc(sizeof (*pair));
    if (pair == NULL)
        return false;
    pair->key = key;
    pair->val = value;
    hash_val = hashmap_get_index(hm, key);
    if (
        hash_val >= hm->bucket_size
        || !s_list_append(&hm->bucket[hash_val], pair)
    ) {
        free(pair);
        return false;
    }
    return true;
}

void hashmap_destroy(hashmap_t *hm)
{
    for (int i = 0; i < hm->bucket_size; i++)
        SLIST_FOREACH(hm->bucket + i, node)
            free(node->value);
    for (int i = 0; i < hm->bucket_size; i++)
        s_list_clear(hm->bucket + i);
    free(hm->bucket);
    free(hm);
}
