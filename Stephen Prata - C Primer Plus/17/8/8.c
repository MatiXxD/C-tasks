#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define SLEN 20


char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);


int main(void){

    Tree pets;
    char choice;

    InitTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice){
            case 'a' :  addpet(&pets);
                break;
            case 'l' :  showpets(&pets);
                break;
            case 'f' :  findpet(&pets);
                break;
            case 'n' :  printf("%d pets in club\n",
                               TreeSize(&pets));
                break;
            case 'd' :  droppet(&pets);
                break;
            default  :  puts("Switching error");
        }
        putchar('\n');
    }
    EmptyTree(&pets);
    puts("Bye.");

    return 0;

}

char menu(void){

    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          1) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");

    while ((ch = getchar()) != EOF){
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)      /* make EOF cause program to quit */
        ch = 'q';

    return ch;

}

void addpet(Tree * pt){

    Item temp;

    if (IsFullTree(pt))
        puts("No room in the club!");
    else{
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.types[0], SLEN);
        uppercase(temp.types[0]);
        uppercase(temp.petname);
        AddToTree(&temp, pt);
    }

}

void showpets(const Tree * pt){

    if (IsEmptyTree(pt))
        puts("No entries!");
    else
        PrintPets(pt);

}

void findpet(const Tree * pt) {

    Item temp;

    if (IsEmptyTree(pt)){
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.types[0], SLEN);
    uppercase(temp.petname);
    uppercase(temp.types[0]);
    printf("%s the %s ", temp.petname, temp.types[0]);
    if (FindInTree(pt, &temp))
        printf("is a member.\n");
    else
        printf("is not a member.\n");

}

void droppet(Tree * pt){

    Item temp;

    if (IsEmptyTree(pt)){
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.types[0], SLEN);
    uppercase(temp.petname);
    uppercase(temp.types[0]);
    
    printf("%s the %s ", temp.petname, temp.types[0]);

    if (DeleteFromTree(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");

}

void uppercase(char * str){

    while (*str){
        *str = toupper(*str);
        str++;
    }

}

char * s_gets(char * st, int n){

    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }

    return ret_val;

}
