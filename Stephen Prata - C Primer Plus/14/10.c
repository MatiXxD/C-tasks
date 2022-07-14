#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_SIZE 20
#define PLACE_SIZE 12

typedef void (*V_FP_STPLACE)(struct place[]);


struct place {
	int num;
	bool empty;
	struct {
		char firstname[NAME_SIZE];
		char lastname[NAME_SIZE];
	};
};


void cleanLine(void);
char s_getchar(void);
char* s_gets(char str[], int size);
char getOption(void);
void emptyCount(struct place placeInPlane[]);
void printEmptyPlace(struct place placeInPlane[]);
void printBookedPlace(struct place placeInPlane[]);
int getPlaceNum(void);
void bookPlace(struct place placeInPlane[]);
void removeReserv(struct place placeInPlane[]);
void readData(struct place placeInPlane[], const char* filename);
void writeData(struct place placeInPlane[], const char* filename);
void showMenu(struct place placeInPlane[PLACE_SIZE]);


int main(void) {

	const char* filename = "plane.dat";
	struct place placeInPlane[PLACE_SIZE];

	readData(placeInPlane, filename);
	showMenu(placeInPlane);
	writeData(placeInPlane, filename);

	return 0;

}


void cleanLine(void) {

	while (getchar() != '\n')
		continue;

}

char s_getchar(void) {

	char ch = getchar();
	cleanLine();

	return ch;

}

char* s_gets(char str[], int size) {

	char* retVal = fgets(str, size, stdin);
	if (retVal) {
		char* find = strchr(str, '\n');
		if (find) *find = '\0';
		else cleanLine();
	}

	return retVal;

}

char getOption(void) {

	char option;

	printf("Choose what you want to do:\n");
	printf("a) Show numbers of empty places\nb) Show empty places\n"
		"c) Show list of booked places\nd) Book the place\n"
		"e) Remove reservation\nf) Exit\n");

	option = tolower(s_getchar());
	while (strchr("abcdef", option) == NULL) {
		printf("Wrong input. Try again: ");
		option = tolower(s_getchar());
	}

	return option;

}

void emptyCount(const struct place placeInPlane[]) {

	int count = 0;

	for (int i = 0; i < PLACE_SIZE; i++)
		if (placeInPlane[i].empty) count++;

	printf("Now plane has %d empty places.\n", count);

}

void printEmptyPlace(const struct place placeInPlane[]) {

	for (int i = 0; i < PLACE_SIZE; i++)
		if (placeInPlane[i].empty)
			printf("%d) %s\n", placeInPlane[i].num, "empty");


}

void printBookedPlace(const struct place placeInPlane[]) {

	for (int i = 0; i < PLACE_SIZE; i++)
		if (!placeInPlane[i].empty)
			printf("%d) %s\n", placeInPlane[i].num, "booked");


}

int getPlaceNum(void) {

	int placeNum;

	while (scanf("%d", &placeNum) != 1 || placeNum > PLACE_SIZE || placeNum <= 0) {
		printf("Wrong input. Try again: ");
		cleanLine();
	}
	cleanLine();

	return placeNum;

}

void bookPlace(struct place placeInPlane[]) {

	char tempFirstname[NAME_SIZE];
	char tempLastname[NAME_SIZE];

	printf("Enter number of place you want to book: ");
	int placeNum = getPlaceNum();

	if (placeInPlane[placeNum - 1].empty) {

		printf("Enter your firstname:\n");
		s_gets(tempFirstname, NAME_SIZE);
		printf("Enter your lastname:\n");
		s_gets(tempLastname, NAME_SIZE);

		strcpy(placeInPlane[placeNum - 1].firstname, tempFirstname);
		strcpy(placeInPlane[placeNum - 1].lastname, tempLastname);
		placeInPlane[placeNum - 1].empty = false;

	}
	else {
		printf("Place with number %d already booked.\n", placeNum);
	}

}

void removeReserv(struct place placeInPlane[]) {

	printf("Enter number of place you want to book: ");
	int placeNum = getPlaceNum();

	if (!placeInPlane[placeNum - 1].empty)
		placeInPlane[placeNum - 1].empty = true;
	else
		printf("Place with number %d wasn't booked.\n", placeNum);

}

void readData(struct place placeInPlane[], const char* filename) {

	int i = 0;

	FILE* fin = fopen(filename, "rb");
	if (fin) {
		while (fread(&placeInPlane[i++], sizeof(struct place), 1, fin))
			continue;
		fclose(fin);
	}
	else {
		for (int i = 0; i < PLACE_SIZE; i++) {
			placeInPlane[i].num = i + 1;
			placeInPlane[i].empty = true;
		}
	}

}

void writeData(struct place placeInPlane[], const char* filename) {

	FILE* fout = fopen(filename, "wb");
	if (fout) {
		fwrite(placeInPlane, sizeof(struct place), PLACE_SIZE, fout);
	}
	else printf("File \"%s\" wasn't open.\n", filename);

}

void showMenu(struct place placeInPlane[PLACE_SIZE]) {

	V_FP_STPLACE funcArray[5] = {
		emptyCount,
		printEmptyPlace,
		printBookedPlace,
		bookPlace,
		removeReserv
	};

	char option;

	while ((option = getOption()) != 'f') {
		putchar('\n');
		switch (option) {
		case 'a':	(*funcArray[0])(placeInPlane);
			break;
		case 'b':	(*funcArray[1])(placeInPlane);
			break;
		case 'c':	(*funcArray[2])(placeInPlane);
			break;
		case 'd':	(*funcArray[3])(placeInPlane);
			break;
		case 'e':	(*funcArray[4])(placeInPlane);
			break;
		}
		putchar('\n');
	}

}
