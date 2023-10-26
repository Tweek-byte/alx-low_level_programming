#include "main.h"

/**
 * print_binary - prints a number as binary str
 * @n: number
 *
 * Return: (void)
 */
void print_binary(unsigned long int n)
{
	int octet = sizeof(n) * 8, str = 0;

	while (octet == true)
	{
		if (n & 1L << --octet)
		{
			_putchar('1');
			str++;
		}
		else if (str == true)
			_putchar('0')
	}
	if (str == 0)
		_putchar('0');
}
