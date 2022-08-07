#include <stdio.h>
#include <string.h>
#include "tree.h"


static bool toLeft(const Item* item1, const Item* item2);
static bool toRight(const Item* item1, const Item* item2);
static Node* recursiveSearch(Node* node, const Item* item);
static void copyToNode(Node* node, const Item* item);
static Node* makeNode(const Item* item);
static void addNode(Node** node, Node* newNode);
static bool getParent(const Item* item, Node* node, Node** parent);
static void deleteNode(Node** node);
static void deleteNodes(Node* root);
static void addToNode(Node* node, Item* item);
static void deleteFromNode(Node* node, Item* item);
static void printTree(const Node* node);
static bool inNode(const Node* node, Item* item);


void InitTree(Tree* tree) {

	tree->root = NULL;
	tree->size = 0;

}

bool IsEmptyTree(const Tree* tree) {

	return tree->size == 0;

}

bool IsFullTree(const Tree* tree) {

	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
		return true;

	free(temp);
	return false;

}

unsigned TreeSize(const Tree* tree) {

	return tree->size;

}

bool FindInTree(const Tree* tree, const Item* item) {

    Node* findNode = recursiveSearch(tree->root, item);
	if(findNode == NULL) return false;

    for(int i = 0 ; i < (findNode->item).size ; i++)
        if(!strcmp((findNode->item).info.types[i], item->types[0]))
            return true;
    
    return false;

}

bool AddToTree(Item* item, Tree* tree) {

    Node* newNode;
    Node* findNode;

	if (IsFullTree(tree)) {
		fprintf(stderr, "The tree is full.\n");
		return false;
	}

    findNode = recursiveSearch(tree->root, item);
    if(findNode != NULL && (findNode->item).size < 10){
        addToNode(findNode, item);
        tree->size++;
        return true;
    }

	newNode = makeNode(item);
	if (newNode == NULL) {
		fprintf(stderr, "Memory error.\n");
		return false;
	}

	tree->size++;
	if (tree->root == NULL)
		tree->root = newNode;
	else
		addNode(&tree->root, newNode);

	return true;

}

bool DeleteFromTree(Item* item, Tree* tree) {

    Node* parent = NULL;
    Node* child;

	if (IsEmptyTree(tree)) {
		fprintf(stderr, "Tree is empty.\n");
		return false;
	}
    else if ((child = recursiveSearch(tree->root, item)) == NULL || !inNode(child, item)){
        fprintf(stderr, "Item wasn't found in the tree.\n");
        return false;
    }
    getParent(item, tree->root, &parent);
    // UPPER WORK (probably)

    if((child->item).size == 1){
        printf("CHECK\n");
        if (parent == NULL)
            deleteNode(&tree->root);
        else if (parent->left != NULL && !strcmp((parent->left->item).info.petname, item->petname)) 
            deleteNode(&parent->left);
        else
            deleteNode(&parent->right);
    }
    else
        deleteFromNode(child, item);

	tree->size--;

	return true;

}

void EmptyTree(Tree* tree) {

	if (tree != NULL) {
		deleteNodes(tree->root);
		tree->root = NULL;
		tree->size = 0;
	}

}

void PrintPets(const Tree* tree){

    printTree(tree->root);

}




static bool toLeft(const Item* item1, const Item* item2) {

	if(strcmp(item1->petname, item2->petname) < 0) return true;
    else return false;

}

static bool toRight(const Item* item1, const Item* item2) {

	if(strcmp(item1->petname, item2->petname) > 0) return true;
    else return false;

}

static Node* recursiveSearch(Node* node, const Item* item) {

	if(node == NULL) return NULL;
    
    if(!strcmp((node->item).info.petname, item->petname))
        return node;

    if (toLeft(item, &(node->item).info))
		return recursiveSearch(node->left, item);
	else if (toRight(item, &(node->item).info))
		return recursiveSearch(node->right, item);

}

static void copyToNode(Node* node, const Item* item) {

	strcpy((node->item).info.petname, item->petname);
    strcpy((node->item).info.types[0], item->types[0]);

    (node->item).size = 1;

}

static Node* makeNode(const Item* item) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		copyToNode(newNode, item);
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;

}

static void addNode(Node** node, Node* newNode) {

	if (*node == NULL) {
		*node = newNode;
		return;
	}

	if (toLeft(&(newNode->item).info , &((*node)->item).info))
		addNode(&(*node)->left, newNode);
	else if (toRight(&(newNode->item).info, &((*node)->item).info))
		addNode(&(*node)->right, newNode);

}

static bool getParent(const Item* item, Node* node, Node** parent) {

	if (node == NULL)
        return false;
	else if (!strcmp((node->item).info.petname, item->petname))
        return true;
        

	if (toLeft(item, &(node->item).info)) {
		*parent = node;
		return getParent(item, node->left, parent);
	}
	else if (toRight(item, &(node->item).info)) {
		*parent = node;
		return getParent(item, node->right, parent);
	}
	else {
		fprintf(stderr, "Location error.\n");
		return false;
	}
	
}

static void deleteNode(Node** node) {

	Node* temp;
    
	// Only left side
	if ((*node)->right == NULL) {
		temp = *node;
		*node = (*node)->left;
		free(temp);
	}
	
	// Only right side
	else if ((*node)->left == NULL) {
		temp = *node;
		*node = (*node)->right;
		free(temp);
	}

	// Both sides
	else {
		for (temp = (*node)->left; temp->right != NULL; )
			temp = temp->right;
		temp->right = (*node)->right;
		temp = *node;
		*node = (*node)->left;
		free(temp);
	}

}

static void deleteNodes(Node* root) {

	if (root != NULL) {
		Node* temp = root->right;
		deleteNodes(root->left);
		free(root);
		deleteNodes(temp);
	}

}

static void addToNode(Node* node, Item* item){

    strcpy((node->item).info.types[(node->item).size], item->types[0]);
    (node->item).size++;

}

static void deleteFromNode(Node* node, Item* item){

    int ind;

    for(int i = 0 ; i < (node->item).size ; i++)
        if(!strcmp((node->item).info.types[i], (item->types)[0])){
            ind = i;
            break;
        }
    
    for(int i = ind ; i < (node->item).size - 1 ; i++)
        strcpy((node->item).info.types[i], (node->item).info.types[i+1]);

    (node->item).size--;

}

static void printTree(const Node* node){

    if(node == NULL) return;

    printTree(node->left);
    for(int i = 0 ; i < (node->item).size ; i++)
        printf("%s %s\n", (node->item).info.petname, (node->item).info.types[i]);
    printTree(node->right);

}

static bool inNode(const Node* node, Item* item){

    for(int i = 0 ; i < (node->item).size ; i++)
        if(!strcmp((node->item).info.types[i], item->types[0]))
            return true;

    return false;

}