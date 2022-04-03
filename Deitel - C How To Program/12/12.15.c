#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct queueNode {
	int time;
	struct queueNode* nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode* QueueNodePtr;


void enqueue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr, int value);
int dequeue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr);
int randTime();
void printQueue(QueueNodePtr headPtr);


int main() {

	srand(time(NULL));

	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;

	const int WORK_TIME = 720;
	int timeInQueue = 0;
	int spawnNewPerson = 0;
	int servePerson = randTime();

	for (int i = 0; i < WORK_TIME; i++) {

		if (!spawnNewPerson) {

			enqueue(&headPtr, &tailPtr, randTime());
			spawnNewPerson = randTime();

		}

		if (!servePerson) {

			if (headPtr != NULL) {

				dequeue(&headPtr, &tailPtr);
				if (headPtr != NULL)
					servePerson = headPtr->time;

			}
			else {

				servePerson = randTime();
				puts("Queue is empty now.");

			}

		}

		spawnNewPerson--;
		if (headPtr != NULL)
			servePerson--;

		printf("%.2d:%.2d\t", i / 60, i % 60);
		printQueue(headPtr);

	}

	return 0;

}

void enqueue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr, int value) {

	QueueNodePtr newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));

	if (newPtr != NULL) {

		newPtr->time = value;
		newPtr->nextPtr = NULL;

		if (*headPtr == NULL)
			*headPtr = newPtr;

		else
			(*tailPtr)->nextPtr = newPtr;

		(*tailPtr) = newPtr;

	}
	else
		puts("Not enough memory");

}

int dequeue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr) {

	int value = (*headPtr)->time;
	QueueNodePtr temp = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
		*tailPtr = NULL;

	free(temp);
	return value;

}

int randTime() {

	return 1 + rand() % 4;

}

void printQueue(QueueNodePtr headPtr) {
	int i = 0;

	while (headPtr != NULL) {

		printf("%d(%s) -> ", headPtr->time, i == 0 ? "serve" : "wait");
		headPtr = headPtr->nextPtr;
		i++;

	}
	printf("END\n");

}