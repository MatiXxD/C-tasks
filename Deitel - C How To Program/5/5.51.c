#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


enum Status { CONTINUE, WON, LOST };


int rollDice(void);

float checkRes(int points, float bet);

enum Status continueGame(enum Status gameStatus, int sum, int myPoint);

bool winOrLose(enum Status gameStatus);

void reaction(void);


int main(void) {

    int sum;
    float bankBalance = 1000;
    float bet;

    srand((int)time(NULL));

    while (bankBalance > 0) {

        puts("Enter your bet");
        scanf_s("%f", &bet);
        while (bet > bankBalance) {

            puts("Enter correct bet");
            scanf_s("%f", &bet);

        }

        sum = rollDice();
        bankBalance += checkRes(sum, bet);

        printf("Your balance is %.2f", bankBalance);
        puts("\n\n--------------------------------------------------\n\n");

        if (bankBalance == 0)
            printf("You have lost all you money((((((\n");

        else
            reaction();

    }

    return 0;

}

float checkRes(int points, float bet) {

    int myPoint = 0;
    enum Status gameStatus;

    switch (points) {


    case 7:
    case 11:
        gameStatus = WON;
        break;


    case 2:
    case 3:
    case 12:
        gameStatus = LOST;
        break;


    default:
        gameStatus = CONTINUE;
        myPoint = points;
        printf("Point is %d\n", myPoint);
        break;
    }

    if (gameStatus == CONTINUE)
        gameStatus = continueGame(gameStatus, points, myPoint);

    if (winOrLose(gameStatus))
        return bet;

    else
        return -bet;

}

enum Status continueGame(enum Status gameStatus, int sum, int myPoint) {

    while (CONTINUE == gameStatus) {
        sum = rollDice();


        if (sum == myPoint) {
            gameStatus = WON;
        }
        else {
            if (7 == sum) {
                gameStatus = LOST;
            }
        }
    }

    return gameStatus;

}

bool winOrLose(enum Status gameStatus) {

    if (WON == gameStatus) {

        puts("Player wins\n");
        return 1;

    }
    else {

        puts("Player loses\n");
        return 0;

    }

}

int rollDice(void) {
    int die1;
    int die2;
    int workSum;

    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);
    workSum = die1 + die2;


    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
    return workSum;

}

void reaction(void) {

    int select;

    select = 1 + rand() % 6;

    switch (select)
    {
    case 1:
        puts("Oh, you're going for broke, huh?\n");
        break;
    case 2:
        puts("Aw cmon, take a chance!\n");
        break;
    case 3:
        puts("Hey, I think this guy is going to break the bank!!\n");
        break;
    case 4:
        puts("You're up big. Now's the time to cash in your chips!\n");
        break;
    case 5:
        puts("Way too lucky! Those dice have to be loaded!\n");
        break;
    case 6:
        puts("Bet it all! Bet it all!\n");
        break;
    default:
        break;
    }

}