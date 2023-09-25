#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint_end - adds node at the end of a list.
 *
 * @head: head of the node.
 *
 * @n: value to be added.
 *
 * Return: returns the adress of the last node, NULL if fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *z, *temp;

	if (head == NULL)
		return (NULL);

	z = (listint_t *)malloc(sizeof(listint_t));
	if (z == NULL)
		return (NULL);

	z->n = n;
	z->next = NULL;
	if (*head == NULL)
	{
		*head = z;
			return (z);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = z;
	return (z);
}
