#include <stdio.h>
#include <string.h>

int n;
static int m;

typedef struct oseba {
    char ime[10];
    int starost;
} oseba;

void metoda() {
    static int k = 1;
    k++;
    printf("%d", k);
}

int main(int argc, char* argv[]) {
    metoda();
    printf("\n");
    metoda();

    /*oseba oseba1;
    strcpy(oseba1.ime, "Lan");
    oseba1.starost = 10;*/
}
