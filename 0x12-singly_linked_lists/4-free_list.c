#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * release_list - Frees the memory allocated for a linked list.
 *
 * @head: A pointer to the first node of the list to be freed.
 */
void release_list(list_t *head)
{
	if (head)
	{
		release_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}
