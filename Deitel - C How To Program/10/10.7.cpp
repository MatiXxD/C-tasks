#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct bitCard {
    unsigned face : 4; 
    unsigned suit : 2; 
    unsigned color : 1; 
}; 

typedef struct bitCard Card; 
void fillDeck(Card* const wDeck); 
void shuffel(Card* const wDeck);
void deal(const Card* const wDeck); 

int main(void)
{
    Card deck[52]; 

    srand((unsigned)time(NULL));

    fillDeck(deck);
    shuffel(deck);
    deal(deck);
    return 0; 
} 


void fillDeck(Card* const wDeck)
{
    int i; 

    
    for (i = 0; i <= 51; i++) {
        wDeck[i].face = i % 13;
        wDeck[i].suit = i / 13;
        wDeck[i].color = i / 26;
    } 
} 


void deal(const Card* const wDeck)
{
    int k1; 
    int k2; 

    for (k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++) {
        printf("Card:%3d  Suit:%2d  Color:%2d   ",
            wDeck[k1].face, wDeck[k1].suit, wDeck[k1].color);
        printf("Card:%3d  Suit:%2d  Color:%2d\n",
            wDeck[k2].face, wDeck[k2].suit, wDeck[k2].color);
    } 
} 

void shuffel(Card* const wDeck) {

    for (int i = 0; i < 52; i++) {

        int j = rand() % 52;
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;

    }
        

}
