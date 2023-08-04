#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        /* Check if the value already exists in the AVL tree */
        if (avl_find(root, array[i]) == NULL)
        {
            /* Insert the value into the AVL tree */
            if (!avl_insert(&root, array[i]))
                return (NULL);
        }
    }

    return (root);
}
