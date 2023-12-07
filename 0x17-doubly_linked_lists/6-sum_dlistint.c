#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data.
 * @head: Pointer to the head of the list.
 *
 * Return: sum.
 */

int sum_dlistint(dlistint_t *head)
{
	int count = 0;

	while (head)
	{
		count += head->n;
		head = head->next;
	}
	return (count);
