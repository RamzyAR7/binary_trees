#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree +1
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree_height(tree->left) > tree_height(tree->right))
		return (1 + tree_height(tree->left));
	else
		return (1 + tree_height(tree->right));
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree) - 1);
}
