
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "bstree.h"

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	int wc;
	FILE* fd;
	char buffer[1024];
	BSTree bst;
	bst = NewBSTree();

	// Kreiraj stablo
	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	wc = 0;
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		AddNode(&bst, _strdup(buffer));
		wc++;
	}

	fclose(fd);

	// Ispiši stablo, visinu i broj èvorova
	PrintBSTree(bst);

	printf("\nH = %d, N = %d\n", BSTHeight(bst), wc);

	// Snimi i izbriši
	if ((fd = fopen("stablo.txt", "wt")) == NULL)
	{
		printf("Error opening file for writing.\n");
		return;
	}
	SaveBSTree(bst, fd);
	fclose(fd);

	DeleteBSTree(bst);

	// Uèitaj stablo
	if ((fd = fopen("stablo.txt", "rt")) == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	bst = LoadBSTree(fd);
	fclose(fd);

	// Ispiši visinu i izbriši
	printf("\nH = %d\n", BSTHeight(bst));

	BSTPrint_Longer_Than(bst, 8);

	printf("\n");

	printf("Longset word: %d \n", BSTLongest_Word_Int(bst));

	printf("Longset word: %s \n", BSTLongest_Word_Char(bst));

	printf("Number of leafs: %d \n", BSTLeaf_Int(bst));

	BSTPrint_Leaf(bst);
	
	printf("\n");

	printf("Number of knots: %d \n", BSTKnot_Int(bst));

	BSTPrint_Knot(bst);

	printf("\n");

	BSTAddTo_Leaf(&bst, "KRAJ");

	PrintBSTree(bst);

	printf("\n");

	BSTDelete_Leafs(&bst);

	printf("Number of leafs: %d \n", BSTLeaf_Int(bst));

	BSTPrint_Leaf(bst);

	printf("\n");

	DeleteBSTree(bst);

}