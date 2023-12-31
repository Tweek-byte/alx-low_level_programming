#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *ptr;
	unsigned long int i;
	char flag = 0;

	if (!ht || !ht->array)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			if (flag == 1)
				printf(", ");

			printf("'%s': '%s'", ptr->key, ptr->value);
			flag = 1;
			ptr = ptr->next;
		}
	}

	printf("}\n");
}
