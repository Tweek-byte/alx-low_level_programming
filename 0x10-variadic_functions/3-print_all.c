#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints arguments based on the format
 * @format: format string containing types of arguments
 *
 * Description: This function takes a format string and variable arguments
 *              and prints the arguments based on the format specified.
 *              The format string can contain the following types:
 *              - 'c': for char arguments
 *              - 'i': for integer arguments
 *              - 'f': for float arguments
 *              - 's': for string arguments (if NULL, "(nil)" is printed)
 *              The arguments are printed in the order specified by the format string.
 *              The function prints a newline character at the end.
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", separator, va_arg(args, int));
		}
		else if (format[i] == 'i')
		{
			printf("%s%i", separator, va_arg(args, int));
		}
		else if (format[i] == 'f')
		{
			printf("%s%f", separator, va_arg(args, double));
		}
		else if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", separator, str);
		}

		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
