#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct treeNode {
    struct treeNode* leftPtr;
    int data;
    struct treeNode* rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;


void insertNode(TreeNodePtr* treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
int depth(TreeNodePtr treePtr, int depth);


int main(void) {
    int i;
    int item;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");


    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    printf("\nDepth of the tree is %d", depth(rootPtr, 1));

    return 0;
}


void insertNode(TreeNodePtr* treePtr, int value) {

    if (*treePtr == NULL) {
        *treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));


        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else {

        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else {
            insertNode(&((*treePtr)->rightPtr), value);
        }

    }
}


void inOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}


void preOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}


void postOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }

}

int depth(TreeNodePtr treePtr, int d) {

    int num1 = 0;
    int num2 = 0;

    if (treePtr != NULL) {

        num1 = depth(treePtr->leftPtr, d + 1);
        num2 = depth(treePtr->rightPtr, d + 1);

    }
    else {

        return --d;

    }


    if (num1 >= num2)
        return num1;
    else
        return num2;

}