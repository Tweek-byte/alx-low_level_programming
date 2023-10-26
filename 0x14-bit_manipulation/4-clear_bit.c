#include "main.h"

/**
 * clear_bit - clears bit at index
 * @n: points to index
 * @index: index of bit.
 *
 * Return: 1 if it worked, or -1 if fails.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
		unsigned long int trac = 1UL << index;

		if (index >= 8 * sizeof(*n))
			return (-1);

		*n = *n & ~trac;

	return (1);
}
