#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints a list of nodes.
 *
 * @h: pointer to the first node.
 *
 * Return: number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *ptr = h;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
		count++;
	}

	return (count);
}
