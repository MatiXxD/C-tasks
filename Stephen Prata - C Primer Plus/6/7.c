#include <stdio.h>
#include <string.h>


int main(void) {

	const int SIZE = 128;
	char str[SIZE] = "";

	printf("Enter your string: ");
	scanf_s("%s", str, SIZE);

	printf("Reversed string: ");
	for (int i = strlen(str) - 1; i >= 0; i--)
		printf("%c", str[i]);

	return 0;

}
