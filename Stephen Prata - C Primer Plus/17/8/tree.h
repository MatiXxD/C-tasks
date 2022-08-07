#ifndef _TREE_H_
#define _TREE_H_
#include <stdlib.h>
#include <stdbool.h>


// Define Item, Node and Tree
typedef struct item{
    char petname[20];
    char types[10][20];
}Item;
typedef struct nodeItem{
    Item info;
    unsigned size;
}NodeItem;

typedef struct treeNode {
	struct treeNode* left;
	NodeItem item;
	struct treeNode* right;
} Node;

typedef struct tree {
	Node* root;
	unsigned size;
} Tree;


// Initialize tree
void InitTree(Tree* tree);

// Check if tree is empty
bool IsEmptyTree(const Tree* tree);

// Check if tree is full
bool IsFullTree(const Tree* tree);

// Return size of the tree
unsigned TreeSize(const Tree* tree);

// Find item in the tree
bool FindInTree(const Tree* tree, const Item* item);

// Add item to the tree
bool AddToTree(Item* item, Tree* tree);

// Delete item from the tree
bool DeleteFromTree(Item* item, Tree* tree);

// Empty tree
void EmptyTree(Tree* tree);

// Print list of pets
void PrintPets(const Tree* tree);

#endif