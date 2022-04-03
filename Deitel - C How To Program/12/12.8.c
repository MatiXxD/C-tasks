#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode {

	int data;
	listNode* nextPtr;

};

typedef struct listNode listNode;
typedef listNode* listNodePtr;


void insertNum(listNodePtr* list, int num);
void printList(listNodePtr list);
void avgAndSum(listNodePtr list);

int main() {

	srand((unsigned int)time(NULL));

	listNodePtr list = NULL;

	for (int i = 0; i < 25; i++)
		insertNum(&list, rand() % 101);

	printList(list);
	avgAndSum(list);

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

	int i = 0;
	while (list != NULL) {

		printf("%d%c", list->data, ++i % 5 != 0 ? ' ' : '\n');
		list = list->nextPtr;

	}

	printf("\n");

}

void avgAndSum(listNodePtr list) {

	long sum = 0;
	int count = 0;
	while (list != NULL) {

		sum += list->data;
		count++;
		list = list->nextPtr;

	}

	printf("Sum of the list is : %ld\nAverage of the list is  : %.2f", sum, ((float)sum) / count);

}