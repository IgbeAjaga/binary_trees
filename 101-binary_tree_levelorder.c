#include "binary_trees.h"

/**
 * binary_tree_height - Function that calculates the height of a binary tree.
 * @tree: The root node of the binary tree.
 *
 * Return: The height of the binary tree.
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
		if (tree)
		{
			left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_depth - Function that calculates the depth of a node from the root.
 * @tree: The node to calculate the depth for.
 *
 * Return: The depth of the node (number of edges from the root).
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * create_linked_node - Creates a linked node containing the node and its depth.
 * @head: Pointer to the head of the linked list.
 * @tree: The node to store in the linked list.
 * @depth: The depth of the node in the tree.
 */
void create_linked_node(link_t **head, const binary_tree_t *tree, size_t depth)
{
	link_t *new_node, *aux;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = depth;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new_node->next = NULL;
		aux->next = new_node;
	}
}

/**
 * traverse_tree - Recursively traverses the
 * tree and stores each node in the linked list.
 * @head: Pointer to the head of the linked list.
 * @tree: The current node to check.
 */
void traverse_tree(link_t **head, const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree != NULL)
	{
		depth = binary_tree_depth(tree);
		create_linked_node(head, tree, depth);
		traverse_tree(head, tree->left);
		traverse_tree(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Traverses the binary tree
 * using level-order traversal.
 * @tree: The root node of the binary tree.
 * @func: The function to be applied to each node in the traversal.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		traverse_tree(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
