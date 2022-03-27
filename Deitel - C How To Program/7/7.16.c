#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52


void shuffle(unsigned int wDeck[][FACES]); 
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[]);
void initDeck(unsigned int deck[][FACES]);
void swap(unsigned int* a, unsigned int* b);
void printDeck(const unsigned int deck[][FACES]);

int main(void) {
    
    int num = 1;
    unsigned int deck[SUITS][FACES] = { 0 };

    srand(time(NULL)); 

    initDeck(deck);

    while (num != -1) {

        shuffle(deck);
        puts("\nDo you want to shuffle deck again? (-1 to stop)");
        scanf_s("%d", &num);

    }

                           
    const char* suit[SUITS] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };

                       
    const char* face[FACES] =
    { "Ace", "Deuce", "Three", "Four",
     "Five", "Six", "Seven", "Eight",
     "Nine", "Ten", "Jack", "Queen", "King" };

    puts("\n------------------Result------------------\n");
    deal(deck, face, suit); 
}


void shuffle(unsigned int wDeck[][FACES]) {
    
    int tmp_i, tmp_j;

    for (int i = 0; i < SUITS; i++) {

        for (int j = 0; j < FACES; j++) {

            tmp_i = rand() % SUITS;
            tmp_j = rand() % FACES;

            swap(&wDeck[i][j], &wDeck[tmp_i][tmp_j]);

        }

    }

    puts("\nAfter shuffel deck is:\n");
    printDeck(wDeck);

}

void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[]) {
    for (size_t card = 1; card <= CARDS; ++card) {
        for (size_t row = 0; row < SUITS; ++row) {
            for (size_t column = 0; column < FACES; ++column) {
                if (wDeck[row][column] == card) {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t'); 
                }
            }
        }
    }
}

void initDeck(unsigned int deck[][FACES]) {

    for (int i = 0; i < SUITS; i++)
        for (int j = 0; j < FACES; j++)
            deck[i][j] = (j + 1) + FACES * i;

    puts("Start deck is:\n");

    printDeck(deck);

}

void swap(unsigned int* a, unsigned int* b) {

    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
    
}

void printDeck(const unsigned int deck[][FACES]) {

    for (int i = 0; i < SUITS; i++) {

        for (int j = 0; j < FACES; j++)
            printf("%3d", deck[i][j]);

        puts("");

    }

}