#include <stdio.h>
#include <ctype.h>
#include "stack.h"


inline static void cleanLine(void){

    while(getchar() != '\n')
        continue;

}

void getStr(Stack* stack);
void printElem(Item *item);

int main(void){

    Item temp;
    Stack stack;
    InitStack(&stack);
    getStr(&stack);

    while(!IsEmpty(&stack)){
        printf("Values in the stack:\n");
        ApplyFunc(&stack, printElem);
        putchar('\n');
        Pop(&temp, &stack);
    }

    DeleteStack(&stack);

    return 0;

}


void getStr(Stack* stack){

    Item temp;

    puts("Enter your string:");
    while((temp = getchar()) != '\n')
        Push(temp, stack);
    
}

void printElem(Item *item){

    putchar(*item);

}