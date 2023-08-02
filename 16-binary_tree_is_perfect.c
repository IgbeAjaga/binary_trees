#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t left_depth, right_depth;

    if (tree == NULL)
        return (0);

    left_depth = binary_tree_depth(tree->left);
    right_depth = binary_tree_depth(tree->right);

    if (left_depth == right_depth)
    {
        if (binary_tree_is_perfect(tree->left) &&
            binary_tree_is_perfect(tree->right))
            return (1);
    }

    return (0);
}
