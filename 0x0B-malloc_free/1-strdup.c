#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *str2;
	int i, wc = 0;

	if (str == NULL)
		return (NULL);
	while (str[wc])
		wc++;
	str2 = malloc(sizeof(char) * (wc + 1));
	if (str2 == NULL)
		return (NULL);
	for (i = 0; i < wc; i++)
		str2[i] = str[i];
	str2[wc] = '\0';
	return (str2);
}
