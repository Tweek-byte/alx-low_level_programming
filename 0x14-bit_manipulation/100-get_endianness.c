#include "main.h"

/**
 * get_endianness - Checks endianness.
 *
 * Return: 0 for big endian, 1 for little.
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *e = (char *)&n;

	return (*e);
}
