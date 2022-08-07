#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "tree.h"

#define MAX_LINE_SIZE 256


bool readFile(Tree* tree, const char* filename);
char menu(void);
void printFunc(Item* item);


int main(int argc, char* argv[]){

    Tree tree;
    Item temp;
    unsigned count;
    char answer;

    if(argc < 2){
        fprintf(stderr, "You didn't eneter file's name.\n");
        return 1;
    }

    temp.count = 1;
    InitTree(&tree);
    if(!readFile(&tree, argv[1])) return 1;

    while((answer = menu()) != 'e'){
        if(answer == 'p') 
            TraverseInTree(&tree, printFunc, 2);
        else if (answer == 's'){
            printf("Enter word you want to find: ");
            scanf("%s", temp.word);
            while(getchar() != '\n') continue;
            count = FindInTree(&tree, &temp);
            printf("Word %s was found %u times in file.\n", 
                temp.word, count); 
        }
    }

    return 0;

}


bool readFile(Tree* tree, const char* filename){

    FILE* f;
    Item temp;
    temp.count = 1;

    f = fopen(filename, "r");
    if(f == NULL){
        fprintf(stderr, "Couldn't open file %s.\n", filename);
        return false;
    }

    while(fscanf(f, "%s", temp.word) == 1)
       AddToTree(&temp, tree);
    
    return true;

}

char menu(void){

    char answer;

    printf("Enter option:\n");
    printf("p) Print tree\ns) Print word count\n"
        "e) Exit\n\n");

    answer = tolower(getchar());
    while(getchar() != '\n') continue;
    while(strchr("pse", answer) == NULL){
        printf("Wrong option. Try again: ");
        answer = tolower(getchar());
        while(getchar() != '\n') continue;
    }

    return answer;

}

void printFunc(Item* item){

    printf("%s : %u\n", item->word, item->count);

}