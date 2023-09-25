#include "lists.h"
#include <stdio.h>

/**
 * add_nodeint - adds node to the beginning of a list.
 *
 * @head: pointer to the adress of h (in the main function).
 * @n: value to be stored in the new node.
 *
 * Return: adress of the new element of the new node, NULL if fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	if (head == NULL)
		return (NULL);
	listint_t *zbi = (listint_t *)malloc(sizeof(listint_t));
	if (zbi == NULL)
		return (NULL);
	zbi->n = n;
	zbi->next = *head;
	*head = zbi;

	return (zbi);
}
