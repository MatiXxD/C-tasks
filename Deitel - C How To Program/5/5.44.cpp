#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void choose(void);

int getNum(int lvl);

void example(int operation, int lvl);

void correctMessage(void);

void incorrectMessage(void);

void check(int rightNum);

int main(void) {

	srand((int)time(NULL));

    choose();

	return 0;

}

void choose(void) {

    int lvl, operation;
    operation = lvl = 0;

    while (lvl < 1 || lvl > 3) {

        puts("Enter your lvl (from 1 to 3)");
        scanf_s("%d", &lvl);

    }

    while (operation < 1 || operation > 5) {

        puts("Enter operation (1 - '+', 2 - '-', 3 - '*', 4 - '/'");
        scanf_s("%d", &operation);

    }
   
    example(operation, lvl);

}

int getNum(int lvl) {

    switch (lvl) {

    case 1:
        return 1 + rand() % 10;
        break;

    case 2:
        return 1 + rand() % 100;
        break;

    case 3:
        return 1 + rand() % 1000;
        break;

    }

    return -1;

}

void example(int operation, int lvl) {

    int num1, num2;
    int correctNum;

    num1 = getNum(lvl);
    num2 = getNum(lvl);

    switch (operation) {

    case 1:
        printf("%d + %d = ", num1, num2);
        correctNum = num1 + num2;
        check(correctNum);
        break;

    case 2:
        printf("%d - %d = ", num1, num2);
        correctNum = num1 - num2;
        check(correctNum);
        break;

    case 3:
        printf("%d * %d = ", num1, num2);
        correctNum = num1 * num2;
        check(correctNum);
        break;

    case 4:
        printf("Int part of %d / %d = ", num1, num2);
        correctNum = num1 / num2;
        check(correctNum);
        printf("%d mod %d = ", num1, num2);
        correctNum = num1 % num2;
        check(correctNum);
        break;

    }

}

void correctMessage(void)
{
    switch (rand() % 4)
    {
    case 0:
        printf("Very good!\n\n");
        break;
    case 1:
        printf("Excellent!\n\n");
        break;
    case 2:
        printf("Nice work!\n\n");
        break;
    case 3:
        printf("Keep up the good work!\n\n");
        break;
    }
}

void incorrectMessage(void)
{
    switch (rand() % 4)
    {
    case 0:
        printf("No. Please try again.\n? ");
        break;
    case 1:
        printf("Wrong. Try once more.\n? ");
        break;
    case 2:
        printf("Don't give up!\n? ");
        break;
    case 3:
        printf("No. Keep trying.\n? ");
        break;
    }
}

void check(int rightNum) {

    int number;
    int misstake = 0;

    scanf_s("%d", &number);
    while (number != rightNum) {

        incorrectMessage();
        scanf_s("%d", &number);
        misstake++;

    }

    if (!misstake)
        correctMessage();

    else if (misstake >= 1 && misstake <= 3)
        puts("You get score to pass exam");

    else
        puts("You didn't pass");

}
