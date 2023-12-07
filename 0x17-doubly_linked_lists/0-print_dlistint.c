#include "lists.h"

/**
 * print_dlistint - Prints all elements of a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	for (; h != NULL; i++)
	{
		printf("%d", h->n);
		h = h->next;
	}
	return (i);
}
