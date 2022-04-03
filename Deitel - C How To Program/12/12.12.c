#include <stdio.h>
#include <stdlib.h>

struct stackNode {

	char data;
	stackNode* nextPtr;

};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;


void convertToPostfix(char infix[], char postfix[], int n);
bool isOperator(char c);
int precedence(char operator1, char operator2);
void push(StackNodePtr* topPtr, char value);
char pop(StackNodePtr* topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main() {

	char infix[128];
	char postfix[128];

	int i = 0;
	char ch = 0;
	while ((ch = getchar()) != '\n')
		if (ch != ' ')
			infix[i++] = ch;

	convertToPostfix(infix, postfix, i);

	return 0;

}

void convertToPostfix(char infix[], char postfix[], int n) {

	StackNodePtr topPtr = NULL;
	push(&topPtr, '(');
	infix[n] = ')';

	int i = 0;
	int j = 0;
	char c;
	while (!isEmpty(topPtr)) {

		c = infix[i++];

		if (isOperator(c)) {

			while (isOperator(topPtr->data) && precedence(topPtr->data, c) >= 0)
				postfix[j++] = pop(&topPtr);

			push(&topPtr, c);

		}
		else if (c != '(' && c != ')') {

			postfix[j++] = c;

		}
		else if (c == '(') {

			push(&topPtr, c);

		}
		else {

			while (topPtr->data != '(')
				postfix[j++] = pop(&topPtr);

			pop(&topPtr);

		}

	}

	for (int k = 0; k < i; k++)
		printf("%c ", infix[k]);
	puts("");

	for (int k = 0; k < j; k++)
		printf("%c ", postfix[k]);
	puts("");

}

bool isOperator(char c) {

	switch (c) {

	case '+':
		return true;

	case '-':
		return true;

	case '*':
		return true;

	case '/':
		return true;

	case '^':
		return true;

	case '%':
		return true;

	default:
		return false;

	}

}

int precedence(char operator1, char operator2) {

	char operators[] = "+-*/^%";
	int privileges[] = { 1, 1, 2, 2, 2, 2 };
	int privilege1, privilege2;

	for (int i = 0; i < 6; i++) {

		if (operators[i] == operator1)
			privilege1 = privileges[i];
		if (operators[i] == operator2)
			privilege2 = privileges[i];

	}

	if (privilege1 < privilege2)
		return -1;
	else if (privilege1 == privilege2)
		return 0;
	else
		return 1;

}

void push(StackNodePtr* topPtr, char value) {

	StackNodePtr newPtr = (StackNodePtr)malloc(sizeof(StackNode));
	if (newPtr != NULL) {

		newPtr->data = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;

	}
	else
		puts("No memory available.");
}

char pop(StackNodePtr* topPtr) {

	StackNodePtr temp = *topPtr;
	char popVal = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(temp);

	return popVal;

}

char stackTop(StackNodePtr topPtr) {

	return topPtr->data;

}

int isEmpty(StackNodePtr topPtr) {

	return topPtr == NULL;

}

void printStack(StackNodePtr topPtr) {

	if (topPtr != NULL)
		while (topPtr != NULL) {

			printf("%c ", topPtr->data);
			topPtr = topPtr->nextPtr;

		}
	else
		printf("Stack is empty");

	puts("");

}