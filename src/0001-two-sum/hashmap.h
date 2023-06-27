#ifndef HASHMAP_H
    #define HASHMAP_H

    #include "single_linked_list.h"

typedef int hm_key_t;
typedef int hm_val_t;

typedef struct {
    hm_key_t key;
    hm_val_t val;
} hm_pair_t;

typedef struct {
    s_list_t *bucket;
    int bucket_size;
} hashmap_t;

hashmap_t *hashmap_create(int size);

bool hashmap_insert(hashmap_t *hm, hm_key_t key, hm_val_t value);
hm_val_t hashmap_get(hashmap_t *hm, hm_key_t key, hm_val_t sentinel);
hm_pair_t *hashmap_get_pair(hashmap_t *hm, hm_key_t key);

void hashmap_destroy(hashmap_t *hm);

#endif /* !HASHMAP_H */
