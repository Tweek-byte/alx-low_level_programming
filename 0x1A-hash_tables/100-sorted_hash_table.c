#include "hash_tables.h"

/**
 * s_hash_table_create - Allocates memory for a sorted hash table.
 * @size: Size of the hash table.
 *
 * Return: Pointer to the new table, or NULL on failure.
 */
s_hash_table_t *s_hash_table_create(unsigned long int size)
{
	s_hash_table_t *sorted_ht;
	unsigned long int idx;

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
	for (idx = 0; idx < size; idx++)
	{
		sorted_ht->array[idx] = NULL;
	}
	return (sorted_ht);
}

/**
 * make_shash_node - Creates a new node for the sorted hash table.
 * @key: Key for the data.
 * @value: Data to be stored.
 *
 * Return: Pointer to the new node, or NULL on failure.
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
 * add_to_sorted_list - Adds a node to the sorted (by key's ASCII) linked list.
 * @table: The sorted hash table.
 * @sorted_node: The node to add.
 *
 * Return: void.
 */
void add_to_sorted_list(s_hash_table_t *table, shash_node_t *sorted_node)
{
	shash_node_t *current_node;

	if (!table->s_head && !table->s_tail)
	{
		table->s_head = table->s_tail = sorted_node;
		return;
	}
	current_node = table->s_head;
	while (current_node)
	{
		if (strcmp(sorted_node->key, current_node->key) < 0)
		{
			sorted_node->s_next =
				sorted_node->s_next = current_node;
			sorted_node->s_prev = current_node->s_prev;
			current_node->s_prev = sorted_node;
			if (sorted_node->s_prev)
				sorted_node->s_prev->s_next = sorted_node;
			else
				table->s_head = sorted_node;
			return;
		}
		current_node = current_node->s_next;
	}
	sorted_node->s_prev = table->s_tail;
	table->s_tail->s_next = sorted_node;
	table->s_tail = sorted_node;
}

/**
 * s_hash_table_set - Sets a key to a value in the hash table.
 * @htdb: The sorted hash table.
 * @key: The key to the data.
 * @value: The data to add.
 *
 * Return: 1 on success, 0 otherwise.
 */
int s_hash_table_set(s_hash_table_t *htdb, const char *key, const char *value)
{
	unsigned long int hashed_index;
	char *new_value;
	shash_node_t *sorted_node, *current_node;

	if (!htdb || !htdb->array || !htdb->size ||
			!key || !strlen(key) || !value)
		return (0);
	hashed_index = key_index((const unsigned char *)key, htdb->size);
	current_node = htdb->array[hashed_index];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			new_value = strdup(value);
			if (!new_value)
				return (0);
			free(current_node->value);
			current_node->value = new_value;
			return (1);
		}
		current_node = current_node->next;
	}
	sorted_node = make_shash_node(key, value);
	if (!sorted_node)
		return (0);
	sorted_node->next = htdb->array[hashed_index];
	htdb->array[hashed_index] = sorted_node;
	add_to_sorted_list(htdb, sorted_node);
	return (1);
}

/**
 * s_hash_table_get - Retrieve a value from the hash table.
 * @sorted_ht: The hash table.
 * @key: The key to the data.
 *
 * Return: The value associated with key, or NULL on failure.
 */
char *s_hash_table_get(const s_hash_table_t *sorted_ht, const char *key)
{
	unsigned long int hashed_index;
	shash_node_t *current_node;

	if (!sorted_ht || !sorted_ht->array || !sorted_ht->size ||
			!key || !strlen(key))
		return (NULL);
	hashed_index = key_index((const unsigned char *)key, sorted_ht->size);
	current_node = sorted_ht->array[hashed_index];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}

/**
 * s_hash_table_print - Prints a sorted hash table.
 * @sorted_ht: The hash table to print.
 *
 * Return: void.
 */
void s_hash_table_print(const s_hash_table_t *sorted_ht)
{
	shash_node_t *current_node;
	char flag = 0;

	if (!sorted_ht || !sorted_ht->array)
		return;
	printf("{");
	current_node = sorted_ht->s_head;
	while (current_node)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		flag = 1;
		current_node = current_node->s_next;
	}
	printf("}\n");
}

/**
 * s_hash_table_print_rev - Prints a sorted hash table in reverse.
 * @sorted_ht: The hash table to print.
 *
 * Return: void.
 */
void s_hash_table_print_rev(const s_hash_table_t *sorted_ht)
{
	shash_node_t *current_node;
	char flag = 0;

	if (!sorted_ht || !sorted_ht->array)
		return;
	printf("{");
	current_node = sorted_ht->s_tail;
	while (current_node)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		flag = 1;
		current_node = current_node->s_prev;
	}
	printf("}\n");
}

/**
 * s_hash_table_delete - Deletes a sorted hash table.
 * @sorted_ht: The hash table to delete.
 *
 * Return: void.
 */
void s_hash_table_delete(s_hash_table_t *sorted_ht)
{
	unsigned long int i;
	shash_node_t *next_node;

	if (!sorted_ht || !sorted_ht->array || !sorted_ht->size)
		return;
	for (i = 0; i < sorted_ht->size; i++)
	{
		while (sorted_ht->array[i])
		{
			next_node = sorted_ht->array[i]->next;
			free(sorted_ht->array[i]->key);
			free(sorted_ht->array[i]->value);
			free(sorted_ht->array[i]);
			sorted_ht->array[i] = next_node;
		}
	}
	free(sorted_ht->array);
	sorted_ht->array = NULL;
	sorted_ht->s_head = sorted_ht->s_tail = NULL;
	sorted_ht->size = 0;
	free(sorted_ht);
}
