#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to the lowest common ancestor of two nodes
*/
binary_tree_t *binary_trees_ancestor(const b_t *first, const b_t *second)
{
	binary_tree_t *current, *current_2;

	current = (binary_tree_t *)first;
	current_2 = (binary_tree_t *)second;
	while (current)
	{
		current_2 = (binary_tree_t *)second;
		while (current_2)
		{
			if (current == current_2)
				return (current_2);
			current_2 = current_2->parent;
		}
		current = current->parent;
	}
	return (NULL);
}
