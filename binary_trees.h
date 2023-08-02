#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree Structure */
typedef struct binary_tree_s bst_t;

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap Structure */
typedef struct binary_tree_s heap_t;

/* Print Functions */
void binary_tree_print(const binary_tree_t *);

/* Task 0 - New Node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1 - Insert Left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2 - Insert Right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3 - Delete Tree */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4 - Is Leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Task 5 - Is Root */
int binary_tree_is_root(const binary_tree_t *node);

/* Task 6 - Pre-order Traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Task 7 - In-order Traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Task 8 - Post-order Traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Task 9 - Height of Binary Tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Task 10 - Depth of Binary Tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Task 11 - Size of Binary Tree */
size_t binary_tree_size(const binary_tree_t *tree);

/* Task 12 - Number of Leaves in Binary Tree */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Task 13 - Number of Nodes with at least 1 child in Binary Tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Task 14 - Number of Nodes at Specific Level of Binary Tree */
size_t binary_tree_level(const binary_tree_t *tree, size_t level);

/* Task 15 - Check if Binary Tree is Full */
int binary_tree_is_full(const binary_tree_t *tree);

/* Task 16 - Check if Binary Tree is Perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Task 17 - Find Sibling Node */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Task 18 - Find Uncle Node */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Task 19 - Find Lowest Common Ancestor */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* Task 20 - Check if Binary Tree is BST */
int binary_tree_is_bst(const binary_tree_t *tree);

/* Task 21 - Balance Factor of AVL Tree Node */
int binary_tree_balance(const binary_tree_t *tree);

/* Task 22 - Check if AVL Tree is Balanced */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Task 23 - Sort Array to AVL Tree */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Task 24 - Convert Binary Tree to Heap */
heap_t *binary_tree_to_heap(binary_tree_t *tree);

/* Task 25 - Check if Binary Tree is Heap */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Task 26 - Insert Node in Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);

/* Task 27 - Array to Binary Heap */
heap_t *array_to_heap(int *array, size_t size);

/* Task 28 - Extract Max Node from Binary Heap */
int heap_extract(heap_t **root);

/* Task 29 - Binary Heap to Sorted Array */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/* Task 30 - Print Array */
void print_array(const int *array, size_t size);

#endif /* BINARY_TREES_H */
