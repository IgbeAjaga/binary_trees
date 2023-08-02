#include "binary_trees.h"

/**
 * array_to_avl - Build an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    size_t i;
    avl_t *root = NULL;

    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (avl_insert(&root, array[i]) == NULL)
        {
            /* If insertion fails, free the tree and return NULL */
            binary_tree_delete(root);
            return (NULL);
        }
    }

    return (root);
}
