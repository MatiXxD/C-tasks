#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define PLAYERCARDS 5

void shuffle(unsigned int wDeck[][FACES]);
void deal(const unsigned int wDeck[][FACES], unsigned int playersCards1[], unsigned int playersCards2[], const char* wFace[], const char* wSuit[]);
int globalCheck(const unsigned int playersCards[], int player);
bool pairCheck(const unsigned int cardFaces[]);
bool twoPairCheck(const unsigned int cardFaces[]);
bool trioOrFourCheck(const unsigned int cardFaces[], int id);
bool flashCheck(const unsigned int cardSuits[]);
bool streetCheck(const unsigned int cardsFaces[]);

int main(void) {

    int score1, score2;

    const char* suit[SUITS] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };

    const char* face[FACES] =
    { "Ace", "Deuce", "Three", "Four",
      "Five", "Six", "Seven", "Eight",
      "Nine", "Ten", "Jack", "Queen", "King" };


    unsigned int deck[SUITS][FACES] = { 0 };
    unsigned int playersCards1[PLAYERCARDS] = { 0 };
    unsigned int playersCards2[PLAYERCARDS] = { 0 };

    srand(time(NULL));

    shuffle(deck);
    deal(deck, playersCards1, playersCards2, face, suit);

    puts("\n--------------------------------\n");

    score1 = globalCheck(playersCards1, 1);
    score2 = globalCheck(playersCards2, 2);

    puts("\n\n--------------------------------\n\n");

    if (score1 > score2)
        puts("First player WIN!");

    else if (score1 < score2)
        puts("Second player WIN!");

    else
        puts("Draw");

    return 0;

}


void shuffle(unsigned int wDeck[][FACES]) {
    size_t row;
    size_t column;
    size_t card;


    for (card = 1; card <= CARDS; ++card) {


        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);


        wDeck[row][column] = card;
    }
}


void deal(const unsigned int wDeck[][FACES], unsigned int playersCards1[], unsigned int playersCards2[], const char* wFace[], const char* wSuit[]) {
    size_t card;
    size_t row;
    size_t column;

    int temp = 1;
    int secondTemp;

    puts("First player's cards is:");

    for (card = 1; card <= CARDS; ++card) {

        for (row = 0; row < SUITS; ++row) {

            for (column = 0; column < FACES; ++column) {

                if (wDeck[row][column] == card && temp <= 10) {

                    if (temp <= 5) {

                        printf("%d) %5s of %-8s\n", temp, wFace[column], wSuit[row]);
                        playersCards1[temp - 1] = row * 100 + column;
                        temp++;

                    }

                    else if (temp <= 10) {

                        if (temp == 6)
                            puts("\n\nSecond player's cards:");

                        secondTemp = temp - 5;
                        printf("%d) %5s of %-8s\n", secondTemp, wFace[column], wSuit[row]);
                        playersCards2[secondTemp - 1] = row * 100 + column;
                        temp++;

                    }

                    else
                        return;

                }
                

            }
        }

    }
}

int globalCheck(const unsigned int playersCards[], int player) {

    int score = 0;

    unsigned int cardsSuits[PLAYERCARDS] = { 0 };
    unsigned int cardsFaces[PLAYERCARDS] = { 0 };

    unsigned int temp;

    for (int i = 0; i < PLAYERCARDS; i++) {

        cardsSuits[i] = playersCards[i] / 100;
        temp = cardsSuits[i];
        cardsFaces[i] = playersCards[i] - temp * 100;

    }

    if (pairCheck(cardsFaces)) {

        score += 1;
        printf("\nPlayer%d got pair!\n", player);

    }

    if (twoPairCheck(cardsFaces)) {

        score += 2;
        printf("\nPlayer%d got two pair!\n", player);

    }

    if (trioOrFourCheck(cardsFaces, 3)) {

        score += 3;
        printf("\nPlayer%d got trio!\n", player);

    }


    if (trioOrFourCheck(cardsFaces, 4)) {

        score += 6;
        printf("\nPlayer%d got four!\n", player);

    }


    if (flashCheck(cardsSuits)) {

        score += 5;
        printf("\nPlayer%d got flash!\n", player);

    }

    if (streetCheck(cardsFaces)) {

        score += 4;
        printf("\nPlayer%d got street!\n", player);

    }


    return score;

}

bool pairCheck(const unsigned int cardFaces[]) {

    for (int i = 0; i < PLAYERCARDS; i++)
        for (int j = 0; j < PLAYERCARDS; j++)
            if (cardFaces[i] == cardFaces[j] && i != j)
                return 1;

    return 0;

}

bool twoPairCheck(const unsigned int cardFaces[]) {

    int count = 0;
    int countTEST = 0;
    int pos = 0;

    for (int i = 0; i < PLAYERCARDS; i++)
        for (int j = i; j < PLAYERCARDS; j++)
            if (cardFaces[i] == cardFaces[j] && i != j) {

                count++;
                j = 228;

            }

    if (count >= 2)
        return 1;

    else
        return 0;

}

bool trioOrFourCheck(const unsigned int cardFaces[], int id) {

    int pos = 0;
    int count = 1;

    for (int i = 0; i < PLAYERCARDS; i++) {

        for (int j = 0; j < PLAYERCARDS; j++)
            if (cardFaces[i] == cardFaces[j] && i != j)
                if (++count == id)
                    return 1;

        count = 1;

    }

    return 0;

}

bool flashCheck(const unsigned int cardSuits[]) {

    int pos = 0;

    for (int i = 0; i < PLAYERCARDS; i++)
        if (cardSuits[pos] != cardSuits[i] && pos != i)
            return 0;

    return 1;

}

bool streetCheck(const unsigned int cardsFaces[]) {

    int pos = 0;

    for (int i = 1; i < PLAYERCARDS; i++)
        if (cardsFaces[pos] + i != cardsFaces[i])
            return 0;

    return 1;

}