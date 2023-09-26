#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - sums data(n) of a list and returns it.
 *
 * @head: head of node
 *
 * Return: returns sum of data
 */
int sum_listint(listint_t *head)
{
	listint_t *current;
	int sum = 0;

	if (head == NULL)
		return (0);

	current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
