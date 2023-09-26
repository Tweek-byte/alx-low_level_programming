#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees the list.
 *
 * @head: pointer to the first node.
 *
 * Return: void.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *temp;

	if (head == NULL)
		return;

	current = *head;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*head = NULL;
}
