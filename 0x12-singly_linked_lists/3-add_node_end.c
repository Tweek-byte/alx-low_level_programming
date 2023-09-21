#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * str_length - Finds the length of a string.
 * @str: String to find the length of.
 *
 * Return: Length of the string.
 */
unsigned int str_length(char *str)
{
	unsigned int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * add_node_end - Adds a new node to the end of a linked list.
 * @head: Double pointer to the head of the linked list.
 * @str: String to add to the new node.
 *
 * Return: Pointer to the new node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;

	if (str == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = str_length(new_node->str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (new_node);
}
