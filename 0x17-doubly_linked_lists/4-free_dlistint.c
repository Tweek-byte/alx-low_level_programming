#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
