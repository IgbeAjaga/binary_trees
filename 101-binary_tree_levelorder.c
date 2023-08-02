#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_enqueue - Enqueues a node in a binary tree queue
 *
 * @rear: Pointer to the rear of the queue
 * @node: Pointer to the node to enqueue
 */
void binary_tree_enqueue(binary_tree_t **rear, const binary_tree_t *node)
{
    binary_tree_t *new = (binary_tree_t *)node;

    if (rear == NULL)
        return;

    if (*rear == NULL)
    {
        new->next = new;
        *rear = new;
    }
    else
    {
        new->next = (*rear)->next;
        (*rear)->next = new;
        *rear = new;
    }
}

/**
 * binary_tree_dequeue - Dequeues a node from a binary tree queue
 *
 * @rear: Pointer to the rear of the queue
 *
 * Return: Pointer to the dequeued node
 */
binary_tree_t *binary_tree_dequeue(binary_tree_t **rear)
{
    binary_tree_t *front;

    if (rear == NULL || *rear == NULL)
        return (NULL);

    front = (*rear)->next;

    if (*rear == front)
        *rear = NULL;
    else
        (*rear)->next = front->next;

    front->next = NULL;
    return (front);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t *rear = NULL;

    if (tree == NULL || func == NULL)
        return;

    binary_tree_enqueue(&rear, tree);

    while (rear != NULL)
    {
        binary_tree_t *current = binary_tree_dequeue(&rear);

        if (current != NULL)
        {
            func(current->n);

            if (current->left != NULL)
                binary_tree_enqueue(&rear, current->left);
            if (current->right != NULL)
                binary_tree_enqueue(&rear, current->right);
        }
    }
}
