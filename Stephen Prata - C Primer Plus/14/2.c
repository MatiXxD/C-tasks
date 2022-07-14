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
int getDays(char monthName[]);
int monthNum(char monthName[]);


int main(void) {

	int total;
	int days, years;
	char monthName[NAME_SIZE];

	printf("Enter month name: ");
	while (s_gets(monthName, NAME_SIZE) != NULL && monthName[0] != '\0') {

		printf("Now enter number of years and days: ");
		scanf_s("%d %d", &years, &days);
		cleanLine();

		if (days <= 31 && days >= 0) {
			total = getDays(monthName);
			if (total != -1) {
				for (int i = 1; i <= years; i++)
					total += i % 4 ? 365 : 366;
				total += days;
				printf("%02d:%02d:%d has %d days\n", days,
					monthNum(monthName), years, total);
			}
			else puts("Wrong month name.");
		}
		else puts("Wrong value for days.");

		printf("Enter month name (empty line to stop): ");

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

int getDays(char monthName[]) {

	int total = 0;
	bool flag = false;

	monthName[0] = toupper(monthName[0]);
	for (int i = 1; i < strlen(monthName); i++)
		monthName[i] = tolower(monthName[i]);

	for (int i = 0; i < 12; i++) {
		if (!strcmp(monthName, months[i].name)) {
			flag = true;
			break;
		}
		total += months[i].days;
	}

	return flag ? total : -1;

}

int monthNum(char monthName[]) {

	for (int i = 0; i < 12; i++)
		if (!strcmp(monthName, months[i].name)) return i;

}
