#include <stdio.h>
#include <string.h>

void printFile(char *name);
void parsFlags(char *name, char *flag);

int main(int argc, char **argv) {
    char flags[][] = {"-b", "-e", "-E", "-n", "-s", "-t", "-T"};
    for (int i = 1; i < argc; i++) {
        parsFlags(argv[i], flags[i]);
        printFile(argv[i]);
    }
    return 0;
}

void printFile(char *name) {
    char c;
    FILE *f = fopen(name, "r");
    if (f != NULL) {
        while (c != EOF) {
            c = fgetc(f);
            putc(c, stdout);
        }
    }
    fclose(f);
    return;
}

void parsFlags(char *name, char *flag) {
    if (strcmp(name, flag) == 0) {
        printf("флаг есть");
    } else {printf("флага нет");}
    return;
}