#include <stdio.h>
#include <string.h>


#define MAXTITL  41
#define MAXAUTL  41
#define MAXBKS  100


struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};


void cleanLine(void);
char* s_gets(char* st, int n);
void printInputOrder(struct book library[], int count);
void alphCmp(struct book* b1, struct book* b2);
void valCmp(struct book* b1, struct book* b2);
void printSortOrder(struct book library[], int count, void (*cmpFunc)(struct book*, struct book*));


int main(void) {

    struct book library[MAXBKS];
    int count = 0;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0') {

        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        cleanLine();

        if (count < MAXBKS)
            printf("Enter the next title.\n");

    }

    if (count > 0) {
        printf("\nHere is the list of your books (input order):\n");
        printInputOrder(library, count);
        printf("\nHere is the list of your books (alphabet order):\n");
        printSortOrder(library, count, alphCmp);
        printf("\nHere is the list of your books (value order):\n");
        printSortOrder(library, count, valCmp);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

void cleanLine(void) {

    while (getchar() != '\n')
        continue;

}

char* s_gets(char* st, int n) {

    char*  ret_val = fgets(st, n, stdin);
    if (ret_val){
        char* find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            cleanLine();
    }

    return ret_val;

}

void printInputOrder(struct book library[], int count) {

    for (int i = 0; i < count; i++)
        printf("%s by %s: $%.2f\n", library[i].title,
            library[i].author, library[i].value);

}

void alphCmp(struct book* b1, struct book* b2) {

    if (strcmp(b1->title, b2->title) > 0) {
        struct book temp = *b1;
        *b1 = *b2;
        *b2 = temp;
    }

}

void valCmp(struct book* b1, struct book* b2) {

    if (b1->value > b2->value) {
        struct book temp = *b1;
        *b1 = *b2;
        *b2 = temp;
    }

}

void printSortOrder(struct book library[], int count, void (*cmpFunc)(struct book*, struct book*)) {

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++)
            (*cmpFunc)(&library[i], &library[j]);                                                           // Use cmpFunc argument to choose between
        printf("%s by %s: $%.2f\n", library[i].title,                                                       // sort by values and sort by alphabet
            library[i].author, library[i].value);
    }
    printf("%s by %s: $%.2f\n", library[count-1].title,
        library[count-1].author, library[count-1].value);

}
