#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct insurance {
	char cardNum[10];
	struct {
		char name[20];
		char patronymic[20];
		char surname[20];
	};
};


void printStruct1(const struct insurance* data);
void printStruct2(struct insurance data);


int main(void) {

	struct insurance insuranceArray[5] = {
		{"123456789", {"Leo", "Nikolayevich", "Tolstoy"}},
		{"987654321", {"Jane", "", "Austen"}},
		{"123321789", {"Philip", "Nicholas", "Pullman"}},
		{"123987789", {"Douglas", "Noel", "Adams"}},
		{"123357789", {"Harper", "", "Lee"}}
	};

	for(int i = 0 ; i < 5 ; i++)
		printStruct1(&insuranceArray[i]);
	putchar('\n');
	for(int i = 0 ; i < 5 ; i++)
		printStruct2(insuranceArray[i]);

	return 0;

}

void printStruct1(const struct insurance* data) {

	char addToStr[4] = "";
	if (strcmp(data->patronymic, "")) {
		addToStr[0] = toupper(data->patronymic[0]);
		addToStr[1] = '.';
		addToStr[2] = ' ';
		addToStr[3] = '\0';
	}

	printf("%s, %s %s-- %s\n", data->surname, data->name, addToStr, data->cardNum);

}

void printStruct2(struct insurance data) {

	char addToStr[4] = "";
	if (strcmp(data.patronymic, "")) {
		addToStr[0] = toupper(data.patronymic[0]);
		addToStr[1] = '.';
		addToStr[2] = ' ';
		addToStr[3] = '\0';
	}

	printf("%s, %s %s-- %s\n", data.surname, data.name, addToStr, data.cardNum);

}
