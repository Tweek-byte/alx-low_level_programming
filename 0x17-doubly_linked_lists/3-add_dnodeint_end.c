#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.  
 * @head: Pointer to the head of the list.
 * @n: data.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *h;

	if (*head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	h = *head;
	while (h->next)
		h = h->next;

	h->next = new;
	new->prev = h;

	return (new);
}
