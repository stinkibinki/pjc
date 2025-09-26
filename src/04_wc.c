#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
    FILE *dat = fopen(args[1], "r");
    if (dat == NULL) {
        printf("Napaka");
        exit(1);
    }

    int znaki = 0;
    int vrstica = 0;
    int besede = 0;
    int prejsnji = 10; //'\n'

    while (!feof(dat)) {
        int c = fgetc(dat);
        if (c > 0) znaki++;
        if (c == '\n') {
            znaki++;
            vrstica++;
        }
        if ((c == ' ' || c == '\n' || feof(dat)) && (prejsnji != ' ' && prejsnji != '\n')) {
            besede++;
        }
        prejsnji = c;
    }
    printf("nl: %d, besede: %d, znaki: %d\n", vrstica, besede, znaki);

    fclose(dat);
}
