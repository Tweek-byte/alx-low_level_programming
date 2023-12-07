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
	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7] = "      ";
	size_t username_len = strlen(argv[1]);
	unsigned int index, sum = 0;
	int max_char = argv[1][0];

	key[0] = charset[(username_len ^ 59) & 63];

	for (index = 0; index < username_len; index++)
	{
		sum += argv[1][index];
		key[2] ^= argv[1][index];
		if (argv[1][index] > max_char)
			max_char = argv[1][index];
	}

	key[1] = charset[(sum ^ 79) & 63];
	key[3] = charset[rand() % 64];
	key[4] = charset[(sum * sum ^ 239) & 63];

	srand(max_char ^ 14);
	key[5] = charset[rand() & 63];

	printf("%s\n", key);
	return (0);
}
