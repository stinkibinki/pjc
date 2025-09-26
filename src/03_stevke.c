#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pojavitve[10];
char niz[100];

void prestej(char niz[], int pojavitve[]) {
    //printf("%d", strlen(niz));
    for (int j = 0; j < strlen(niz); j++) {
        if (48 <= niz[j] && niz[j] <= 57) {
            pojavitve[niz[j] - '0'] += 1;
        }
    }
}

int main() {
    do {
        fgets(niz, 100, stdin);
        prestej(niz, pojavitve);
    } while (niz[0] != '\n');
    printf("0=%d,1=%d,2=%d,3=%d,4=%d,5=%d,6=%d,7=%d,8=%d,9=%d",
        pojavitve[0], pojavitve[1], pojavitve[2], pojavitve[3], pojavitve[4],
        pojavitve[5], pojavitve[6], pojavitve[7], pojavitve[8], pojavitve[9]);
}

