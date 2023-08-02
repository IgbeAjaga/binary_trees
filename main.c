#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *node;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 90);
    root->right = binary_tree_node(root, 85);
    root->left->right = binary_tree_node(root->left, 80);
    root->left->left = binary_tree_node(root->left, 79);

    binary_tree_print(root);

    node = binary_tree_sibling(root->left);
    printf("Sibling of %d: %d\n", root->left->n, node ? node->n : 0);

    node = binary_tree_sibling(root->right);
    printf("Sibling of %d: %d\n", root->right->n, node ? node->n : 0);

    node = binary_tree_uncle(root->left->right);
    printf("Uncle of %d: %d\n", root->left->right->n, node ? node->n : 0);

    node = binary_tree_uncle(root->left->left);
    printf("Uncle of %d: %d\n", root->left->left->n, node ? node->n : 0);

    node = binary_trees_ancestor(root->left->left, root->right);
    printf("Ancestor of %d and %d: %d\n", root->left->left->n, root->right->n, node ? node->n : 0);

    node = binary_trees_ancestor(root->left, root->left->right);
    printf("Ancestor of %d and %d: %d\n", root->left->n, root->left->right->n, node ? node->n : 0);

    printf("Is %d BST: %d\n", root->n, binary_tree_is_bst(root));
    printf("Is %d BST: %d\n", root->left->n, binary_tree_is_bst(root->left));
    printf("Is %d BST: %d\n", root->right->n, binary_tree_is_bst(root->right));

    printf("Balance factor of %d: %d\n", root->n, binary_tree_balance(root));
    printf("Balance factor of %d: %d\n", root->left->n, binary_tree_balance(root->left));
    printf("Balance factor of %d: %d\n", root->right->n, binary_tree_balance(root->right));

    printf("Is %d AVL: %d\n", root->n, binary_tree_is_avl(root));
    printf("Is %d AVL: %d\n", root->left->n, binary_tree_is_avl(root->left));
    printf("Is %d AVL: %d\n", root->right->n, binary_tree_is_avl(root->right));

    avl_t *avl_tree;
    int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95};
    size_t n = sizeof(array) / sizeof(array[0]);

    avl_tree = array_to_avl(array, n);
    binary_tree_print(avl_tree);
    binary_tree_delete(avl_tree);

    heap_t *heap_tree;
    int array_heap[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95};
    size_t n_heap = sizeof(array_heap) / sizeof(array_heap[0]);

    heap_tree = array_to_heap(array_heap, n_heap);
    binary_tree_print(heap_tree);
    binary_tree_delete(heap_tree);

    return (0);
}
