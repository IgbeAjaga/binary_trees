#include <stddef.h>
#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the binary tree.
 * @index: Current index of the node in the binary tree.
 * @node_count: Total number of nodes in the binary tree.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_heap - Checks if a binary tree is a max binary heap.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max binary heap, otherwise 0.
 */
int is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    if (tree->left && tree->n < tree->left->n)
        return (0);

    if (tree->right && tree->n < tree->right->n)
        return (0);

    return (is_heap(tree->left) && is_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    size_t node_count = binary_tree_size(tree);

    return (is_complete(tree, 0, node_count) && is_heap(tree));
}
