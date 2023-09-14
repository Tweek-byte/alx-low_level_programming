#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - calculates the sum of variable arguments
 *
 * @n: number of arguments
 * @...: integers
 *
 * Return: the sum result
*/
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0, i = n;
	va_list ap;

	if (!n)
		return (0);
	va_start(ap, n);
	while (i--)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}
