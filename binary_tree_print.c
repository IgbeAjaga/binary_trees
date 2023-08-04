#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree_recursively - Stores recursively each level in an array of strings
 *
 * @node: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @tree_str: Buffer to store the printed tree
 *
 * Return: Length of printed tree after processing
 */
static int print_tree_recursively(const binary_tree_t *node, int offset, int depth, char **tree_str)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!node)
		return (0);
	is_left = (node->parent && node->parent->left == node);
	width = sprintf(b, "(%03d)", node->n);
	left = print_tree_recursively(node->left, offset, depth + 1, tree_str);
	right = print_tree_recursively(node->right, offset + left + width, depth + 1, tree_str);
	for (i = 0; i < width; i++)
		tree_str[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			tree_str[depth - 1][offset + left + width / 2 + i] = '-';
		tree_str[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			tree_str[depth - 1][offset - width / 2 + i] = '-';
		tree_str[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * calculate_tree_height - Measures the height of a binary tree
 *
 * @node: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t calculate_tree_height(const binary_tree_t *node)
{
	size_t height_left, height_right;

	height_left = node->left ? 1 + calculate_tree_height(node->left) : 0;
	height_right = node->right ? 1 + calculate_tree_height(node->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **tree_str;
	size_t height, i, j;

	if (!tree)
		return;
	height = calculate_tree_height(tree);
	tree_str = malloc(sizeof(*tree_str) * (height + 1));
	if (!tree_str)
		return;
	for (i = 0; i < height + 1; i++)
	{
		tree_str[i] = malloc(sizeof(**tree_str) * 255);
		if (!tree_str[i])
			return;
		memset(tree_str[i], 32, 255);
	}
	print_tree_recursively(tree, 0, 0, tree_str);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (tree_str[i][j] != ' ')
				break;
			tree_str[i][j] = '\0';
		}
		printf("%s\n", tree_str[i]);
		free(tree_str[i]);
	}
	free(tree_str);
}
