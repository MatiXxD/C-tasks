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
ListNodePtr searchInList(ListNodePtr list, int searchNum);


int main(void) {

    srand((unsigned int)time(NULL));

    ListNodePtr list = NULL;
    for (int i = 0; i < 20; i++)
        insertNum(&list, rand() % 101);

    //printList(list);
    //puts("");

    int num = 0;
    ListNodePtr searchPtr;

    printf("Enter number you want to find (from 0 to 100 and -1 to exit): ");
    scanf_s("%d", &num);
    while (num != -1) {

        searchPtr = searchInList(list, num);
        if (searchPtr != NULL)
            printf("Number %d was found in the list\n", searchPtr->data);
        else
            printf("Number %d wasn't found in the list\n", num);

        printf("Enter number you want to find (from 0 to 100 and -1 to exit): ");
        scanf_s("%d", &num);

    }

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

ListNodePtr searchInList(ListNodePtr list, int searchNum) {

    if (list != NULL) {

        if (list->data != searchNum)
            searchInList(list->nextPtr, searchNum);

        else
            return list;

    }
    else {

        return NULL;

    }

}