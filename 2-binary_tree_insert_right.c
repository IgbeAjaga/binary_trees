#include "binary_trees.h"

/**
 * binary_tree_insert_right - Add a node to the right of the parent.
 * If the parent already has a right child, the new node is inserted
 * below the existing right child.
 *
 * @parent: Pointer to the parent node.
 * @value: Value of the new node to be inserted.
 * Return: Pointer to the new node, or NULL if it fails.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;
	return (new_node);
}
