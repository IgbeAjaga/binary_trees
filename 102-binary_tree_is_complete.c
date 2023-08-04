#include "binary_trees.h"

/**
 * create_node - Creates a new node for
 * the linked list.
 * @node: Pointer to the binary tree node.
 *
 * Return: Pointer to the new node.
 */
link_t *create_node(binary_tree_t *node)
{
	link_t *new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees the nodes in the linked list.
 * @head: Pointer to the head node of the linked list.
 */
void free_queue(link_t *head)
{
	link_t *temp_node;
	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

/**
 * push - Pushes a node into the stack (linked list).
 * @node: Pointer to the binary tree node to push.
 * @head: Pointer to the head node of the stack.
 * @tail: Pointer to the tail node of the stack.
 */
void push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop - Pops a node from the stack (linked list).
 * @head: Pointer to the head node of the stack.
 */
void pop(link_t **head)
{
	link_t *temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_is_complete - Checks if
 * a binary tree is complete.
 * @tree: Pointer to the binary tree node.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;

		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;

		pop(&head);
	}

	return (1);
}
