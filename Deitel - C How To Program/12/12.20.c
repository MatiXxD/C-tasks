#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct listNode {

    int data;
    listNode* nextPtr;

};

typedef struct listNode ListNode;
typedef listNode* ListNodePtr;


void insertNum(ListNodePtr* list, int num);
void printList(ListNodePtr list);
void printListReverse(ListNodePtr list);


int main(void) {

    srand((unsigned int)time(NULL));

    ListNodePtr list = NULL;
    for (int i = 0; i < 15; i++)
        insertNum(&list, rand() % 21);

    printList(list);
    printListReverse(list);
    puts("");

    return 0;
}


void insertNum(ListNodePtr* list, int num) {

    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNode));

    if (newPtr != NULL) {

        ListNodePtr currentPtr = *list;
        ListNodePtr previousPtr = NULL;

        newPtr->data = num;
        newPtr->nextPtr = NULL;

        while (currentPtr != NULL && currentPtr->data < num) {

            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;

        }

        if (previousPtr != NULL) {

            newPtr->nextPtr = currentPtr;
            previousPtr->nextPtr = newPtr;

        }
        else {

            newPtr->nextPtr = *list;
            *list = newPtr;

        }

    }
    else
        puts("Not enough memory!");

}

void printList(ListNodePtr list) {

    while (list != NULL) {

        printf("%3d", list->data);
        list = list->nextPtr;

    }
    printf("\n");

}

void printListReverse(ListNodePtr list) {

    if (list != NULL) {

        printListReverse(list->nextPtr);
        printf("%3d", list->data);

    }
    else
        return;

}