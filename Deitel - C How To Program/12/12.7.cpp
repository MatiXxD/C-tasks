#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode {

	int data;
	listNode *nextPtr;

};

typedef struct listNode listNode;
typedef listNode* listNodePtr;


void insertNum(listNodePtr* list, int num);
void printList(listNodePtr list);
void merge(listNodePtr* list1, listNodePtr* list2);

int main() {

	srand((unsigned int)time(NULL));

	listNodePtr firstList = NULL;
	listNodePtr secondList = NULL;

	for (int i = 0; i < 15; i++) {

		insertNum(&firstList, rand() % 15);
		insertNum(&secondList, rand() % 15);

	}

	printList(firstList);
	printList(secondList);
	printf("After: ");
	merge(&firstList, &secondList);
	printList(firstList);

	return 0;

}


void insertNum(listNodePtr* list, int num) {

	listNodePtr newPtr = (listNodePtr)malloc(sizeof(listNode));

	if (newPtr != NULL) {

		listNodePtr currentPtr = *list;
		listNodePtr previousPtr = NULL;

		newPtr->data = num;
		newPtr->nextPtr = NULL;

		while (currentPtr != NULL && currentPtr->data < num) {

			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;

		}

		if (previousPtr == NULL) {

			newPtr->nextPtr = *list;
			*list = newPtr;

		}
		else {

			newPtr->nextPtr = currentPtr;
			previousPtr->nextPtr = newPtr;

		}

	}

}

void printList(listNodePtr list) {

	while (list != NULL) {

		printf("%d ", list->data);
		list = list->nextPtr;

	}

	printf("\n");

}

void merge(listNodePtr* list1, listNodePtr* list2) {

	while (*list2 != NULL) {

		insertNum(list1, (*list2)->data);
		*list2 = (*list2)->nextPtr;

	}

}
