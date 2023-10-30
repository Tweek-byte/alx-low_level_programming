#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 *
 * @filename: is the name of the file.
 * @text_content:  is the NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 * If filename is NULL return -1
 * return 1 if the file exists and -1 if the file does not exist or !per.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int letters;

	if (!filename)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		text_content = "";
	}

	for (letters = 0; text_content[letters] != '\0'; letters++)
		;

	fd = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
	{
		return (-1);
	}

	write(file, text_content, i);
	return (1);
}
