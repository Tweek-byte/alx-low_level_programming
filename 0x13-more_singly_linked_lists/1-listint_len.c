#include "lists.h"
#include <stdio.h>

/**
 * listint_len - traverses the list.
 *
 * @h: pointer to the first node of the list.
 *
 * Return: returns the number of elements in a likned list.
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *ptr = h;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return (count);
}
