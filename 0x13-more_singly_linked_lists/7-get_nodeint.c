#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t
 *
 * @head: head of node
 *
 * @index: current position.
 *
 * Return: returns the nnth node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *z = head;
	unsigned int count = 0;

	while (z != NULL)
	{
		if (index == count)
			return (z);
		z = z->next;
		count++;
	}

	return (NULL);
}
