#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gaulityPoints(int averageMark);

int main(void) {

	int averageMark;
	int mark;

	puts("Enter average mark of student (from 0 to 100):");
	scanf_s("%d", &averageMark);
	
	mark = gaulityPoints(averageMark);

	if (!mark)
		puts("Too low average mark.");

	else if (mark == -1)
		puts("Entered wrong average mark.");

	else
		printf("%d\n", mark);

	return 0;

}

int gaulityPoints(int averageMark) {

	if (averageMark >= 90 && averageMark <= 100)
		return 4;

	else if (averageMark >= 80 && averageMark <= 89)
		return 3;

	else if (averageMark >= 70 && averageMark <= 79)
		return 2;

	else if (averageMark >= 60 && averageMark <= 69)
		return 1;

	else if (averageMark >= 0 && averageMark < 60)
		return 0;

	else
		return - 1;

}