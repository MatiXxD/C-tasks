#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_SIZE 20
#define PLACE_SIZE 12
#define PLANE_COUNT 4


struct place {
	int num;
	bool empty;
	bool confirmed;
	struct {
		char firstname[NAME_SIZE];
		char lastname[NAME_SIZE];
	};
};


void cleanLine(void);
char s_getchar(void);
char* s_gets(char str[], int size);
char getOption(void);
void emptyCount(const struct place placeInPlane[]);
void printPlace(const struct place placeInPlane[], bool status);
int getPlaceNum(void);
void bookPlace(struct place placeInPlane[]);
void removeReserv(struct place placeInPlane[]);
void confirmReserv(struct place placeInPlane[]);
void readData(struct place placeInPlane[], int flight);
void writeData(struct place placeInPlane[], int flight);
int getFlight(void);


int main(void) {

	int flight;
	char option;
	struct place placeInPlanes[PLANE_COUNT][PLACE_SIZE];
	struct place *placeInPlane = NULL;

	while ((flight = getFlight()) != -1) {

		switch (flight) {
		case 102:	placeInPlane = placeInPlanes[0];
					break;
		case 311:	placeInPlane = placeInPlanes[1];
					break;
		case 444:	placeInPlane = placeInPlanes[2];
					break;
		case 519:	placeInPlane = placeInPlanes[3];
					break;
		}

		readData(placeInPlane, flight);
		while ((option = getOption()) != 'g') {
			putchar('\n');
			switch (option) {
			case 'a':	emptyCount(placeInPlane);
						break;
			case 'b':	printPlace(placeInPlane, true);
						break;
			case 'c':	printPlace(placeInPlane, false);
						break;
			case 'd':	bookPlace(placeInPlane);
						break;
			case 'e':	removeReserv(placeInPlane);
						break;
			case 'f':	confirmReserv(placeInPlane);
						break;
			}
			putchar('\n');
		}
		writeData(placeInPlane, flight);
	}

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
		"e) Remove reservation\nf) Comfirm book\ng) Exit\n");

	option = tolower(s_getchar());
	while (strchr("abcdefg", option) == NULL) {
		printf("Wrong input. Try again: ");
		option = tolower(s_getchar());
	}

	return option;

}

void emptyCount(const struct place placeInPlane[]) {

	int count = 0;

	for (int i = 0 ; i < PLACE_SIZE ; i++)
		if (placeInPlane[i].empty) count++;

	printf("Now plane has %d empty places.\n", count);

}

void printPlace(const struct place placeInPlane[], bool status) {

	char* statusStr = status ? "empty" : "booked";

	for (int i = 0; i < PLACE_SIZE; i++) {
		if (status == placeInPlane[i].empty && !strcmp(statusStr, "empty")) {
			printf("%d) %s\n", placeInPlane[i].num, statusStr);
		}
		else if (status == placeInPlane[i].empty && !strcmp(statusStr, "booked")) {
			printf("%d) %s (%s)\n", placeInPlane[i].num, statusStr,
				placeInPlane[i].confirmed ? "confirmed" : "not confirmed");
		}
	}

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

	if (placeInPlane[placeNum-1].empty) {

		printf("Enter your firstname:\n");
		s_gets(tempFirstname, NAME_SIZE);
		printf("Enter your lastname:\n");
		s_gets(tempLastname, NAME_SIZE);

		strcpy(placeInPlane[placeNum-1].firstname, tempFirstname);
		strcpy(placeInPlane[placeNum-1].lastname, tempLastname);
		placeInPlane[placeNum-1].empty = false;
		//placeInPlane[placeNum-1].confirmed = false;

	}
	else {
		printf("Place with number %d already booked.\n", placeNum);
	}

}

void removeReserv(struct place placeInPlane[]) {

	printf("Enter number of place you want to book: ");
	int placeNum = getPlaceNum();

	if (!placeInPlane[placeNum-1].empty && !placeInPlane[placeNum - 1].confirmed) {
		placeInPlane[placeNum-1].empty = true;
		placeInPlane[placeNum-1].confirmed = false;
	}
	else if (placeInPlane[placeNum-1].confirmed)
		printf("Place with number %d was confirmed.\n", placeNum);
	else
		printf("Place with number %d wasn't booked.\n", placeNum);

}

void confirmReserv(struct place placeInPlane[]){

	printf("Enter your place number: ");
	int placeNum = getPlaceNum();

	if (!placeInPlane[placeNum-1].empty) {

		char tempFirstname[NAME_SIZE];
		char tempLastname[NAME_SIZE];

		printf("To confirm your place you need to give some information.\n");
		printf("Enter your firstname: ");
		s_gets(tempFirstname, NAME_SIZE);
		printf("Enter your lastname: ");
		s_gets(tempLastname, NAME_SIZE);

		if (!strcmp(tempFirstname, placeInPlane[placeNum - 1].firstname) &&
			!strcmp(tempLastname, placeInPlane[placeNum - 1].lastname)) {
			printf("You've confirmed your flight!\n");
			placeInPlane[placeNum - 1].confirmed = true;
		}
		else printf("You entered wrong info.\n");

	}
	else printf("Place with number %d wasn't booked.\n", placeNum);

}

void readData(struct place placeInPlane[], int flight) {

	int i = 0;
	char filename[8];
	sprintf(filename, "%d", flight);
	strcat(filename, ".dat");

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
			placeInPlane[i].confirmed = false;
		}
	}

}

void writeData(struct place placeInPlane[], int flight) {

	char filename[8];
	sprintf(filename, "%d", flight);
	strcat(filename, ".dat");

	FILE* fout = fopen(filename, "wb");
	if (fout) {
		fwrite(placeInPlane, sizeof(struct place), PLACE_SIZE, fout);
	}
	else printf("File \"%s\" wasn't open.\n", filename);

}

int getFlight(void) {

	int flightArr[4] = { 102, 311, 444, 519 };
	int flight;

	printf("Enter one of this index:\n1) for %d\n2) for %d\n3) for %d\n4) for %d\n5) to exit\n",
		102, 311, 444, 519);
	while (scanf("%d", &flight) != 1 || flight < 1 || flight > 5) {
		printf("Wrong input. Try again: ");
		cleanLine();
	}
	cleanLine();

	if (flight != 5) return flightArr[flight - 1];
	else return -1;
}
