#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode {

	char data;
	listNode* nextPtr;

};

typedef struct listNode listNode;
typedef listNode* listNodePtr;


void insertNum(listNodePtr* list, char num);
void printList(listNodePtr list);
void reverse(listNodePtr list);

int main() {

	srand((unsigned int)time(NULL));

	listNodePtr list = NULL;
	char words[] = "qwertyuiopasdfghjklzxcvbnm!@#$%^&*";

	for (int i = 0; i < 10; i++)
		insertNum(&list, words[rand() % 35]);

	printList(list);
	reverse(list);
	;
	return 0;

}


void insertNum(listNodePtr* list, char num) {

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

		printf("%c ", list->data);
		list = list->nextPtr;

	}

	printf("\n");

}

void reverse(listNodePtr list) {

	int i = 0;
	char arr[10] = { 0 };

	while (list != NULL) {

		arr[i++] = list->data;
		list = list->nextPtr;

	}

	for (int i = 0; i < 10; i++)
		printf("%c ", arr[10 - 1 - i]);

}