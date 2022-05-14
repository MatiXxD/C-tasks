#include <stdio.h>
#include <ctype.h>

int main(void) {

	char ch;
	unsigned upperCount = 0;
	unsigned lowerCount = 0;
	unsigned othersCount = 0;

	printf("Start your input (use CTRL+Z or CTRL+D to stop):\n");
	while ((ch = getchar()) != EOF) {
		if (!isalpha(ch))
			othersCount++;
		else if (isupper(ch))
			upperCount++;
		else
			lowerCount++;
	}

	printf("Upper count = %d\nLower count = %d\nOthers count = %d\n",
		upperCount, lowerCount, othersCount);

	return 0;

}
