#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generates key for crackme5
 * @argc: num of arguments
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	unsigned int index, sum;
	size_t username_length, sum_of_chars;
	char *charset =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char generated_key[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	username_length = strlen(argv[1]);
	generated_key[0] = charset[(username_length ^ 59) & 63];
	for (index = 0, sum_of_chars = 0; index < username_length; index++)
		sum_of_chars += argv[1][index];
	generated_key[1] = charset[(sum_of_chars ^ 79) & 63];
	for (index = 0, sum = 1; index < username_length; index++)
		sum *= argv[1][index];
	generated_key[2] = charset[(sum ^ 85) & 63];
	for (sum = argv[1][0], index = 0; index < username_length; index++)
		if ((char)sum <= argv[1][index])
			sum = argv[1][index];
	srand(sum ^ 14);
	generated_key[3] = charset[rand() & 63];
	for (sum = 0, index = 0; index < username_length; index++)
		sum += argv[1][index] * argv[1][index];
	generated_key[4] = charset[(sum ^ 239) & 63];
	for (sum = 0, index = 0; (char)index < argv[1][0]; index++)
		sum = rand();
	generated_key[5] = charset[(sum ^ 229) & 63];
	printf("%s\n", generated_key);
	return (0);
}
