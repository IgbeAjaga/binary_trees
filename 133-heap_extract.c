#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes in a binary tree.
 *
 * @node1: First node.
 * @node2: Second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int tmp;

    tmp = node1->n;
    node1->n = node2->n;
    node2->n = tmp;
}

/**
 * get_last_node - Gets the last level-order node in the binary tree.
 *
 * @root: Pointer to the root node of the binary tree.
 *
 * Return: Pointer to the last level-order node, or NULL on failure.
 */
heap_t *get_last_node(heap_t *root)
{
    size_t size, i;
    heap_t **queue, *node, *last_node = NULL;

    if (root == NULL)
        return (NULL);

    size = binary_tree_size(root);

    queue = malloc(sizeof(heap_t *) * size);
    if (queue == NULL)
        return (NULL);

    queue[0] = root;

    for (i = 0; i < size; ++i)
    {
        node = queue[i];
        if (node == NULL)
            break;

        last_node = node;
        queue[(2 * i) + 1] = node->left;
        queue[(2 * i) + 2] = node->right;
    }

    free(queue);
    return (last_node);
}

/**
 * heapify_up - Move the value up the binary heap to maintain max heap.
 *
 * @node: Pointer to the node to start the heapify up process.
 */
void heapify_up(heap_t *node)
{
    heap_t *parent;
    int tmp;

    while (node->parent != NULL)
    {
        parent = node->parent;

        if (node->n <= parent->n)
            break;

        tmp = node->n;
        node->n = parent->n;
        parent->n = tmp;

        node = parent;
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node;
    int value;

    if (root == NULL || *root == NULL)
        return (0);

    last_node = get_last_node(*root);
    if (last_node == NULL)
        return (0);

    value = (*root)->n;
    swap_values(*root, last_node);

    if (last_node->parent != NULL)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }

    free(last_node);
    heapify_down(*root);
    return (value);
}
