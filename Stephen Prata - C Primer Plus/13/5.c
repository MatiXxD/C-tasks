#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 1000

int main(int argc, char* argv[]) {

    double numbers[ARSIZE];
    double value;
    long pos;
    FILE *iofile;


    for (int i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);

    if ((iofile = fopen(argv[1], "wb")) == NULL) {
        fprintf(stderr, "Could not open %s for output.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr,
                "Could not open %s for random access.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ind;
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &ind) == 1 && ind >= 0 && ind < ARSIZE) {
        pos = (long)ind * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }

    fclose(iofile);
    puts("Bye!");

    return 0;

}

