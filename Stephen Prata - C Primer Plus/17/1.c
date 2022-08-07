#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE    45


struct film {
    char title[TSIZE];
    int rating;
    struct film* next;
};


static inline void cleanLine(void) {

    while (getchar() != '\n')
        continue;

}


char* s_gets(char* str, int n);
void printFilms(struct film* movies);
void printRecursive(struct film* const movies);


int main(void) {

    struct film* head = NULL;
    struct film* prev = NULL;
    struct film* current = NULL;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {

        current = (struct film*)malloc(sizeof(struct film));
        if (current == NULL) {
            printf("Memory error. Exiting...\n");
            return 1;
        }

        if (head == NULL)
            head = current;
        else
            prev->next = current;

        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        cleanLine();

        puts("Enter next movie title (empty line to stop):");
        prev = current;

    }

    if (head == NULL)
        printf("No data entered. ");
    else {
        printf("Here is the movie list:\n");
        current = head;
        printFilms(current);
        printf("\nThe list from end:\n");
        current = head;
        printRecursive(head);
    }

    current = head;
    while (current != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
    printf("Bye!\n");

    return 0;

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

void printFilms(struct film* movies) {

    while (movies != NULL) {
        printf("Movie: %s  Rating: %d\n",
            movies->title, movies->rating);
        movies = movies->next;
    }

}

void printRecursive(struct film* const movies) {

    if (movies == NULL) return;

    printRecursive(movies->next);
    printf("Movie: %s  Rating: %d\n", movies->title, movies->rating);

}
