#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node
 * Return: pointer to the new root node
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *l, *l_r;

	if (tree == NULL)
		return (NULL);
	root = tree;
	l = tree->left;
	l_r = tree->left->right;
	root->parent = l;
	l->parent = NULL;
	l->right = root;
	root->left = l_r;
	if (l_r != NULL)
		l_r->parent = root;
	return (l);
}
