#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: root node of the tree to measure the size
 * Return: size of tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t len = 0;

	if (tree == NULL)
	{
		return (0);
	}

	len = 1 + binary_tree_size(tree->left);
	len += binary_tree_size(tree->right);

	return (len);
}
