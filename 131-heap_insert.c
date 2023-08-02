#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Heapify the binary tree after inserting a new node.
 *
 * @node: Pointer to the newly inserted node.
 *
 * Return: Pointer to the root of the binary tree.
 */
heap_t *heapify(heap_t *node)
{
    int tmp;

    while (node->parent && node->n > node->parent->n)
    {
        tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }

    return (node);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the binary heap.
 * @value: The value to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;
    while (parent->left && parent->right)
    {
        if (binary_tree_height(parent->left) <= binary_tree_height(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    return (heapify(new_node));
}
