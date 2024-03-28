#include "binary_trees.h"
/**
 * locate_position - locates the right position for the inserted node
 * @tree: double pointer to the parent node
 * @inserted: double pointer to the inserted node
*/
void locate_position(bst_t **tree, bst_t **inserted)
{
	if (*inserted != NULL && (*tree)->n > (*inserted)->n)
	{
		if ((*tree)->left != NULL)
			locate_position(&((*tree)->left), inserted);
		else
		{
			(*tree)->left = *inserted;
			(*inserted)->parent = *tree;
			return;
		}
	}
	if (*inserted != NULL && (*tree)->n < (*inserted)->n)
	{
		if ((*tree)->right != NULL)
			locate_position(&((*tree)->right), inserted);
		else
		{
			(*tree)->right = *inserted;
			(*inserted)->parent = *tree;
			return;
		}
	}
	if (*inserted != NULL && (*tree)->n == (*inserted)->n)
	{
		free(*inserted);
		*inserted = NULL;
		return;
	}

}
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node or NULL
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *inserted = binary_tree_node(*tree, value);

	if (*tree == NULL)
	{
		*tree = inserted;
		return (inserted);
	}
	locate_position(tree, &inserted);
	return (inserted);
}
