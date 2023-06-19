#ifndef TREE_H
#define TREE_H
#include <string.h>

// �vor stabla sa pokaziva�om na rije� i na djecu �vora
typedef struct Node {
	char* word;
	struct Node* left, * right;
} Node;

// Stablo odnosno pokaziva� na korijen stabla
typedef Node* BSTree;

BSTree NewBSTree();

void AddNode(BSTree* bst, char* word);

int BSTHeight(BSTree bst);

void BSTPrint_Longer_Than(BSTree bst, int n);

int BSTLongest_Word_Int(BSTree bst);

char* BSTLongest_Word_Char(BSTree bst);

void BSTPrint_Leaf(BSTree bst);

void BSTPrint_Knot(BSTree bst);

int BSTLeaf_Int(BSTree bst);

int BSTKnot_Int(BSTree bst);

void BSTAddTo_Leaf(BSTree* bst, char* str);

void BSTDelete_Leafs(BSTree* bst);

void PrintBSTree(BSTree bst);

void SaveBSTree(BSTree bst, FILE* fd);

void DeleteBSTree(BSTree bst);

BSTree LoadBSTree(FILE* fd);

#endif
