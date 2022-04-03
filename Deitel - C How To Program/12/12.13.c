#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct stackNode {

	int data;
	stackNode* nextPtr;

};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;


int evaluatePostfixExpression(char* exp, int* i);
int calculate(int op1, int op2, char operatr);
void push(StackNodePtr* topPtr, int value);
int pop(StackNodePtr* topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main() {

	char exp[128];
	int result;

	int i = 0;
	char ch = 0;
	while ((ch = getchar()) != '\n')
		if (ch != ' ')
			exp[i++] = ch;

	result = evaluatePostfixExpression(exp, &i);
	if (result != -1 && i != 1337)
		printf("Result = %d", result);

	return 0;

}

int evaluatePostfixExpression(char* exp, int* i) {

	int value = 0;
	int x, y;
	StackNodePtr topPtr = NULL;

	exp[*i] = '\0';
	while (*exp) {

		value = *exp - '0';

		if (value >= 0 && value < 10) {

			push(&topPtr, value);

		}
		else {

			x = pop(&topPtr);
			y = pop(&topPtr);

			push(&topPtr, calculate(y, x, *exp));

		}

		exp++;

	}

	if (topPtr != NULL)
		return topPtr->data;
	else {

		*i = 1337;
		return -1;

	}

}

int calculate(int op1, int op2, char operatr) {

	switch (operatr) {

	case '+':
		return op1 + op2;

	case '-':
		return op1 - op2;

	case '*':
		return op1 * op2;

	case '/':
		if (op2 != 0)
			return op1 / op2;
		else
			return -1;

	case '^':
		return (int)pow(op1, op2);

	case '%':
		return op1 % op2;

	default:
		return -101;

	}

}

void push(StackNodePtr* topPtr, int value) {

	StackNodePtr newPtr = (StackNodePtr)malloc(sizeof(StackNode));
	if (newPtr != NULL) {

		newPtr->data = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;

	}
	else
		puts("No memory available.");

}

int pop(StackNodePtr* topPtr) {


	StackNodePtr temp = *topPtr;
	int value = (*topPtr)->data;

	*topPtr = (*topPtr)->nextPtr;
	free(temp);

	return value;

}

int isEmpty(StackNodePtr topPtr) {

	return topPtr == NULL;

}

void printStack(StackNodePtr topPtr) {

	if (topPtr != NULL)
		while (topPtr != NULL) {

			printf("%d", topPtr->data);
			topPtr = topPtr->nextPtr;

		}

	else
		puts("The stack is empty");

}