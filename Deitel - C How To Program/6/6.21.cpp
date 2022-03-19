#include <stdio.h>
#include <ctype.h>
#define SIZE 11

int getPlace(int places[], int index);
int getIndex(void);
int getAnotherPlace(int places[], int index);
int checkForContinue(int step, int places[]);

int main(void) {

	int id, place;
	int i = 1;
	int places[SIZE] = { 0 };

	while (i <= 10) {

		id = getIndex();
		place = getPlace(places, id);

		if (place)
			printf("Your seat is %d\n", place);

		else {

			place = getAnotherPlace(places, id);

			if (place)
				printf("Your seat is %d\n", place);

			else
				puts("Next flight leaves in 3 hours.\n");

		}

		i = checkForContinue(i, places);

		if (!i) {

			puts("All places are booked");
			i = 1337;

		}

	}

	return 0;

}

int getPlace(int places[], int index) {

	int i = (index == 1) ? 1 : 6;
	int j = (index == 1) ? 6 : 11;

	for (; i < j; i++) 
		if (places[i] == 0) {

			places[i] = 1;
			return i;

		}

	return 0;

}

int getIndex(void) {

	int index = 228;

	printf("%s\n%s\n", "Please type 1 for \"first class\"", "Please type 2 for \"economy\"");
	scanf_s("%d", &index);
	
	while (index != 1 && index != 2) {

		puts("Enter correct value!");
		scanf_s("%d", &index);

	}

	return index;

}

int getAnotherPlace(int places[], int index) {
	
	char answer;
	int place;
	int newIndex = (index == 1) ? 2 : 1;

	printf("%s", index == 2 ? "The economy section is full.\n" : "The first class section is full.\n");
	printf("%s", index == 2 ? "Would you like to sit in first class" : "Would you like to sit in economy class");
	printf(" section ( Y or N )?\n");
	answer = getchar();

	scanf_s("%c", &answer, 1);
	while (toupper(answer) != 'Y' && toupper(answer) != 'N') {

		puts("Input 'Y' for YES and 'N' for NO!");
		scanf_s("%c", &answer, 1);

	}

	if (toupper(answer) == 'Y') {

		place = getPlace(places, newIndex);

		return place;

	}

	else
		return 0;

}

int checkForContinue(int step, int places[]) {

	char answer;
	int i;
	bool check = 0;
	int newStep = 228;

	for(i = 1 ; i < SIZE ; i++)
		if (places[i] == 0) {

			check = 1;
			i = 228;

		}
			
	if (!check)
		return 0;

	puts("Whould you like to continue input? (Y or N)");
	answer = getchar();

	scanf_s("%c", &answer, 1);
	while (toupper(answer) != 'Y' && toupper(answer) != 'N') {

		puts("Input 'Y' for YES and 'N' for NO!");
		scanf_s("%c", &answer, 1);

	}
	
	puts("\n\n-------------------------------------\n\n");

	if (toupper(answer) == 'Y')
		return step;

	else
		return newStep;

}
