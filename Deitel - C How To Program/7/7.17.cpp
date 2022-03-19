#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIST 70

void makeTrack(char track[]);
bool move(char track[], int* posH, int* posT);
int chooseMove(int num, char id);
void printTrack(char track[]);
bool checkWinner(int* const posH, int* const posT);

int main(void) {

	int posH, posT;
	char track[DIST + 20];

	makeTrack(track);

	puts("BANG !!!!!\nAND THE'RE OFF !!!!!");

	srand((unsigned int)time(NULL));
	posH = posT = 0;
	while (move(track, &posH, &posT));

	return 0;

}

void makeTrack(char track[]) {

	int i;

	track[0] = 'S';
	track[DIST - 1] = 'F';

	for (i = 1; i < DIST - 1; i++)
		track[i] = (i % 10 != 0) ? '.' : '|';
	
}

bool move(char track[], int* posH, int* posT) {

	bool check;
	int skip;

	int iH, iT;
	int tempPosH, tempPosT;

	iH = 1 + rand() % 10;
	iT = 1 + rand() % 10;

	tempPosH = *posH;
	tempPosT = *posT;

	*posH += chooseMove(iH, 'H');
	if (*posH < 0)
		*posH = 0;

	*posT += chooseMove(iT, 'T');
	if (*posT < 0)
		*posT = 0;

	if (track[*posH] != 'S' && track[*posH] != 'F') 
		track[*posH] = 'H';
	if (track[tempPosH] != 'S' && track[tempPosH] != 'F' && tempPosH != *posH)
		track[tempPosH] = tempPosH % 10 == 0 ? '|' : '.';

	

	if (track[*posT] != 'S' && track[*posT] != 'F') 
		track[*posT] = 'T';
	if (track[tempPosT] != 'S' && track[tempPosT] != 'F' && tempPosT != *posT)
		track[tempPosT] = tempPosT % 10 == 0 ? '|' : '.';


	if (*posH == *posT && *posH != 0 && *posT != 0 && *posH != DIST - 1 && *posT != DIST - 1) {

		puts("OUCH\n");
		track[*posT] = 'O';

	}

	printTrack(track);
	printf("\n\nH = %d\nT = %d\n\n", *posH, *posT);
	check = checkWinner(posH, posT);

	puts("\nPRESS ANY BUTTON TO CONTINUE\n");
	skip = getchar();

	return check;

}

int chooseMove(int num, char id) {

	if (id == 'T')
		switch (num) {

		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return 3;

		case 6:
		case 7:
			return -6;

		case 8:
		case 9:
		case 10:
			return 1;

		}

	else 
		switch (num) {

		case 1:
		case 2:
			return 0;

		case 3:
		case 4:
			return 9;

		case 5:
			return -12;

		case 6:
		case 7:
		case 8:
			return 1;

		case 9:
		case 10:
			return -2;

		}

	return -1;

}

void printTrack(char track[]) {

	int i;

	for (i = 0; i < DIST; i++)
		printf("%c", track[i]);

	puts("\n\n");
}

bool checkWinner(int* const posH, int* const posT) {

	if (*posH > DIST - 1 && *posT < DIST - 1) {

		puts("Hare wins. Yuch.");
		return 0;

	}

	else if (*posH < DIST - 1 && *posT > DIST - 1) {

		puts("TORTOISE WINS!!! YAY!!!");
		return 0;

	}

	else if (*posH > DIST - 1 && *posT > DIST - 1) {

		puts("DRAW!");
		return 0;

	}

	else
		return 1;

}