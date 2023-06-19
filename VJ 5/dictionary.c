#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dictionary create() {
	Dictionary dic = (Word*)malloc(sizeof(Word));
	if (!dic)
		return 0;
	dic->count = 0;
	dic->word = NULL;
	dic->next = NULL;
	return dic;
}

void add(Dictionary dict, char* str) {
	while (dict->next != NULL)
	{
		if (strcmp(str, dict->next->word)>0)
		{
			dict = dict->next;
		}
		else if (strcmp(str, dict->next->word) == 0)
		{
			dict->next->count++;
			return;
		}
		else
		{
			Dictionary temp = (Word*)malloc(sizeof(Word));
			temp->word = _strdup(str);
			temp->count = 1;
			temp->next = dict->next;
			dict->next = temp;
			return;
		}
	}
	if (dict->next == NULL)
	{
		Dictionary temp = (Word*)malloc(sizeof(Word));
		temp->word = _strdup(str);
		temp->count = 1;
		temp->next = dict->next;
		dict->next = temp;
		return;
	}
}

void print(Dictionary dict) {
	dict = dict->next;
	int i = 0;
	while (dict != NULL)
	{
		printf("%s, %d\n", dict->word,dict->count);
		dict = dict->next;
		i++;
	}
	printf("%d\n", i);
}

void destroy(Dictionary dict) {
	Dictionary brisi = dict;
	dict = dict->next;
	free(brisi);
	while (dict!= NULL)
	{
		brisi = dict;
		dict = dict->next;
		free(brisi->word);
		free(brisi);
	}
}

int filter(Word* w) {
	if(strlen(w->word) > 3)
	{
		if (w->count >= 5 && w->count <= 10)
		{
			return 1;
		}
	}
	return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {
	Dictionary p,t;
	p = indict;
	t = indict->next;
	while (t!=NULL)
	{
		if (filter(t))
		{
			p->next = t->next;
			free(t->word);
			free(t);
			t= p->next;
		}
		else
		{
			p = p->next;
			t = t->next;
		}
	}
	return indict;
}
