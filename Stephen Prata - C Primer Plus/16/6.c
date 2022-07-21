#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

typedef struct {
    char firstName[20];
    char lastName[20];
}Name;

void showNames(const Name people[], int size);
int myComp(const void* p1, const void* p2);

int main(void){

    Name people[10] = {
        {"Glenn", "Green"},
        {"Annette", "Smith"},
        {"David", "Conner"},
        {"Willie", "Williams"},
        {"Rebecca", "Wilson"},
        {"Maria", "Carrol"},
        {"Michael", "Johnson"},
        {"David", "Simpson"},
        {"William", "Barnes"},
        {"Deborah", "Williams"},
    };

    puts("Before sorting:");
    showNames(people, 10);
    puts("\nAfter sorting:");
    qsort(people, 10, sizeof(Name), myComp);
    showNames(people, 10);

    return 0;

}

void showNames(const Name people[], int size) {

    for (int i = 0; i < size; i++)
        printf("%s %s\n", people[i].lastName, people[i].firstName);

}


int myComp(const void* p1, const void* p2) {

    const Name* a1 = (const Name*)p1;
    const Name* a2 = (const Name*)p2;

    int compVal = strcmp(a1->lastName, a2->lastName);
    if (compVal != 0)
        return compVal;
    else
        return strcmp(a1->firstName, a2->firstName);

}
