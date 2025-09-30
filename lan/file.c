#include <stdio.h>

int main(int argc, char *args[]) {
    FILE *fpt;
    fpt = fopen("../res/tocke1.txt", "r");
    char output[99];
    fprintf(fpt, "%s");
    printf("%s", output);
    fclose(fpt);
}