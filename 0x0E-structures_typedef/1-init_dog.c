#include <stdio.h>
#include "dog.h"

/**
 * init_dog - initialize a variable of type struct (dog)
 * @d: pointer to struct (dog)
 * @name: name in struct dog
 * @age: age in struct dog
 * @owner: owner in struct dog
 *
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
