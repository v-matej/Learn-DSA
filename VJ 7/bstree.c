#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if (*bst == NULL)
	{
		BSTree novi = (BSTree)malloc(sizeof(Node));
		novi->word = word;
		novi->left = NULL;
		novi->right = NULL;
		*bst = novi;
		return;
	}
	if (strcmp((*bst)->word, word) == 0)
	{
		free(word);
		return 0;
	}
	if(strcmp((*bst)->word,word)<0)
		AddNode(&((*bst)->left), word);
	else
		AddNode(&((*bst)->right), word);

}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if(bst==NULL)
		return 0;
	else
	{
		int lMax = BSTHeight(bst->left);
		int rMax = BSTHeight(bst->right);
		if (lMax > rMax)
			return (lMax + 1);
		else
			return (rMax + 1);
	}
}

void BSTPrint_Longer_Than(BSTree bst, int n)
{
	if (bst == NULL)
		return;
	if (strlen(bst->word) > n)
	{
		printf("%s ", bst->word);
	}
	BSTPrint_Longer_Than(bst->left,n);
	BSTPrint_Longer_Than(bst->right,n);
}

int BSTLongest_Word_Int(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
		return 0;
	
	int lw = BSTLongest_Word_Int(bst->left);
	int rw = BSTLongest_Word_Int(bst->right);
	if (lw >= strlen(bst->word) && lw >= rw)
		return lw;
	if (rw >= strlen(bst->word) && lw <= rw)
		return rw;

	return strlen(bst->word);
}

char* BSTLongest_Word_Char(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
		return "";

	char* lw = BSTLongest_Word_Char(bst->left);
	char* rw = BSTLongest_Word_Char(bst->right);
	if (strlen(lw) >= strlen(bst->word) && strlen(lw) >= strlen(rw))
		return lw;
	if (strlen(rw) >= strlen(bst->word) && strlen(lw) <= strlen(rw))
		return rw;

	return bst->word;
}

void BSTPrint_Leaf(BSTree bst)
{
	if (bst == NULL)
		return;
	if (bst->left == NULL && bst->right == NULL)
	{
		printf("%s ", bst->word);
	}
	BSTPrint_Leaf(bst->left);
	BSTPrint_Leaf(bst->right);
}

void BSTPrint_Knot(BSTree bst)
{
	if (bst == NULL)
		return;
	if (bst->left != NULL && bst->right != NULL)
	{
		printf("%s ", bst->word);
	}
	else if(bst->left != NULL && bst->right == NULL)
	{
		printf("%s ", bst->word);
	}
	else if (bst->left == NULL && bst->right != NULL)
	{
		printf("%s ", bst->word);
	}
	BSTPrint_Knot(bst->left);
	BSTPrint_Knot(bst->right);
}

int BSTLeaf_Int(BSTree bst)
{
	if (bst == NULL)
		return 0;
	if (bst->left == NULL && bst->right == NULL)
	{
		return 1;
	}
	return BSTLeaf_Int(bst->left) + BSTLeaf_Int(bst->right);
}

int BSTKnot_Int(BSTree bst)
{
	if (bst == NULL)
		return 0;
	else if (bst->left == NULL && bst->right == NULL)
	{
		return 0+BSTKnot_Int(bst->left) + BSTKnot_Int(bst->right);
	}
	else
		return 1 + BSTKnot_Int(bst->left) + BSTKnot_Int(bst->right);
}

void BSTAddTo_Leaf(BSTree *bst,char* str)
{
	if ((*bst) == NULL)
		return;
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		Node* novi = (Node*)malloc(sizeof(Node));
		novi->word = _strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->left = novi;
		novi = (Node*)malloc(sizeof(Node));
		novi->word = _strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->right = novi;
		return;
	}
	BSTAddTo_Leaf(&((*bst)->left),str);
	BSTAddTo_Leaf(&((*bst)->right),str);
}

void BSTDelete_Leafs(BSTree* bst)
{
	if ((*bst) == NULL)
	{
		return;
	}
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		free((*bst)->word);
		free((*bst));
		*bst = NULL;
		return;
	}
	BSTDelete_Leafs(&((*bst)->left));
	BSTDelete_Leafs(&((*bst)->right));
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
	if (bst == NULL)
		return;
	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if (bst == NULL)
		return;
	fprintf(fd,"%s ",bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	if (bst == NULL){
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE* fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().
	BSTree novi=NewBSTree();
	char buffer[1024];
	while(fscanf(fd, "%s", buffer)>0)
		AddNode(&novi, _strdup(buffer));
	return novi;
}

