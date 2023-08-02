#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_down - Move the value down the binary heap to maintain max heap.
 *
 * @node: Pointer to the node to start the heapify down process.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest, *tmp;

    while (1)
    {
        largest = node;

        if (node->left && node->left->n > largest->n)
            largest = node->left;

        if (node->right && node->right->n > largest->n)
            largest = node->right;

        if (largest == node)
            break;

        tmp = node->n;
        node->n = largest->n;
        largest->n = tmp;

        node = largest;
    }
}

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
    size_t i;
    heap_t *root, *parent, *new_node;

    if (array == NULL || size == 0)
        return (NULL);

    root = binary_tree_node(NULL, array[0]);
    if (root == NULL)
        return (NULL);

    for (i = 1; i < size; ++i)
    {
        parent = root;
        new_node = binary_tree_node(NULL, array[i]);
        if (new_node == NULL)
            return (NULL);

        while (1)
        {
            if (binary_tree_height(parent->left) <= binary_tree_height(parent->right))
            {
                if (parent->left == NULL)
                {
                    parent->left = new_node;
                    new_node->parent = parent;
                    heapify_down(new_node);
                    break;
                }
                parent = parent->left;
            }
            else
            {
                if (parent->right == NULL)
                {
                    parent->right = new_node;
                    new_node->parent = parent;
                    heapify_down(new_node);
                    break;
                }
                parent = parent->right;
            }
        }
    }

    return (root);
}
