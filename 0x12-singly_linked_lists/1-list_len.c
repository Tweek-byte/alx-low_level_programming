#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len -  returns the number of elements in a linked list_t list.
 * @h: name of the list
 * Return: the number of elements in a linked list_t list.
 */
size_t list_len(const list_t *h)
{
	int counter = 0;

	while (h)
	{
		counter++;
		h = h->next;
	}
	return (counter);
}
