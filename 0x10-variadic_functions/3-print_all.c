#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints arguments based on the format.
 * @format: Format string containing types of arguments.
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		j = 1;
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%i", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				j = 0;
				break;
		}

		if (format[i + 1] && j)
			printf(", ");
		i++;
	}

	printf("\n");
	va_end(args);
}
