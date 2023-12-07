#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the beginning of the linked list
 * @idx: is the index of the list where the new node should be added.
 * @n: data
 *
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *next;
	dlistint_t *ptr;

	unsigned int c;

	if (!h)
		return (NULL);
	if (idx != 0)
	{
		ptr = *h;
		for (c = 0; c < idx - 1 && ptr; c++)
			ptr = ptr->next;
		if (!ptr)
			return (NULL);
	}
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		next = *h;
		*h = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = ptr;
		next = ptr->next;
		ptr->next = new;
	}
	new->next = next;
	if (new->next)
		new->next->prev = new;
	return (new);
}
