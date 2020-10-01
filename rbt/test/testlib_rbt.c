/*
 * author: greyshell
 * description: tests heap
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#include "../../liquid_oxygen/rbt/rbt.h"


int main(void) {
    rbt t;
    bool return_type;
    initialize_rbt(&t);

    // TEMP
    t.root = malloc(sizeof(rbt_node));
    t.root->value = 10;
    t.root->left = malloc(sizeof(rbt_node));
    t.root->left->value = 5;
    t.root->right = malloc(sizeof(rbt_node));
    t.root->right->value = 15;
    t.root->left->left = malloc(sizeof(rbt_node));
    t.root->left->left->value = 3;
    t.root->left->right = malloc(sizeof(rbt_node));
    t.root->left->right->value = 7;
    t.root->right->left = malloc(sizeof(rbt_node));
    t.root->right->left->value = 12;
    t.root->right->right = malloc(sizeof(rbt_node));
    t.root->right->right->value = 17;
    t.sz = 7;

    display_rbt(&t);

    return 0;
}
