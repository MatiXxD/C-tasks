#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>


void sigintHandler(int errorCode);
void sigabrtHandler(int errorCode);


int main() {

    srand((unsigned)time(NULL));
    signal(SIGINT, sigintHandler);
    signal(SIGABRT, sigabrtHandler);

    int temp = 0;

    for (int i = 0; i < 100; i++) {

        printf("%d) %d\n", i + 1, temp);
        temp = 1 + rand() % 100;

        if (temp == 16)
            abort();

    }

    getchar();

    return 0;

}


void sigintHandler(int errorCode) {

    printf("Signal %s was caught with error code %d\n", "SIGINT", errorCode);
    signal(SIGINT, sigintHandler);

}

void sigabrtHandler(int errorCode) {

    printf("Signal %s was caught with error code %d\n", "SIGABRT", errorCode);
    getchar();
    exit(EXIT_SUCCESS);

}