#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int id;
    char firstName[20];
    char lastName[20];
    double balance;

}Client;

void getClients(FILE* ofPtr, FILE* trPtr, FILE* nfPtr);

int main(void) {
    
    FILE *ofPtr, *trPtr, *nfPtr;
    ofPtr = fopen("oldmast.dat", "r");
    trPtr = fopen("trans.dat", "r");
    nfPtr = fopen("newmast.dat", "w");
    
    getClients(ofPtr, trPtr, nfPtr);

    fclose(ofPtr);
    fclose(trPtr);
    fclose(nfPtr);

    return 0; 
} 

void getClients(FILE* ofPtr, FILE* trPtr, FILE* nfPtr) {

    int i = 0;
    Client clients[100];
    char trash[100];

    fscanf_s(ofPtr, "%s%s%s%s", trash, 25, trash, 25, trash, 25, trash, 25);
    fscanf_s(trPtr, "%s%s", trash, 50, trash, 50);
    while (!feof(ofPtr)) {

        int tempId;
        double tempBalance;

        fscanf_s(ofPtr, "%d%s%s%lf", &clients[i].id, clients[i].firstName, 20,
            clients[i].lastName, 20, &clients[i].balance);
        fscanf_s(trPtr, "%d%lf", &tempId, &tempBalance);

        if (tempId == clients[i].id)
            clients[i].balance += tempBalance;

        else
            printf("Unamatched transacton record for account number %d\n", tempId);

        i++;

    }
    clients[i].id = -3228;

    i = -1;
    while (clients[++i].id != -3228) 
        fprintf(nfPtr, "%-5d%-15s%-15s%-10lf\n", clients[i].id, clients[i].firstName, clients[i].lastName, clients[i].balance);
    

}

//Id	    FirstName	LastName	Balance
//100	    Alan		Jones 	    348.17
//300	    Mary		Smith		27.19
//500	    Sam 		Sharp		0.00
//700     Suzy		Green		-14.22

//Id		Balance
//100		27.14
//300		62.11
//400		100.56
//900   	82.17