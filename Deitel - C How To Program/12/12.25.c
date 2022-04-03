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
void outputTree(TreeNodePtr treePtr, int totalSpaces);


int main(void) {

    srand((unsigned int)time(NULL));

    TreeNodePtr rootPtr = NULL;
    int i;
    int item;

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }
    printf("\n");

    outputTree(rootPtr, 0);

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
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
            printf("dup");
    }
}

void outputTree(TreeNodePtr treePtr, int totalSpaces) {

    while (treePtr != NULL) {

        outputTree(treePtr->rightPtr, totalSpaces + 5);
        for (int i = 0; i < totalSpaces; i++)
            printf(" ");
        printf("%d\n", treePtr->data);
        treePtr = treePtr->leftPtr;
        totalSpaces += 5;

    }

}