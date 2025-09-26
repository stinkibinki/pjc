#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
    if (argc != 2) {
        printf("Podaj število n!");
    } else if (atoi(args[1]) < 0) {
        printf("Število n naj bo pozitivno.");
    } else {
        int n = atoi(args[1]);
        int f1 = 1;
        int f2 = 1;
        int fn = 0;
        int vsota = 2;
        int meja = 0;
        if (n < 3) {
            vsota = n;
        } else {
            for (int j = 3; j <= n; j++) {
                fn = f2 + f1;
                vsota += fn;
                f1 = f2;
                f2 = fn;
                if (vsota < 0) {
                    meja = j-1;
                    break;
                }
            }
            if (meja != 0) {
                printf("Napaka! Smiselna zgornja meja za n je %d", meja);
            } else {
                printf("%d", vsota);
            }

        }

    }
}