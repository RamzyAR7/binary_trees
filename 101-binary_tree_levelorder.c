#include "binary_trees.h"
/**
 * make_q - makes a new node
 * @queue: queue
 * @now: value of node
 * Return: node
*/
void make_q(q **queue, binary_tree_t **now)
{
	q *new, *current;

	new = malloc(sizeof(q));
	if (new == NULL)
		return;
	new->steady = *now;
	new->next = NULL;
	if (*queue == NULL)
	{
		*queue = new;
		(*queue)->prev = NULL;
	}
	else
	{
		current = *queue;
		while (current->next != NULL)
		{
			current = current->next;
		}
		new->prev = current;
		current->next = new;
	}
}
/**
 * rm_q - makes a new node
 * @queue: queue
 * @func: function of int value
 * Return: node
*/
int rm_q(q **queue, void (*func)(int))
{
	int added = 0;
	q *current, *temp;

	if (*queue == NULL)
		return (added);
	current = *queue;
	if (current->steady->left != NULL)
	{
		make_q(queue, &(current->steady->left));
		added += 1;
	}
	if (current->steady->right != NULL)
	{
		make_q(queue, &(current->steady->right));
		added += 1;
	}
	func(current->steady->n);
	temp = *queue;
	if ((*queue)->next != NULL)
		(*queue)->next->prev = NULL;
	*queue = (*queue)->next;
	free(temp);
	temp = NULL;
	return (added);
}
/**
 * binary_tree_levelorder - goes through a tree using level-order traversal
 * @tree: pointer to root node
 * @func: pointer to function of node value
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	q *queue = NULL;
	binary_tree_t *current;
	int going = 1;

	if (tree == NULL || func == NULL)
		return;
	current = (binary_tree_t *)tree;
	make_q(&queue, &current);
	while (going)
	{
		going += rm_q(&queue, func);
		going--;
	}
}
