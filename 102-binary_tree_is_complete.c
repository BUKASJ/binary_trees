#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_complete = 1;

	int level_has_incomplete_node = 0;
	int current_level_has_null_child = 0;
	const binary_tree_t *node;

	binary_tree_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		node = queue[front++];

		if (node->left == NULL || node->right == NULL)
			current_level_has_null_child = 1;

		if (level_has_incomplete_node && (node->left || node->right))
			return (0);

		if ((node->left == NULL && node->right) || (current_level_has_null_child &&
					(node->left || node->right)))
			level_has_incomplete_node = 1;

		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}

	return (is_complete);
}
