#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define NAME_SIZE 20
#define CSIZE 4
#define MARKS_COUNT 3


struct name {
	char firstname[NAME_SIZE];
	char lastname[NAME_SIZE];
};

struct student {
	struct name studentName;
	float marks[MARKS_COUNT];
	float avgMark;
};


void cleanLine(void);
char* s_gets(char str[], int size);
void correctName(char *str);
int checkInput(int checkArr[], int size);
void getMarks(struct student students[]);
void getAvgMark(struct student students[]);
void printMarks(struct student students[]);


int main(void) {

	struct student students[CSIZE] = {
		{{"Lisa", "Wells"}},
		{{"Richard", "Sherman"}},
		{{"Rodney", "Tyler"}},
		{{"Ryan", "Rivera"}}
	};

	getMarks(students);
	getAvgMark(students);
	printMarks(students);

	return 0;

}


void cleanLine(void) {

	while (getchar() != '\n')
		continue;

}

char* s_gets(char str[], int size) {

	char* retVal = fgets(str, size, stdin);
	if (retVal) {
		char* find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			cleanLine();
	}

}

void correctName(char *str) {

	if (*str) {

		*str = toupper(*str);
		str++;

		while (*str) {
			*str = tolower(*str);
			str++;
		}

	}

}

int checkInput(int checkArr[], int size) {

	for (int i = 0; i < size; i++)
		if (checkArr[i] == 0) return 1;

	return 0;

}

void getMarks(struct student students[]) {

	int i, check;
	int checkArr[CSIZE] = { 0, 0, 0, 0 };											                     	// Array to check if students' marks was entered
	char tempName[NAME_SIZE];

	for (int i = 0; i < CSIZE; i++)
		students[i].avgMark = 0;

	puts("Enter student's name:");
	while (checkInput(checkArr, CSIZE) && s_gets(tempName, NAME_SIZE) != NULL) {		// Stop when all students get their marks

		correctName(tempName);
		check = 0;
		for (i = 0; i < CSIZE; i++)
			if (!strcmp(tempName, students[i].studentName.firstname)) {
				check = 1;
				break;
			}

		if (check && !checkArr[i]) {
			printf("Enter %s's marks: ", tempName);
			for (int j = 0; j < MARKS_COUNT; j++)
				scanf("%f", &students[i].marks[j]);
			cleanLine();

			checkArr[i] = 1;
		}
		else if (check) printf("%s's marks already entered.\n", tempName);
		else printf("Student with name %s wasn't found.\n", tempName);


		puts("\nEnter student's name:");

	}

}

void getAvgMark(struct student students[]) {

	float total;

	for (int i = 0; i < CSIZE; i++) {
		total = 0;
		for (int j = 0; j < MARKS_COUNT; j++)
			total += students[i].marks[j];
		students[i].avgMark = total / MARKS_COUNT;
	}

}

void printMarks(struct student students[]) {

	float total[MARKS_COUNT] = { 0, 0, 0 };

	printf("%10s%10s%6s%6s%6s%6s\n", "Firstname", "Lastname", "Exam1",
		"Exam2", "Exam3", "Avg");
	for (int i = 0; i < CSIZE; i++) {
		printf("%10s%10s%6.2f%6.2f%6.2f%6.2f\n", students[i].studentName.firstname,
			students[i].studentName.lastname, students[i].marks[0],
			students[i].marks[1], students[i].marks[2],
			students[i].avgMark);
		total[0] += students[i].marks[0];
		total[1] += students[i].marks[1];
		total[2] += students[i].marks[2];
	}
	printf("%20s%6.2f%6.2f%6.2f", "", total[0] / CSIZE,
		total[1] / CSIZE, total[2] / CSIZE);

}
