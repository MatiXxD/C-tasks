#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define MOVE_COUNT 4
#define MAX_PLAYERS 19


struct player {

	int index;
	struct {
		char firstname[NAME_SIZE];
		char lastname[NAME_SIZE];
	};
	int moveInfo[MOVE_COUNT];
	float avgAch;

};


void cleanLine(void);
char* s_gets(char str[], int size);
void initPlayers(struct player players[], int size);
void readFile(FILE* fin, struct player players[], int size);
void printResult(struct player players[], int size);


int main(void) {

	int count;
	const char* fileName = "file";
	struct player players[MAX_PLAYERS];

	FILE* finPtr;
	finPtr = fopen(fileName, "r");
	if (finPtr == NULL) {
		printf("Can't open file with name %s.\n", fileName);
		exit(EXIT_FAILURE);
	}

	initPlayers(players, MAX_PLAYERS);
	readFile(finPtr, players, MAX_PLAYERS);
	printResult(players, MAX_PLAYERS);

	fclose(finPtr);

	return 0;

}


void cleanLine(void) {

	while (getchar() != '\n')
		continue;

}

char* s_gets(char str[], int size) {

	char* retVal = fgets(str, size, stdin);
	if (retVal) {
		char* find = strchr(str, '\n');
		if (find)	*find = '\0';
		else		cleanLine();
	}

}

void initPlayers(struct player players[], int size) {

	for (int i = 0; i < size; i++)
		players[i].index = -1;

}

void readFile(FILE* fin, struct player players[], int size) {

	int check;
	int tempInd;
	int tempArr[MOVE_COUNT];
	char tempFirstname[NAME_SIZE] = "";
	char tempLastname[NAME_SIZE] = "";

	int i = 0;
	while(i < size) {

		check = fscanf(fin, "%d%s%s%d%d%d%d", &tempInd, tempFirstname, tempLastname,
			&tempArr[0], &tempArr[1], &tempArr[2], &tempArr[3]);
		if (check == 7) {
			players[i].index = tempInd;
			strcpy(players[i].firstname, tempFirstname);
			strcpy(players[i].lastname, tempFirstname);
			for (int j = 0; j < MOVE_COUNT; j++) {
				players[i].moveInfo[j] = tempArr[j];
			}
			players[i].avgAch = ((float)players[i].moveInfo[1]) / players[i].moveInfo[2];
			i++;
		}
		else if(check == EOF) break;

	}

}

void printResult(struct player players[], int size) {

	int i = 0;
	float totalArr[MOVE_COUNT + 1] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

	printf("%20s%16s%6s\n", "Name", "Points", "Avg");
	while (i < size && players[i].index != -1) {
		printf("%10s%10s%4d%4d%4d%4d%6.2f\n", players[i].firstname, players[i].lastname,
			players[i].moveInfo[0], players[i].moveInfo[1], players[i].moveInfo[2],
			players[i].moveInfo[3], players[i].avgAch);
		for (int j = 0; j < MOVE_COUNT; j++)
			totalArr[j] += (float)players[i].moveInfo[j];
		totalArr[MOVE_COUNT] += players[i].avgAch;
		i++;
	}
	printf("Average statistics:\n");
	printf("%20s%4.1f%4.1f%4.1f%4.1f%6.2f\n", "", totalArr[0] / i, totalArr[1] / i,
		totalArr[2] / i, totalArr[3] / i, totalArr[4] / i);

}
