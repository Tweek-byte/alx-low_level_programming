#include "main.h"
/**
 * read_textfile - reads a text file and prints it to
 * the POSIX standard output.
 *
 * @filename: file to read
 * @letters: number of letters to be printed to STDOUT_FILENO
 *
 * Return: returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buf[1024 * 8];
	ssize_t bytes;
	ssize_t to_print;

	if (filename == NULL)
		return (0);
	if (!letters)
		return (0);

	fd = open(filename, O_RDONLY)
		if (fd == -1)
			return (0);

	bytes = read(fd, &buf[0], letters);
	if (bytes == -1)
		close(fd);
		return (0);

	to_print = write(STDOUT_FILENO, &buf[0], bytes);
	if (to_print == -1)
		close(fd);
		return (0);

	close(fd);
	return (to_print);
}
