#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void cleanBuffer();
void printWords(char** wordsArr, int wordsCount);
void cleanArray(char** wordsArr, int wordsCount);

int main(void) {

	int wordsCount = 1;
	char** wordsArr;

	printf("Enter how much word you want to enter: ");
	scanf("%d", &wordsCount);
	cleanBuffer();
	wordsArr = (char**)malloc(wordsCount * sizeof(char*));

	if (wordsArr) {
		printf("Now enter %d words:\n", wordsCount);
		for (int i = 0; i < wordsCount; i++) {
			char temp[MAX_SIZE];
			temp[0] = '\0';
			if (scanf("%s", temp) == 1) {
				wordsArr[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
				strncpy(wordsArr[i], temp, (strlen(temp) + 1));
			}
		}

		printWords(wordsArr, wordsCount);
		cleanArray(wordsArr, wordsCount);
	}

	return 0;

}

void cleanBuffer() {

	while (getchar() != '\n') continue;

}

void printWords(char** wordsArr, int wordsCount) {

	puts("Here are the words you entered:");
	for (int i = 0; i < wordsCount; i++)
		puts(wordsArr[i]);

}

void cleanArray(char** wordsArr, int wordsCount) {

	for (int i = 0; i < wordsCount; i++)
		free(wordsArr[i]);
	free(wordsArr);

}