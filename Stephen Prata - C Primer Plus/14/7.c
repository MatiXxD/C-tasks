#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10


struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool dlt;
};


int readLibrary(FILE* fptr, struct book library[]);
void cleanLine(void);
char* s_gets(char* st, int n);
char chooseOption(void);
void addBook(struct book library[]);
void showLibrary(const struct book library[]);
void dltBook(struct book library[]);
void modifyBook(struct book library[]);


int main(void) {

    FILE* pbooks;
    const char* fileName = "book.dat";
    struct book library[MAXBKS];
    int index, count;
    int size = sizeof(struct book);
    char option;

    if ((pbooks = fopen(fileName, "rb")) == NULL){
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    count = readLibrary(pbooks, library);
    fclose(pbooks);

    while ((option = chooseOption()) != 'e') {
        switch (option) {
            case 'a':   addBook(library);       count++;    break;
            case 's':   showLibrary(library);   ;           break;
            case 'd':   dltBook(library);       count--;    break;
            case 'm':   modifyBook(library);    ;           break;
        }
        putchar('\n');
    }

    if (count != 0) {
        pbooks = fopen(fileName, "wb");                                     // Open with "wb" to delete previous data
        for (int i = 0; i < MAXBKS; i++)
            if (!library[i].dlt)
                fwrite(&library[i], sizeof(struct book), 1, pbooks);
    }
    else {
        pbooks = fopen(fileName, "wb");
        puts("No books.");
    }

    puts("Bye.\n");
    fclose(pbooks);

    return 0;

}


int readLibrary(FILE* fptr, struct book library[]) {

    int count = 0;

    while (count < MAXBKS && fread(&library[count], sizeof(struct book), 1, fptr) == 1)
        count++;

    return count;

}

void cleanLine(void) {

    while (getchar() != '\n')
        continue;

}

char* s_gets(char* st, int n) {

    char* ret_val = fgets(st, n, stdin);
    if (ret_val){
        char* find = strchr(st, '\n');
        if (find) *find = '\0';
        else cleanLine();
    }

    return ret_val;

}

char chooseOption(void) {

    puts("Enter what you want to do:");
    printf("a) Add new book\ns) Show books\nm) Modify info\nd) Delete book\ne) Exit\n");

    char option = getchar();
    cleanLine();
    while (strchr("asmdeASMDE", option) == NULL) {
        printf("Wrong input '%c'. Try again: ", option);
        option = getchar();
        cleanLine();
    }

    return tolower(option);

}

void addBook(struct book library[]) {

    int i;
    char tempTitle[MAXTITL];
    char tempAuthor[MAXAUTL];

    for (i = 0; i < MAXBKS; i++)
        if (library[i].dlt) break;

    printf("Enter book's name: ");
    s_gets(tempTitle, MAXTITL);
    strcpy(library[i].title, tempTitle);
    printf("Now enter book's author: ");
    s_gets(tempAuthor, MAXAUTL);
    strcpy(library[i].author, tempAuthor);
    printf("Now enter book's price: ");
    scanf("%f", &library[i].value);
    cleanLine();
    library[i].dlt = false;

}

void showLibrary(const struct book library[]) {

    int i;
    int count = 1;

    putchar('\n');
    for (i = 0; i < MAXBKS; i++)
        if(!library[i].dlt)
            printf("%d(index = %d) %s by %s: $%.2f\n", count++, i, library[i].title,
                library[i].author, library[i].value);

    if (count == 1) puts("You don't have any books.");

}

void dltBook(struct book library[]) {

    int index;
    printf("Enter index of book you want to delete: ");
    while (scanf("%d", &index) != 1 && index < 0 && index > MAXBKS) {
        printf("Wrong input. Try again: ");
        cleanLine();
    }
    cleanLine();

    library[index].dlt = true;

}

void modifyBook(struct book library[]) {

    int index;
    char tempTitle[MAXTITL];
    char tempAuthor[MAXAUTL];

    printf("Enter index of book you want to modify: ");
    while (scanf("%d", &index) != 1 && index < 0 && index > MAXBKS) {
        printf("Wrong input. Try again: ");
        cleanLine();
    }
    cleanLine();

    printf("Enter new book's name: ");
    s_gets(tempTitle, MAXTITL);
    strcpy(library[index].title, tempTitle);
    printf("Now enter book's author: ");
    s_gets(tempAuthor, MAXAUTL);
    strcpy(library[index].author, tempAuthor);
    printf("Now enter book's price: ");
    scanf("%f", &library[index].value);
    cleanLine();

}
