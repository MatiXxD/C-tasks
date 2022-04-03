#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct stackNode {

	char data;
	stackNode* nextPtr;

};

typedef struct stackNode stackNode;
typedef stackNode* stackNodePtr;

void push(stackNodePtr* stack, char ch);
void printStack(stackNodePtr stack);

int main() {

	stackNodePtr stack = NULL;
	char str[128] = "";
	scanf_s("%s", str, 128);

	int size = strlen(str);
	for (int i = 0; i < size; i++)
		push(&stack, str[i]);

	printStack(stack);

	return 0;

}

void push(stackNodePtr* stack, char ch) {

	stackNodePtr newPtr = (stackNodePtr)malloc(sizeof(stackNodePtr));
	if (newPtr != NULL) {

		newPtr->data = ch;
		newPtr->nextPtr = *stack;
		*stack = newPtr;

	}
	else
		puts("No memory available.");
}

void printStack(stackNodePtr stack) {

	while (stack != NULL) {

		printf("%c", stack->data);
		stack = stack->nextPtr;

	}

}