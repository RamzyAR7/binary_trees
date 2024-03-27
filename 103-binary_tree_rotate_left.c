#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 * Return: pointer to the new root node
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *r, *r_l;

	if (tree == NULL)
		return (NULL);
	root = tree;
	r = tree->right;
	r_l = tree->right->left;
	root->parent = r;
	r->parent = NULL;
	r->left = root;
	root->right = r_l;
	if (r_l != NULL)
		r_l->parent = root;
	return (r);
}
