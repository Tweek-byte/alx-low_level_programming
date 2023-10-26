#include "main.h"

/**
 * set_bit - set the bit to 1.
 * @n: points to the number
 * @index: index at which we should set the bit to 1.
 *
 * Return: 1 if it worked, or -1 if fails.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
		unsigned long int trac = 1UL << index;

		if (index >= 8 * sizeof(*n))
			return (-1);

		*n = *n | trac;

	return (1);
}
