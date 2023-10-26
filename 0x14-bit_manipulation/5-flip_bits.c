#include "main.h"

/**
 * flip_bits - flipi dak lhza9
 * @n: number
 * @m: index
 * Return: ch7al flipina
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int res = 0;
	unsigned long int count = n ^ m;

	while (count > 0)
	{
		res += count & 1;
		count >>= 1;
	}

	return (res);
}
