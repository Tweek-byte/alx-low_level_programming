#include "hash_tables.h"

/**
 * new_hash_node - new hash node
 * @k: key to insert
 * @v: value to insert
 *
 * Return: pointer to the node
 */
hash_node_t *new_hash_node(const char *k, const char *v)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(k);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(v);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}


/**
 * hash_table_set - adds an element to the hash table.
 *
 * @key: is the key.
 * @value: data to store
 * @ht: hash table to add key/value to
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *new_v;
	unsigned long int index;
	hash_node_t *hash_node, *t;

	if (!ht || !value || !key || !ht->array
	|| ht->size == 0  || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	t = ht->array[index];
	while (t != NULL)
	{
		if (strcmp(t->key, key) == 0)
		{
			new_v = strdup(value);
			if (new_v == NULL)
				return (0);
			free(t->value);
			t->value = new_v;
			return (1);
		}
		t = t->next;
	}

	hash_node = new_hash_node(key, value);
	if (!hash_node)
		return (0);

	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}
