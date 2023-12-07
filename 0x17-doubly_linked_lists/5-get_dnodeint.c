#include "lists.h"

/**
 * get_dnodeint_at_index - gets nodes at index
 * @head: Pointer to the head of the list.
 * @index: is the index of the node, starting from 0
 *
 * Return: returns the nth node of a dlistint_t linked list, return NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int c;

	if (!head)
		return (NULL);
	if (index == 0)
		return (head);
	for (c = 0; c < index; c++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
