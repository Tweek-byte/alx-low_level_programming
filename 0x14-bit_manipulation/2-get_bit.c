#include "main.h"

/**
 * get_bit - get bit at a certain index
 * @n: The number.
 * @index: The index.
 *
 * Return: The value of the bit at the given index (0 or 1),
 * 	-1 if we cant.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
	{
		return (-1);
	}

	return ((n >> index) & 1);
}

