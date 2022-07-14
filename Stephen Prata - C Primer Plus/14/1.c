#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_SIZE 15


struct month{
	char name[NAME_SIZE];
	char abrv[4];
	int days;
	int monthNum;
};

const struct month months[12] = {
	{"January",		"jan", 31, 1},
	{"February",	"feb", 28, 2},
	{"March",		"mar", 31, 3},
	{"April",		"apr", 30, 4},
	{"May",			"may", 31, 5},
	{"June",		"jun", 30, 6},
	{"July",		"jul", 31, 7},
	{"August",		"aug", 31, 8},
	{"September",	"sep", 30, 9},
	{"October",		"oct", 31, 10},
	{"November",	"nov", 30, 11},
	{"December",	"dec", 31, 12},
};


void cleanLine();
char* s_gets(char name[], int size);
int getDays(char name[]);


int main(void) {

	int days;
	char name[NAME_SIZE];

	printf("Enter month name: ");
	while (s_gets(name, NAME_SIZE) != NULL && name[0] != '\0') {
		days = getDays(name);
		if (days != -1)
			printf("Days count for month %s : %d\n", name, days);
		else
			printf("Month with name %s wasn't found\n", name);
		printf("Enter next month's name (empty line to stop): ");
	}

	return 0;

}


void cleanLine() {

	while (getchar() != '\n')
		continue;

}

char* s_gets(char name[], int size) {

	char* retVal = fgets(name, size, stdin);
	if (retVal) {
		char* find = strchr(name, '\n');
		if (find)
			*find = '\0';
		else
			cleanLine();
	}

	return retVal;

}

int getDays(char name[]) {

	int total = 0;
	bool flag = false;

	name[0] = toupper(name[0]);
	for (int i = 1; i < strlen(name); i++)
		name[i] = tolower(name[i]);

	for (int i = 0; i < 12; i++) {
		total += months[i].days;
		if (!strcmp(name, months[i].name)) {
			flag = true;
			break;
		}
	}

	return flag ? total : -1;

}
