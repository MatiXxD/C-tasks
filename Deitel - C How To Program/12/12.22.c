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
void deleteNode(TreeNodePtr* treePtr, TreeNodePtr parent, int value);


int main(void) {
    int i;
    int item;
    TreeNodePtr rootPtr = NULL;

    srand((unsigned int)time(NULL));
    printf("The numbers being placed in the tree are:\n");


    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }


    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);
    puts("\n--------------------------------------\n\n");

    int dltNum = rand() % 15;
    printf("Should delete value = %d\n", dltNum);
    deleteNode(&rootPtr, NULL, dltNum);

    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);
    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);
    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);

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

void deleteNode(TreeNodePtr* treePtr, TreeNodePtr parent, int value) {

    if (*treePtr == NULL) {

        printf("%d value wasn't found.\n", value);
        return;

    }

    if (value > (*treePtr)->data)
        deleteNode(&((*treePtr)->rightPtr), *treePtr, value);
    else if (value < (*treePtr)->data)
        deleteNode(&((*treePtr)->leftPtr), *treePtr, value);
    else {

        if ((*treePtr)->leftPtr == NULL && (*treePtr)->rightPtr == NULL) {

            if (parent != NULL) {

                if (parent->leftPtr != NULL && parent->leftPtr->data == value)
                    parent->leftPtr = NULL;

                else
                    parent->rightPtr = NULL;

            }

            free(*treePtr);

        }
        else if ((*treePtr)->leftPtr != NULL && (*treePtr)->rightPtr != NULL) {


            TreeNodePtr currentPtr = (*treePtr)->leftPtr;
            TreeNodePtr previousPtr = NULL;

            while (currentPtr != NULL && currentPtr->rightPtr != NULL) {

                previousPtr = currentPtr;
                currentPtr = currentPtr->rightPtr;

            }

            if (previousPtr != NULL)
                previousPtr->rightPtr = currentPtr->leftPtr != NULL ? currentPtr->leftPtr : NULL;
            else
                (*treePtr)->leftPtr = currentPtr->leftPtr != NULL ? currentPtr->leftPtr : NULL;


            (*treePtr)->data = currentPtr->data;
            free(currentPtr);

        }
        else {

            TreeNodePtr temp = NULL;

            if ((*treePtr)->leftPtr != NULL)
                temp = (*treePtr)->leftPtr;
            else
                temp = (*treePtr)->rightPtr;


            (*treePtr)->leftPtr = temp->leftPtr;
            (*treePtr)->rightPtr = temp->rightPtr;
            (*treePtr)->data = temp->data;


            free(temp);

        }


    }

}