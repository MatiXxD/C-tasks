#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
 

struct customer {

    char lastName[15];
    char firstName[15];
    int customerNumber;

    struct {

        char phoneNumber[13];
        char address[50];
        char city[15];
        char state[4];
        char zipCode[7];

    } personal;

} customerRecord, *customerPtr;


int main(void)
{
    customerPtr = &customerRecord;

    //a
    strcpy(customerRecord.lastName, "Petrov");                      // ALSO CAN USE sprintf()
    printf("%s\n\n", customerRecord.lastName);

    //b
    strcpy(customerPtr->lastName, "Detrov");
    printf("%s\n\n", customerPtr->lastName);

    //c
    strcpy(customerRecord.lastName, "Denis");
    printf("%s\n\n", customerRecord.lastName);
    
    //d
    strcpy(customerPtr->firstName, "Penis");
    printf("%s\n\n", customerPtr->firstName);

    //e
    customerRecord.customerNumber = 228;
    printf("%d\n\n", customerRecord.customerNumber);

    //f
    customerPtr->customerNumber = 1337;
    printf("%d\n\n", customerPtr->customerNumber);

    //g
    sprintf(customerRecord.personal.phoneNumber, "84991337148");
    printf("%s\n\n", customerRecord.personal.phoneNumber);

    //h
    sprintf(customerPtr->personal.phoneNumber, "84992281337");
    printf("%s\n\n", customerPtr->personal.phoneNumber);


    return 0; 
} 