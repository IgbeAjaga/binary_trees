#include <stdlib.h>
#include <stdio.h>
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
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    binary_tree_t *rear = NULL;
    int flag = 0;

    if (tree == NULL)
        return (0);

    binary_tree_enqueue(&rear, tree);

    while (rear != NULL)
    {
        binary_tree_t *current = binary_tree_dequeue(&rear);

        if (current != NULL)
        {
            if (flag)
            {
                if (current->left != NULL || current->right != NULL)
                    return (0);
            }
            else
            {
                if (current->left == NULL && current->right != NULL)
                    return (0);

                if (current->left != NULL)
                    binary_tree_enqueue(&rear, current->left);
                else
                    flag = 1;

                if (current->right != NULL)
                    binary_tree_enqueue(&rear, current->right);
                else
                    flag = 1;
            }
        }
    }

    return (1);
}
