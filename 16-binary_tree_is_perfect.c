#include "binary_trees.h"

/**
 * check_perfect_tree - Function that checks if a tree is perfect or not.
 * A perfect tree has the same quantity of levels in the left
 * and right subtrees, and each node has either two children or no children.
 *
 * @tree: Tree to check.
 * Return: The level of height if it is a perfect tree, or 0 if it is not.
 */
int check_perfect_tree(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree->left && tree->right)
	{
		left_height = 1 + check_perfect_tree(tree->left);
		right_height = 1 + check_perfect_tree(tree->right);
		if (left_height == right_height && left_height != 0 && right_height != 0)
			return (left_height);
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
 * binary_tree_is_perfect - Function that checks if a binary tree is perfect.
 * A perfect binary tree is a tree in which all its levels
 * are completely filled, and all nodes have either two children or none.
 *
 * @tree: Root of the tree to check.
 * Return: 1 if it is a perfect tree, or 0 if it is not.
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
		result = check_perfect_tree(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
