#include "hash.h"
#include <string.h>
#include <stdlib.h>

static size_t get_hash_code(struct Hash *hash, void *key) {
    size_t code = hash->func_ptr(key);
    return code % N;
}

bool hash_initialize(struct Hash *hash, getCode *func_ptr) {
    hash->func_ptr = func_ptr;
    memset(&hash->table, 0, sizeof(hash->table));
}

bool hash_put(struct Hash *hash, void *key, void *value) {
    struct kv_pair *element;
    size_t idx = get_hash_code(hash, key);

    element = malloc(sizeof(struct kv_pair));
    element->key = key;
    element->value = value;
    element->next = NULL;

    if (hash->table[idx] == NULL) {
        hash->table[idx] = element;
        return true;
    }

    element->next = hash->table[idx];
    hash->table[idx] = element;
    return true;
    // TODO : Handle repetitions
}

bool hash_get(struct Hash *hash, void *key, void **value) {
    struct kv_pair *iter;
    size_t idx = get_hash_code(hash, key);

    iter = hash->table[idx];
    while (iter != NULL) {
        if (hash->func_ptr(iter->key) == hash->func_ptr(key)) {
            *value = iter->value;
            return true;
        }
    }

    return false;
}

//bool hash_delete(struct Hash *, void *);

//bool hash_delete_all(struct Hash *);