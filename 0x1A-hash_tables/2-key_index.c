#include "hash_tables.h"

/**
 * key_index - returns index of a key
 * @key: from where to get index
 * @size: size of the table
 *
 * Return: index for key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
