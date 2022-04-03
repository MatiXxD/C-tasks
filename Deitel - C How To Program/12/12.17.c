#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct treeNode {
    struct treeNode* leftPtr;
    char* word;
    struct treeNode* rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;


void insertNode(TreeNodePtr* treePtr, char* word);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);


int main(void) {

    TreeNodePtr rootPtr = NULL;
    char str[256];
    char* word = NULL;
    char* nextWord = NULL;

    printf("Enter your string:\n");
    scanf_s("%[^\n]s", str, 256);

    word = strtok_s(str, " \t\n,", &nextWord);
    while (word != NULL) {

        insertNode(&rootPtr, word);
        word = strtok_s(NULL, " \t\n,", &nextWord);

    }


    printf("\n\nThe preOrder traversal is:\n");
    preOrder(rootPtr);


    printf("\n\nThe inOrder traversal is:\n");
    inOrder(rootPtr);


    printf("\n\nThe postOrder traversal is:\n");
    postOrder(rootPtr);
    printf("\n");


    return 0;
}


void insertNode(TreeNodePtr* treePtr, char* word) {

    if (*treePtr == NULL) {
        *treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));


        if (*treePtr != NULL) {
            (*treePtr)->word = word;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%s not inserted. No memory available.\n", word);
        }
    }
    else {

        if (strcmp(word, (*treePtr)->word) < 0) {
            insertNode(&((*treePtr)->leftPtr), word);
        }
        else {
            insertNode(&((*treePtr)->rightPtr), word);
        }

    }
}


void inOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%s ", treePtr->word);
        inOrder(treePtr->rightPtr);
    }
}


void preOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        printf("%s ", treePtr->word);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}


void postOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%s ", treePtr->word);
    }

}