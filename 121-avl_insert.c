#include "binary_trees.h"

/**
 * avl_insert - Insert a value in an AVL Tree
 *
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node, *parent;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    parent = *tree;

    while (parent)
    {
        if (value == parent->n)
            return (NULL);

        if (value < parent->n)
        {
            if (parent->left == NULL)
            {
                new_node = binary_tree_node(parent, value);
                parent->left = new_node;
                return (avl_balance(tree, new_node));
            }
            parent = parent->left;
        }
        else
        {
            if (parent->right == NULL)
            {
                new_node = binary_tree_node(parent, value);
                parent->right = new_node;
                return (avl_balance(tree, new_node));
            }
            parent = parent->right;
        }
    }

    return (NULL);
}
