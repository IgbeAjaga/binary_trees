#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *left_child;

    if (tree == NULL || tree->left == NULL)
        return (tree);

    left_child = tree->left;
    tree->left = left_child->right;

    if (left_child->right != NULL)
        left_child->right->parent = tree;

    left_child->parent = tree->parent;
    tree->parent = left_child;
    left_child->right = tree;

    return (left_child);
}
