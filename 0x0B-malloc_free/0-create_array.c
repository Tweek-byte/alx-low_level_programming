#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Creates an array of characters
 * @size: The size of the array
 * @c: The character to initialize the array elements
 *
 * Return: On success, a pointer to the allocated array.
 *         On failure or if size is 0, returns NULL.
 */

char *create_array(unsigned int size, char c)
{
	char *a = malloc(size);

	if (a == NULL || size == 0)
		return (NULL);

	while (size--)
		a[size] = c;

	return (a);
}
