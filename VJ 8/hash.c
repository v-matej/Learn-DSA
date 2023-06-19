#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable* novi = (HashTable*)malloc(sizeof(HashTable));
	novi->table = (Bin**)calloc(size,sizeof(Bin*));
	novi->size = size;
	novi->load = 0;
	return novi;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}


void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int key = hash(word)%ht->size;
	Bin* novi = (Bin*)malloc(sizeof(Bin));
	novi->word = word;
	novi->next = ht->table[key];
	ht->table[key] = novi;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int key = hash(word)%ht->size;
	Bin* temp=ht->table[key];
	while (temp != NULL)
	{
		if (strcmp(temp->word, word) == 0)
			return 1;
		temp = temp->next;
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	int i=0;
	for(i;i<ht->size;i++)
	{
		Bin* b;
		Bin *t = ht->table[i];
		while (t!=NULL)
		{
			b = t;
			t = t->next;
			free(b->word);
			free(b);
		}
	}
	free(ht->table);
	free(ht);
}