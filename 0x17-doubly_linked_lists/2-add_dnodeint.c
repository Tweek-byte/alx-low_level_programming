#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: Pointer to the head of the list.
 * @n: data.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*dlistint_t));
	if (!new)
	{
		return (NULL);
	}

	new->prev = NULL;
	new->next = *head;
	new->n = n;

	if (!head)
		(*head = new);
	*head = new;

	return (new);
}
