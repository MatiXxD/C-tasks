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
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int searchValue);

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


    TreeNodePtr foundPtr;
    int searchValue;

    printf("Enter number you want to find: ");
    scanf_s("%d", &searchValue);

    foundPtr = binaryTreeSearch(rootPtr, searchValue);
    if (foundPtr != NULL)
        printf("Value %d was found.\n", foundPtr->data);
    else
        printf("Value %d wasn't found.\n", searchValue);

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
        else;
    }
}


TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int searchValue) {

    if (treePtr == NULL)
        return NULL;

    if (searchValue > treePtr->data)
        binaryTreeSearch(treePtr->rightPtr, searchValue);

    else if (searchValue < treePtr->data)
        binaryTreeSearch(treePtr->leftPtr, searchValue);

    else if (searchValue == treePtr->data)
        return treePtr;

}