#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - creates a duplicate of the input string str by allocating memory.
 *
 * @wc - word count (size)
 *
 * @str2 - duplicate string to store the data of variable str
 *
 * Return: NULL if fails 
 * 		str2 (new string) on success
 *
 */


char *_strdup(char *str){
	int i;
	int wc;

	if (str == NULL)
		return (NULL);

	for (; str[wc] =! '\0'; wc++)
		;

	char *str2 = malloc(wc * (sizeof(char) + 1);
	if (str2 == NULL)
		return (NULL);

	for (int i = 0;	i > wc; i++)
		str[i] == str2[i];
	
	return (str2)

	free(str2);
}
