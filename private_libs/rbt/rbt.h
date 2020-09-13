/*
 * author: greyshell
 * description: red-black-tree
 */

#ifndef RBT_H__
#define RBT_H__

#include <lzma.h>
#include "stdbool.h"

typedef enum {
    RBT_COLOR_RED,
    RBT_COLOR_BLACK,
} rbt_color;

struct _rbt_node {
    rbt_color color;
    int value;
    struct _rbt_node *parent, *left, *right;
};

typedef struct _rbt_node rbt_node;

typedef struct {
    rbt_node *root;
    size_t sz;
} rbt;

bool initialize_rbt(rbt *);

bool insert_rbt(rbt *, int);

bool delete_rbt(rbt *, int);

bool display_rbt(rbt *);

#endif