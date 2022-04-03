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

typedef struct queueNode {
    TreeNodePtr tree;
    struct queueNode* nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode* QueueNodePtr;


void insertNode(TreeNodePtr* treePtr, int value);
void enqueue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr, TreeNodePtr newTree);
void levelOrder(TreeNodePtr treePtr);


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

    levelOrder(rootPtr);

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

void enqueue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr, TreeNodePtr newTree) {

    QueueNodePtr newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));

    if (newPtr != NULL) {

        newPtr->tree = newTree;
        newPtr->nextPtr = NULL;

        if (*headPtr == NULL)
            *headPtr = newPtr;

        else
            (*tailPtr)->nextPtr = newPtr;

        (*tailPtr) = newPtr;

    }
    else
        puts("Not enough memory");

}

void levelOrder(TreeNodePtr treePtr) {

    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    enqueue(&headPtr, &tailPtr, treePtr);

    while (headPtr != NULL) {

        printf("%3d", headPtr->tree->data);

        if(headPtr->tree->leftPtr != NULL)
            enqueue(&headPtr, &tailPtr, headPtr->tree->leftPtr);
        if(headPtr->tree->rightPtr != NULL)
            enqueue(&headPtr, &tailPtr, headPtr->tree->rightPtr);

        headPtr = headPtr->nextPtr;

    }

}
