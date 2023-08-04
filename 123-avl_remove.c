#include "binary_trees.h"

/**
 * balance_tree - It calculates the balance factor of an
 * AVL tree and executes rotations accordingly.
 * @tree: Pointer to the AVL tree to balance
 */
void balance_tree(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_tree(&(*tree)->left);
	balance_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor_value - Retrieve the successor value, which corresponds
 * to the minimum value found in the right subtree.
 * @node: Pointer to the node to check
 * Return: The minimum value of this subtree
 */
int successor_value(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor_value(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_node_type - Removes a node depending on its children
 * @root: Pointer to the node to remove
 * Return: 0 if it has no children or other value if it has
 */
int remove_node_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}

		free(root);
		return (0);
	}
	else
	{
		new_value = successor_value(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: Pointer to the root of the tree
 * @value: Node with this value to remove
 * Return: The tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Remove a node from an AVL tree
 * @root: Pointer to the root of the tree
 * @value: Node with this value to remove
 * Return: The tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	balance_tree(&root_a);
	return (root_a);
}
