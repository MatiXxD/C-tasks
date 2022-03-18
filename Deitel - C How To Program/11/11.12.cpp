#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int id;
    char name[25];
    int num;
    double price;

}Tool;

int enterChoice();
void initFile();
void writeData();
void printData();
void dltData();
void modifData();

int main(void) {
    
    int choice;

    while ((choice = enterChoice()) != 5) {

        switch (choice) {

        case 0:
            initFile();
            break;

        case 1:
            writeData();
            break;

        case 2:
            printData();
            break;

        case 3:
            modifData();
            break;

        case 4:
            dltData();
            break;

        default:
            puts("Wrond Input!");
            break;

        }

        puts("\n");

    }

    return 0; 
} 

int enterChoice() {

    int a;

    puts("Enter what you want to do:");
    printf("0 - initialize file\n1 - write some data\n2 - print file / show data\n3 - update info about tool\n4 - delete tool\n5 - exit\n");
    scanf_s("%d", &a);

    return a;

}

void initFile() {

    FILE* f;

    if ((f = fopen("hardware.dat", "wb")) == NULL) {

        puts("ERROR!");
        return;

    }
       
    Tool blankTool = {0, "", 0, 0.0};

    for (int i = 0; i < 100; i++)
        fwrite(&blankTool, sizeof(Tool), 1, f);

    fclose(f);
    
}

void writeData() {

    FILE* f;
    if ((f = fopen("hardware.dat", "rb+")) == NULL) {

        puts("ERROR!");
        return;

    }


    Tool tool = { 0, "", 0, 0.0 };
    puts("\nEnter id (0 to exit):");
    scanf_s("%d", &tool.id);
    while (tool.id != 0) {

        puts("Enter name:");
        getchar();
        scanf_s("%[^\n]s", tool.name, 25);
        puts("Enter number of tools and it's price");
        scanf_s("%d%lf", &tool.num, &tool.price);

        fseek(f, (tool.id - 1) * sizeof(Tool), SEEK_SET);
        fwrite(&tool, sizeof(Tool), 1, f);

        puts("\nEnter id (0 to exit):");
        scanf_s("%d", &tool.id);

    }

    fclose(f);

}

void printData() {

    int a;
    FILE* fin;
    Tool tool = { 0, "", 0, 0.0 };

    if ((fin = fopen("hardware.dat", "rb+")) == NULL) {

        puts("ERROR!");
        return;

    }

    puts("Enter 0 to make file for output and 1 for console output");
    scanf_s("%d", &a);

    if (!a) {

        FILE* fout;
        if ((fout = fopen("tools.dat", "w")) == NULL) {

            puts("ERROR!");
            return;

        }

        fprintf(fout, "%-6s%-25s%-10s%10s\n", "Id", "Name", "Number", "Price");
        while (!feof(fin)) {

            fread(&tool, sizeof(Tool), 1, fin);

            if (tool.id != 0)
                fprintf(fout, "%-6d%-25s%-10d%10.2lf\n", tool.id, tool.name, tool.num, tool.price);

        }

        fclose(fout);
        fclose(fin);

    }

    else {

        printf("%-6s%-25s%-10s%10s\n", "Id", "Name", "Number", "Price");
        while (!feof(fin)) {

            fread(&tool, sizeof(Tool), 1, fin);

            if (tool.id != 0)
                printf("%-6d%-25s%-10d%10.2lf\n", tool.id, tool.name, tool.num, tool.price);

        }

        fclose(fin);

    }

}

void dltData() {

    FILE* f;
    int id;
    Tool blankTool = { 0, "", 0, 0.0 };

    if ((f = fopen("hardware.dat", "rb+")) == NULL) {

        puts("ERROR!");
        return;

    }

    puts("\nEnter id of tool you want to be deleted:");
    scanf_s("%d", &id);
    fseek(f, (id - 1) * sizeof(Tool), SEEK_SET);
    fread(&blankTool, sizeof(Tool), 1, f);

    if (blankTool.id != 0) {

        puts("This tool will be deleted:");
        printf("%-6d%-25s%-10d%10.2lf\n", blankTool.id, blankTool.name, blankTool.num, blankTool.price);

        blankTool = { 0, "", 0, 0.0 };
        fseek(f, (id - 1) * sizeof(Tool), SEEK_SET);
        fwrite(&blankTool, sizeof(Tool), 1, f);

    }

    else
        printf("Tool with id %d doesn't exist\n", blankTool.id);
    
    fclose(f);

}

void modifData() {

    FILE* f;
    int id;
    Tool tool = { 0, "", 0, 0.0 };

    if ((f = fopen("hardware.dat", "rb+")) == NULL) {

        puts("ERROR!");
        return;

    }

    puts("\nEnter id of tool you want to modify:");
    scanf_s("%d", &id);
    fseek(f, (id - 1) * sizeof(Tool), SEEK_SET);
    fread(&tool, sizeof(Tool), 1, f);

    if (tool.id != 0) {

        int addNum;
        double addPrice;

        puts("This tool will be modify:");
        printf("%-6d%-25s%-10d%10.2lf\nIntput add changes to number and price:\n", tool.id, tool.name, tool.num, tool.price);
        scanf_s("%d%lf", &addNum, &addPrice);
        tool.num += addNum;
        tool.price += addPrice;

        fseek(f, (id - 1) * sizeof(Tool), SEEK_SET);
        fwrite(&tool, sizeof(Tool), 1, f);

    }

    else
        printf("Tool with id %d doesn't exist\n", tool.id);

    fclose(f);

}