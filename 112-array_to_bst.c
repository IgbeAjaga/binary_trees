#include "binary_trees.h"

/**
 * array_to_bst - Convert an array to a Binary Search Tree (BST).
 * @array: The array to be converted to a BST.
 * @size: The size of the array.
 *
 * Return: The root node of the resulting BST, or NULL if the array is empty.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *bst_root;

	bst_root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		if (i == 0)
		{
			bst_insert(&bst_root, array[i]);
		}
		else
		{
			bst_insert(&bst_root, array[i]);
		}
	}
	return (bst_root);
}
