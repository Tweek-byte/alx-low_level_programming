#ifndef _HASH_TABLES_H_
#define _HASH_TABLES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

int hash_table_set(hash_table_t *ht, const char *key, const char *value);
void hash_table_delete(hash_table_t *ht);
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);

/**
 * struct s_hash_node_s - Node of a hash table
 *
 * @key: The key, string
 *
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @s_prev: A pointer to the previous element of the sorted linked list
 * @s_next: A pointer to the next element of the sorted linked list
 */
typedef struct s_hash_node_s
{
	char *key;
	char *value;
	struct s_hash_node_s *next;
	struct s_hash_node_s *s_prev;
	struct s_hash_node_s *s_next;
} shash_node_t;

/**
 * struct s_hash_table - Hash table
 *
 * @size: The size of the array
 * @array: An array of size @size
 *
 * @s_tail: Pointer to the last element in the linked list
 * @s_head: Pointer to the first element in the linked list
 */
typedef struct s_hash_table
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *s_head;
	shash_node_t *s_tail;
} s_hash_table_t;

s_hash_table_t *s_hash_table_create(unsigned long int size);
int s_hash_table_set(s_hash_table_t *htdb, const char *key, const char *value);
char *s_hash_table_get(const s_hash_table_t *sorted_ht, const char *key);
void s_hash_table_print(const s_hash_table_t *sorted_ht);
void s_hash_table_print_rev(const s_hash_table_t *sorted_ht);
void s_hash_table_delete(s_hash_table_t *sorted_ht);

#endif
