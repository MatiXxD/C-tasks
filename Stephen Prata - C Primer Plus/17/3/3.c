#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


static inline void cleanLine (void) {
    while (getchar() != '\n') continue;
}

void showmovies(Item item);
char* s_gets(char* str, int n);


int main(void) {

    List movies;
    Item temp;

    /* initialize       */
    InitializeList(&movies);
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    /* gather and store */
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}


void showmovies(Item item){

    printf("Movie: %s  Rating: %d\n", item.title,
        item.rating);

}

char* s_gets(char* str, int n) {

    char* retVal = fgets(str, n, stdin);
    if (retVal) {

        char* find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            cleanLine();

    }

    return retVal;

}
