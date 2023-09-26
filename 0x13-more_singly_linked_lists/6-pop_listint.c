#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - remvoves head's node
 *
 * @head: head of node
 *
 * Return: 0 if empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *z;
	int n;

	if (head == NULL || *head == NULL)

		return (0);

	z = head;
	n = z->n;
	*head = (*head)->next;

	free(z);
	return (n);
}
