#include "binary_trees.h"
/**
 * bst_check_right - checks for bst
 * @tree: pointer to root node
 * @indicator: pointer to an indicator int
 * @root: original root node value
*/
void bst_check_right(binary_tree_t *tree, int *indicator, int root)
{
	if (tree == NULL)
		return;
	bst_check_right(tree->left, indicator, root);
	bst_check_right(tree->right, indicator, root);
	if (tree->n >= root)
	{
		*indicator *= 1;
		return;
	}
	else
	{
		*indicator *= 0;
		return;
	}
}
/**
 * bst_check_left - checks for bst
 * @tree: pointer to root node
 * @indicator: pointer to an indicator int
 * @root: original root node value
*/
void bst_check_left(binary_tree_t *tree, int *indicator, int root)
{
	if (tree == NULL)
		return;
	bst_check_left(tree->left, indicator, root);
	bst_check_left(tree->right, indicator, root);
	if (tree->n < root)
	{
		*indicator *= 1;
		return;
	}
	else
	{
		*indicator *= 0;
		return;
	}
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node
 * Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int indicator = 1;

	if (tree == NULL)
		return (0);
	bst_check_left(tree->left, &indicator, tree->n);
	bst_check_right(tree->right, &indicator, tree->n);
	if (tree->left != NULL)
		indicator = binary_tree_is_bst(tree->left);
	if (tree->right != NULL)
		indicator = binary_tree_is_bst(tree->right);
	return (indicator);
}
