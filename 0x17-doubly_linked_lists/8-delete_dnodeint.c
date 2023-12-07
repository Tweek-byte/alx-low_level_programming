#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index.
 * @head: Pointer to the head of the list.
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr;
	unsigned int i;

	if (!head || !*head)
		return (-1);
	ptr = *head;
	if (index == 0)
	{
		*head = ptr->next;
		if (ptr->next == NULL)
			ptr->next->prev = NULL;
		free(ptr);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (ptr->next == NULL)
			return (-1);
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	free(ptr);
	return (1);
}
