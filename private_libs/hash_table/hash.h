/*
 * author: greyshell
 * description: dynamic array based implementation of stack
 * data / key -> void pointer
 * */

#ifndef STACK_DYN_ARR_H__
#define STACK_DYN_ARR_H__

#include "stdbool.h"
#include <stdint.h>
#include <lzma.h>

typedef size_t getCode(void *);

#define N 786431

struct kv_pair {
    void *key;
    void *value;
    struct kv_pair *next;
};

struct Hash {
    struct kv_pair *table[N];
    getCode *func_ptr;
};

bool hash_initialize(struct Hash *, getCode *);

bool hash_put(struct Hash *, void *, void *);

bool hash_get(struct Hash *, void *, void **);

//bool hash_delete(struct Hash *, void *);

//bool hash_delete_all(struct Hash *);

#endif // STACK_DYN_ARR_H__
