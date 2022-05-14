#include <stdio.h>
#include <ctype.h>

int getAnswer(void);
void skip(void);

int main(void) {

	int max = 101;
	int min = 0;
	int guess = 50;
	int answer;

	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\nh if higher and l if lower.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((answer = getAnswer()) != 'y') {

		if (answer == 'h') {
			min = guess;
			guess += (max - min) / 2;
		}
		else {
			max = guess;
			guess -= (max - min) / 2;
		}

		printf("Well, then, is it %d?\n", guess);

	}
	printf("I knew I could do it!\n");

	return 0;

}


int getAnswer(void) {

	int answer;

	answer = tolower(getchar());
	skip();
	while (answer != 'h' && answer != 'l' && answer != 'y') {

		printf("Wrong input. Try angain:\n");
		answer = tolower(getchar());
		skip();

	}

	return answer;

}


void skip(void) {

	while (getchar() != '\n') continue;

}
