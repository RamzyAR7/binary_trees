#include "binary_trees.h"
/**
 * is_full - checks if a binary tree is full
 * @tree: pointer to the root node
 * Return: 1 if full else 0
*/
int is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	else if (tree->left == NULL && tree->right != NULL)
		return (0);
	return (is_full(tree->left) * is_full(tree->right));
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node
 * Return: 1 if full else 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full(tree));
}
