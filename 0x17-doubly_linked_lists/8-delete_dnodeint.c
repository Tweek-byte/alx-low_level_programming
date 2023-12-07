#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at indx
 * @head: Pointer to the head of the list.
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *p;
	unsigned int i;

	if (!head  || !(*head))
		return (-1);
	p = *head;
	if (index == 0)
	{
		*head = p->next;
		if (p->next != NULL)
			p->next->prev = NULL;
		free(p);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (p->next == NULL)
			return (-1);
		p = p->next;
	}
	p->prev->next = p->next;
	if (p->next)
		p->next->prev = p->prev;
	free(p);
	return (1);
}
