#include "main.h"

/**
 * binary_to_uint - converts base 2 to ba uint
 * @b: binary string number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;

	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b != '1' && *b != '0')
			return (0);
		res = (*b++ - '0') + 2 * res;
	}
	return (res);
}
