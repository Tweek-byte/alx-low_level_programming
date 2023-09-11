#include <stdlib.h>

/**
 * main - pints the name of the file
 *
 * Return: returns 0 on success.
*/

int main(void)
{
	char *filename = __FILE__;

	while (*filename != '\0')
	{
	write(1, filename, 1);
	filename++;
	}

	write(1, "\n", 1);

	return (0);
}
