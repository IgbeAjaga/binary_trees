#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *right_child;

    if (tree == NULL || tree->right == NULL)
        return (tree);

    right_child = tree->right;
    tree->right = right_child->left;

    if (right_child->left != NULL)
        right_child->left->parent = tree;

    right_child->parent = tree->parent;
    tree->parent = right_child;
    right_child->left = tree;

    return (right_child);
}
