#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define B 8 //koliko bitna števila

int main(int argc, char *args[]) {
    int i = atoi(args[1]);
    int zacetek = 0;
    int vsota = 0;
    int stEnk = 0;
    int stevila[256];
    int vse = 0;

    for (int n = 1; n <= pow(2,B)-1; n++) {
        int st = n;
        while (st != 0) {
            if (st & 1)
                stEnk++;
            st >>= 1;
            if (stEnk > i) {
                stEnk = 0;
                break;

            }

        }
        if (stEnk == i) {
            stevila[vse] = n;
            vsota += n;
            vse++;
        }
        stEnk = 0;

    }

    for (int k = 0; k < vse; k++) {
        char binIzpis[B+1];
        int s = stevila[k];
        binIzpis[B] = '\0';
        for (int b = B-1; b >= 0;  b--) {
            if (s & 1) {
                binIzpis[b] = '1';
            } else binIzpis[b] = '0';
            s>>=1;
        }
        printf("%s=%d\n", binIzpis, stevila[k]);
    }
    printf("i=%d, n=%d, vsota=%d", i, vse, vsota);
}
