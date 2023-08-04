#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Tree to go through
 * Return: The height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Tree to go through
 * Return: Balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height = 0, left_height = 0, balance_factor = 0;

	if (tree)
	{
		left_height = ((int)binary_tree_height(tree->left));
		right_height = ((int)binary_tree_height(tree->right));
		balance_factor = left_height - right_height;
	}
	return (balance_factor);
}

/**
 * check_is_perfect - Function that checks if a tree is perfect or not
 * @tree: Tree to check
 * Return: 0 if it is not perfect, or the level of height otherwise
 */
int check_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree->left && tree->right)
	{
		left_height = 1 + check_is_perfect(tree->left);
		right_height = 1 + check_is_perfect(tree->right);
		if (right_height == left_height && right_height != 0 && left_height != 0)
			return (right_height);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect
 * @tree: Tree to check
 * Return: 1 if it is perfect, or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = check_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Tree to check
 * Return: 1 if it is a Max Binary Heap, or 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balance_val;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	balance_val = binary_tree_balance(tree);
	if (balance_val == 0)
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_heap(tree->right));
	}
	if (balance_val == 1)
	{
		return (binary_tree_is_heap(tree->left) && binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
