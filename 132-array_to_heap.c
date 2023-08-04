#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_down - Moves the value down the binary tree to heapify it
 * @root: Double pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest, *node;
    int tmp;

    if (root == NULL)
        return;

    node = root;
    while (1)
    {
        largest = node;
        if (node->left != NULL && node->left->n > largest->n)
            largest = node->left;
        if (node->right != NULL && node->right->n > largest->n)
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
