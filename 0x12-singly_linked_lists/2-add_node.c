#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * _strlen - Returns the length of a string.
 * @s: Input string.
 *
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the head of a list_t list.
 * @str: Value to be inserted into the new element.
 *
 * Return: Address of the newly added node.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = strdup(str);

	add->len = _strlen(str);
	add->next = *head;
	*head = add;

	return (add);
}
