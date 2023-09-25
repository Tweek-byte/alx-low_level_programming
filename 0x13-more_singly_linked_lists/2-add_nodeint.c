#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - adds node to the beginning of a list.
 *
 * @head: pointer to the adress of h (in the main function).
 *
 * @n: value to be stored in the new node.
 *
 * Return: adress of the new element of the new node, NULL if fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	if (head == NULL)
		return (NULL);
	listint_t *z = (listint_t *)malloc(sizeof(listint_t));

	if (z == NULL)
		return (NULL);
	z->n = n;
	z->next = *head;
	*head = z;

	return (z);
}
