#include "binary_trees.h"

/**
 * bst_search - Search for a specific value in the
 * binary search tree and return the node.
 * @tree: The binary search tree to search through.
 * @value: The value to search for.
 *
 * Return: The node containing the value or NULL if the value is not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found_node;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found_node = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found_node = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);

	return (found_node);
}
