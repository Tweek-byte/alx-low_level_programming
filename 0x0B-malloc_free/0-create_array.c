#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Creates an array of characters
 * @size: The size of the array
 * @c: The character to initialize the array elements
 * @i: needed shit
 *
 * Return: On success, a pointer to the allocated array.
 *         On failure or if size is 0, returns NULL.
 */

char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return(NULL);

	char* a = malloc(size * sizeof(char);
	if (a == NULL)
		return(NULL);

	for (unsigned int i = 0; i < size; i++)
		a[i] = c;

	return(a);
}
