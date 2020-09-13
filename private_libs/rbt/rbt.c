#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "../queue/queue02.h"

typedef struct {
    rbt_node *n;
    size_t level;
} _rbt_node_depth;

bool initialize_rbt(rbt *tree) {
    tree->root = NULL;
    tree->sz = 0;
}

bool insert_rbt(rbt *tree, int value) {
    // TODO
    return false;
}

bool delete_rbt(rbt *tree, int value) {
    // TODO
    return false;
}

static size_t _max_depth_node(rbt_node *node) {
    size_t l, r;

    if (node == NULL) {
        return 0;
    }

    l = _max_depth_node(node->left);
    r = _max_depth_node(node->right);
    return (l > r ? l : r) + 1;
}

static size_t _max_depth(rbt *tree) {
    return _max_depth_node(tree->root);
}

bool display_rbt(rbt *tree) {
    size_t depth = _max_depth(tree);
    char buf[1024]; // TODO: Fix buffer overflow on stack
    size_t last_level = 0;
    int offset = (1 << depth) - 1;
    queue q;
    _rbt_node_depth *node_depth, *temp;
    initialize_queue(&q);
    node_depth = malloc(sizeof(_rbt_node_depth));
    node_depth->n = tree->root;
    node_depth->level = last_level;
    enqueue(&q, node_depth);

    while (get_queue_size(&q) != 0) {
        peek_at_front(&q, (void **) &node_depth);
        if (last_level != node_depth->level) {
            printf("\n");
            last_level = node_depth->level;
            offset = (1 << (depth - last_level)) - 1;
        }

        if (node_depth->n) {
            sprintf(buf, " %*s%d%*s", offset, " ", node_depth->n->value, offset, " ");
        } else {
            sprintf(buf, " %*s", (offset << 1), " ");
        }
        printf(buf);

        if (node_depth->n) {
            temp = malloc(sizeof(_rbt_node_depth));
            temp->n = node_depth->n->left;
            temp->level = last_level + 1;
            enqueue(&q, temp);
            temp = malloc(sizeof(_rbt_node_depth));
            temp->n = node_depth->n->right;
            temp->level = last_level + 1;
            enqueue(&q, temp);
        }

        dequeue(&q, (void **) &node_depth);
    }
    printf("\n");
    // TODO: Fix memory leak in queue
    return true;
}