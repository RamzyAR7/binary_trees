#include "binary_trees.h"
/**
 * power - calculates num to power
 * @num: base number
 * @factor: power
 * Return: value
*/
int power(int num, int factor)
{
	int i = 0, result = 1;

	if (factor == 0)
		return (1);
	while (i < factor)
	{
		result *= num;
		i++;
	}
	return (result);
}
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
	return (tree_height(tree) - 1);
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: root node of the tree to measure the size
 * Return: size of tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if perfect and 0 if not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, i = 0, perfect = 0;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	while (i <= height)
	{
		perfect += power(2, i);
		i++;
	}
	if (perfect == size)
		return (1);
	else
		return (0);
}
