#include <stdio.h>

#define SIZE 50

void deletTrash(char str[]);
void delet(char str[], int pos);
bool testPalindrome(char str[], int left, int right);
int strlen(char str[]);

int main(void) {

	bool check;
	char chr;
	char str[SIZE];
	int count = 0;

	puts("Enter string: ");
	while ((chr = getchar()) != '\n' && count < SIZE)
		str[count++] = chr;

	str[count] = '\0';

	deletTrash(str);
	check = testPalindrome(str, 0, strlen(str) - 1);

	if (check)
		puts("String is Palindrome");

	else
		puts("String isn't Palindrome");

	return 0;

}

void deletTrash(char str[]) {

	int i;
	
	for (i = 0; i < SIZE; i++) {

		if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
			delet(str, i--);
			
		else if (str[i] == '\0')
			break;

	}

}

void delet(char str[], int pos) {

	int i;
	int temp;

	for (i = pos; i < SIZE; i++) {
	
		temp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = temp;

		if (str[i] == '\0')
			break;

	}

}

bool testPalindrome(char str[], int left, int right) {

	if (left == right || left > right)
		return 1;

	else if (str[left] != str[right])
		return 0;

	else
		return testPalindrome(str, left + 1, right - 1);

}

int strlen(char str[]) {

	int count = 0;

	while (str[count++] != '\0');

	return count - 1;

}