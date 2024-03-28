#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: array
 * @size: size of array
 * Return: pointer to the root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i = 1;

	if (array == NULL || size == 0)
		return (NULL);
	root = binary_tree_node(NULL, array[0]);
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
