#include <stdio.h>
#include <math.h>

double roundToInteger(double number);

double roundToTenths(double number);

double roundToHundreths(double number);

double roundToThousandths(double number);

int main (void) {

	double number, round;
	int check;
	int caseNum;
	int err = 0;
	
	puts("Enter number (-228 to stop input)");
	scanf_s("%lf", &number);

	while (number != -228) {

		puts("Enter case (1 - int, 2 - to 10, 3 - to 100, 4 - to 1000)");
		scanf_s("%d", &caseNum);
		check = 0;
		round = 228;
		
		while (round == 228) {

			switch (caseNum) {

			case 1:
				round = roundToInteger(number);
				check++;
				break;

			case 2:
				round = roundToTenths(number);
				check++;
				break;

			case 3:
				round = roundToHundreths(number);
				check++;
				break;

			case 4:
				round = roundToThousandths(number);
				check++;
				break;

			default:
				puts("Entered wrong case. Choose from 1 to 4!");
				round = 228;

			}

			if(!check)
				scanf_s("%d", &caseNum);

		}
		

		printf("Round number %f is %f", number, round);

		puts("\n\n-----------------------------------\n\n");

		puts("Enter number (-228 to stop input)");
		scanf_s("%lf", &number);

		err++;
	}

	if (err == 0)
		puts("Nothing was entered!");

	return 0;

}

double roundToInteger(double number) {

	return floor(number + 0.5);

}

double roundToTenths(double number) {

	return floor(number * 10 + 0.5) / 10.0;

}

double roundToHundreths(double number) {

	return floor(number * 100 + 0.5) / 100.0;

}

double roundToThousandths(double number) {

	return floor(number * 1000 + 0.5) / 1000.0;

}