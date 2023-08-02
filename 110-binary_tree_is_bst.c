#include <stdbool.h>
#include "binary_trees.h"

/**
 * is_bst_util - Recursive function to check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree
 * @prev: Pointer to the previously visited node
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t **prev)
{
    if (tree == NULL)
        return (1);

    if (!is_bst_util(tree->left, prev))
        return (0);

    if (*prev != NULL && tree->n <= (*prev)->n)
        return (0);

    *prev = tree;

    return is_bst_util(tree->right, prev);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    const binary_tree_t *prev = NULL;
    return (is_bst_util(tree, &prev));
}
