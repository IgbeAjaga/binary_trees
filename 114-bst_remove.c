/**
 * remove_type - Removes a node
 * depending on its children
 * @node: Node to remove
 * Return: 0 if it has no children, or other value if otherwise
 */
int remove_type(bst_t *node)
{
	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
		return (get_successor(node->right));
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: Root of the tree
 * @value: Value of the node to remove
 * Return: The updated tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			root->right = bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}
