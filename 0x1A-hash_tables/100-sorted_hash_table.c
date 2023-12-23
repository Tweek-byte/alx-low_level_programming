#include "hash_tables.h"

/**
 * s_hash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
s_hash_table_t *s_hash_table_create(unsigned long int size)
{
	s_hash_table_t *sorted_ht;
	unsigned long int iterator;

	sorted_ht = malloc(sizeof(s_hash_table_t));
	if (!sorted_ht)
		return (NULL);
	sorted_ht->size = size;
	sorted_ht->s_head = NULL;
	sorted_ht->s_tail = NULL;
	sorted_ht->array = malloc(sizeof(shash_node_t) * size);
	if (!sorted_ht->array)
	{
		free(sorted_ht);
		return (NULL);
	}
	for (iterator = 0; iterator < size; iterator++)
	{
		sorted_ht->array[iterator] = NULL;
	}
	return (sorted_ht);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sorted_hash_node;

	sorted_hash_node = malloc(sizeof(shash_node_t));
	if (!sorted_hash_node)
		return (NULL);
	sorted_hash_node->key = strdup(key);
	if (!sorted_hash_node->key)
	{
		free(sorted_hash_node);
		return (NULL);
	}
	sorted_hash_node->value = strdup(value);
	if (!sorted_hash_node->value)
	{
		free(sorted_hash_node->key);
		free(sorted_hash_node);
		return (NULL);
	}
	sorted_hash_node->next = sorted_hash_node->s_next
		= sorted_hash_node->s_prev = NULL;
	return (sorted_hash_node);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @sorted_table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(s_hash_table_t *sorted_table, shash_node_t *node)
{
	shash_node_t *temp;

	if (!sorted_table->s_head && !sorted_table->s_tail)
	{
		sorted_table->s_head = sorted_table->s_tail = node;
		return;
	}
	temp = sorted_table->s_head;
	while (temp)
	{
		if (strcmp(node->key, temp->key) < 0)
		{
			node->s_next = temp;
			node->s_prev = temp->s_prev;
			temp->s_prev = node;
			if (node->s_prev)
				node->s_prev->s_next = node;
			else
				sorted_table->s_head = node;
			return;
		}
		temp = temp->s_next;
	}
	node->s_prev = sorted_table->s_tail;
	sorted_table->s_tail->s_next = node;
	sorted_table->s_tail = node;
}


/**
 * s_hash_table_set - sets a key to a value in the hash table
 * @sot: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int s_hash_table_set(s_hash_table_t *sot, const char *key, const char *value)
{
	unsigned long int array_index;
	char *new_value;
	shash_node_t *sorted_hash_node, *temporary_node;

	if (!sot || !sot->array || !sot->size ||
			!key || !strlen(key) || !value)
		return (0);
	array_index = key_index((const unsigned char *)key, sot->size);
	temporary_node = sot->array[array_index];
	while (temporary_node)
	{
		if (strcmp(temporary_node->key, key) == 0)
		{
			new_value = strdup(value);
			if (!new_value)
				return (0);
			free(temporary_node->value);
			temporary_node->value = new_value;
			return (1);
		}
		temporary_node = temporary_node->next;
	}
	sorted_hash_node = make_shash_node(key, value);
	if (!sorted_hash_node)
		return (0);
	sorted_hash_node->next = sot->array[array_index];
	sot->array[array_index] = sorted_hash_node;
	add_to_sorted_list(sot, sorted_hash_node);
	return (1);
}

/**
 * s_hash_table_get - retrieve a value from the hash table
 * @sorted_ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *s_hash_table_get(const s_hash_table_t *sorted_ht, const char *key)
{
	unsigned long int array_index;
	shash_node_t *temporary_node;

	if (!sorted_ht || !sorted_ht->array || !sorted_ht->size ||
			!key || !strlen(key))
		return (NULL);
	array_index = key_index((const unsigned char *)key, sorted_ht->size);
	temporary_node = sorted_ht->array[array_index];
	while (temporary_node)
	{
		if (strcmp(temporary_node->key, key) == 0)
			return (temporary_node->value);
		temporary_node = temporary_node->next;
	}
	return (NULL);
}

/**
 * s_hash_table_print - prints a sorted hash table
 * @sorted_ht: hash table to print
 *
 * Return: void
 */
void s_hash_table_print(const s_hash_table_t *sorted_ht)
{
	shash_node_t *temporary_node;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (!sorted_ht || !sorted_ht->array)
		return;
	printf("{");
	temporary_node = sorted_ht->s_head;
	while (temporary_node)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", temporary_node->key, temporary_node->value);
		flag = 1;
		temporary_node = temporary_node->s_next;
	}
	printf("}\n");
}

/**
 * s_hash_table_print_rev - prints a sorted hash table in reverse
 * @sorted_ht: hash table to print
 *
 * Return: void
 */
void s_hash_table_print_rev(const s_hash_table_t *sorted_ht)
{
	shash_node_t *temporary_node;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (!sorted_ht || !sorted_ht->array)
		return;
	printf("{");
	temporary_node = sorted_ht->s_tail;
	while (temporary_node)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", temporary_node->key, temporary_node->value);
		flag = 1;
		temporary_node = temporary_node->s_prev;
	}
	printf("}\n");
}

/**
 * s_hash_table_delete - deletes a sorted hash table
 * @sorted_ht: hash table to delete
 *
 * Return: void
 */
void s_hash_table_delete(s_hash_table_t *sorted_ht)
{
	unsigned long int iterator;
	shash_node_t *next_node;

	if (!sorted_ht || !sorted_ht->array || !sorted_ht->size)
		return;
	for (iterator = 0; iterator < sorted_ht->size; iterator++)
	{
		while (sorted_ht->array[iterator])
		{
			next_node = sorted_ht->array[iterator]->next;
			free(sorted_ht->array[iterator]->key);
			free(sorted_ht->array[iterator]->value);
			free(sorted_ht->array[iterator]);
			sorted_ht->array[iterator] = next_node;
		}
	}
	free(sorted_ht->array);
	sorted_ht->array = NULL;
	sorted_ht->s_head = sorted_ht->s_tail = NULL;
	sorted_ht->size = 0;
	free(sorted_ht);
}
