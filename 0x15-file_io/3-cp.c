#include "main.h"
/**
 * main - copies the content of a file to another file.
 *
 * @argc: argument count.
 * @argv: argument value.
 *
 * Return: content copied
*/
int main(int argc, char **argv)
{
	int file_1, file_2, letters;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_1 = open(argv[1], O_RDONLY);
	if (file_1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	while ((letters = read(file_1, buf, 1024)) > 0)
	{
		if (write(file_2, buf, letters) != letters || file_2 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (letters == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(file_1) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_1);
		exit(100);
	}
	if (close(file_2) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_2);
		exit(100);
	}
	return (0);
}
