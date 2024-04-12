#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first == second->parent || second == first->parent)
		return ((binary_tree_t *)first->parent);

	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	if (first == second->parent->parent || second == first->parent->parent)
		return ((binary_tree_t *)first->parent->parent);

	if (first->parent == second->parent->parent || second->parent ==
			first->parent->parent)
		return ((binary_tree_t *)first->parent->parent);

	if (first->parent == second->parent->parent->parent ||
			second->parent == first->parent->parent->parent)
		return ((binary_tree_t *)first->parent->parent->parent);

	if (first->parent->parent == second->parent->parent->parent ||
			second->parent->parent == first->parent->parent->parent)
		return ((binary_tree_t *)first->parent->parent->parent);

	return (NULL);
}
