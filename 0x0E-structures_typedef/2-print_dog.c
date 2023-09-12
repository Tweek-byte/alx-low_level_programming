#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints the structure (dog)
 * @d: pointer to (dog)
 *
 * Return: returns (void).
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name == NULL) ? "(nil)" : d->name);
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", (d->owner == NULL) ? "(nil)" : d->owner);
	}
}
