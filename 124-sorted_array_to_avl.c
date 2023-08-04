#include "binary_trees.h"

/**
 * aux_sort - AVL tree using the half element of the array
 * @parent: Parent of the node to create
 * @array: Sorted array
 * @begin: Startin position of the array
 * @end: Position where the array ends
 * Return: Created AVL tree
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= end)
	{
		mid = (begin + end) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, end);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - AVL tree from a sorted array
 * @array: Sorted array
 * @size: Size of the sorted array
 * Return: AVL tree from the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)size) - 1));
}
