/* Open addressing hash */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASHSIZE 10001
#define WORDSIZE 100

struct hash_t {
	const char *name;
	int collision;      
};

static struct hash_t hashtab[HASHSIZE];

size_t hash(const char *name)
{
	size_t hashval = 0;
	while (*name != '\0')
		hashval = (hashval << 5) + *name++;
	return hashval % HASHSIZE;
}

size_t hash_search(const char *key)
{
	int i, j;
	size_t index;

	i = hash(key);
	if (i < 0) {
		printf("i = %d\n", i);
		return -1;
	}
	for (j = 0; j < HASHSIZE; j++) {
		index = (i + j) % HASHSIZE;
		if (hashtab[index].collision > 0 && 
		    strcmp(hashtab[index].name, key) == 0)
			return index;
		else
			break;
	}
	return -1;
}

bool hash_insert(const char *key)
{
	size_t i, j, index;

	j = hash(key);
	for (i = 0; i < HASHSIZE; i++) {
		index = (i + j) % HASHSIZE;
		if (hashtab[index].collision == 0 || 
		    strcmp(hashtab[index].name, key) == 0) {
			hashtab[index].name = key;
			hashtab[index].collision++;
			return true;
		}
	}
	return false;
}

bool hash_delete(const char *key)
{
	size_t i, j, index;

	j = hash(key);
	for (i = 0; i < HASHSIZE; i++) {
		index = (i + j) % HASHSIZE;
		if (strcmp(hashtab[index].name, key) == 0) {
			if (hashtab[index].collision > 0) {
				hashtab[index].collision--;
				return true;
			}
		}
	}
	return false;
}
