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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree:  pointer to the root node
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((tree_height(tree->left) - 1) - (tree_height(tree->right) - 1));
}
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
 * left_shifted - checks if a binary tree is left shifted
 * @tree: pointer to the root node
 * Return: 1 or negative if left shifted else 0 or > 1
*/
int left_shifted(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (-2);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	return (left_shifted(tree->left) * left_shifted(tree->right));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 * Return: 1 if complete else 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_balance(tree) == 0)
	{
		if (is_full(tree->right) == 1 && is_full(tree->left) == 0)
			return (0);
		if (left_shifted(tree) == 1 || left_shifted(tree) < 0)
			return (1);
		else
			return (0);
	}
	else if (binary_tree_balance(tree) == 1)
	{
		if (left_shifted(tree) == 1 || left_shifted(tree) < 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
