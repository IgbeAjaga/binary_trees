#include "binary_trees.h"

/**
 * recursive_insert - Insertion of node value into an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node.
 * @new: Pointer for left or right insertion.
 * @nval: Value to insert into the AVL tree.
 * Return: Pointer to the new root after insertion, otherwise NULL.
 */
avl_t *recursive_insert(avl_t **root, avl_t *parent, avl_t **new, int nval)
{
	int balance_factor;

	if (*root == NULL)
		return (*new = binary_tree_node(parent, nval));

	if ((*root)->n > nval)
	{
		(*root)->left = recursive_insert(&(*root)->left, *root, new, nval);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < nval)
	{
		(*root)->right = recursive_insert(&(*root)->right, *root, new, nval);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*root);
	}

	balance_factor = binary_tree_balance(*root);

	if (balance_factor > 1 && (*root)->left->n > nval)
	{
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor > 1 && (*root)->left->n < nval)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n < nval)
	{
		*root = binary_tree_rotate_left(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n > nval)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}

	return (*root);
}

/**
 * avl_insert - Inserts values into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * @value: Value to store in the node.
 * Return: Inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	recursive_insert(tree, *tree, &new, value);
	return (new);
}
