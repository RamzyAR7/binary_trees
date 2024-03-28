#include "binary_trees.h"
/**
 * search_bst - locates the position of the target node
 * @tree: double pointer to the parent node
 * @target: double pointer to the target node
 * @value: value to be looked up
*/
void search_bst(bst_t **tree, bst_t **target, int value)
{
	if (*target == NULL && (*tree)->n > value)
	{
		if ((*tree)->left != NULL)
			search_bst(&((*tree)->left), target, value);
	}
	if (*target == NULL && (*tree)->n < value)
	{
		if ((*tree)->right != NULL)
			search_bst(&((*tree)->right), target, value);
	}
	if (*target == NULL && (*tree)->n == value)
	{
		*target = *tree;
		return;
	}
}
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to root node
 * @value: value to be searched
 * Return: pointer to target node or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *target = NULL, *root = (bst_t *)tree;

	if (root == NULL)
		return (target);
	search_bst(&root, &target, value);
	return (target);
}
