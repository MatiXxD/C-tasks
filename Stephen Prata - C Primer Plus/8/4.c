#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

	char ch;
	bool flag = false;                                                            //Indicate that we start a new word
	unsigned wordsCount = 0;
	unsigned symbolsCount = 0;

	printf("Start your input (use CTRL+Z or CTRL+D to stop):\n");
	while ((ch = getchar()) != EOF) {

		if (ispunct(ch) || ch == ' ' || ch == '\n' || ch == '\t') {
			if(flag)
				wordsCount++;
			flag = false;
		}
		else {
			symbolsCount++;
			flag = true;
		}
	}

	printf("Number of symbols is %u and number of words is %u\n",
		symbolsCount, wordsCount);
	printf("Average number of characters per word is %.2f\n",
		(float)symbolsCount / (float)wordsCount);

	return 0;

}
