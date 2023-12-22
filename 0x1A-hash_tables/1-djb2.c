#include "hash_tables.h"

/**
 * hash_djb2 - djb2 alg
 * @str: string to store hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	int i;
	unsigned long int hv;

	hv = 5381;

	while ((i = *str++))
	{
		hv = ((hv << 5) + hv) + i;
	}

	return (hv);
}
