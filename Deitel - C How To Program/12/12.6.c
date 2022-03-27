#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode {

	char ch;
	listNode* nextPtr;

};

typedef struct listNode listNode;
typedef listNode* listNodePtr;


void fillList(listNodePtr* list);
void printList(listNodePtr list);
void concatenate(listNodePtr* firstList, listNodePtr* secondList);

int main() {

	srand((unsigned int)time(NULL));

	listNodePtr firstList = NULL;
	listNodePtr secondList = NULL;

	fillList(&firstList);
	fillList(&secondList);
	printList(firstList);
	printList(secondList);
	concatenate(&firstList, &secondList);
	printList(firstList);

	return 0;

}


void fillList(listNodePtr* list) {

	char newCh;
	listNodePtr newPtr;
	listNodePtr mainList = (listNodePtr)malloc(sizeof(listNode));					//To save start of the list

	for (int i = 0; i < 10; i++) {

		newCh = 65 + rand() % 26;
		newPtr = (listNodePtr)malloc(sizeof(listNode));
		if (newPtr == NULL)
			return;

		newPtr->ch = newCh;
		newPtr->nextPtr = NULL;

		if (*list != NULL) {
			(*list)->nextPtr = newPtr;
			(*list) = newPtr;														//Move position of the list
		}
		else {
			*list = newPtr;
			mainList = *list;
		}

	}

	*list = mainList;

}

void printList(listNodePtr list) {

	while (list != NULL) {

		printf("%c", list->ch);
		list = list->nextPtr;

	}

	printf("\n");

}

void concatenate(listNodePtr* firstList, listNodePtr* secondList) {

	listNodePtr start = *firstList;												//Save start position of the first list 

	while ((*firstList)->nextPtr != NULL)
		*firstList = (*firstList)->nextPtr;
	(*firstList)->nextPtr = *secondList;

	*firstList = start;

}