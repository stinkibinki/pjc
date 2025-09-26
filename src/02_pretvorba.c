#include <stdio.h>
#include <stdlib.h>

int pH(int i) {
    return i/3600;
}

int pM(int i) {
    return (i - pH(i)*3600) / 60;
}

int pS(int i) {
    return ((i - pH(i)*3600) - pM(i)*60);
}

int p(int i, char n) { // pretvori
    switch (n) {
        case 'h':
            return i/3600;
        case 'm':
            return (i - i/3600) / 60;
        case 's':  // h           m
            return i % 3600 % 60;
        default:
            return -1;
    }
}

void izpisi(int n, int h, int m, int s, int nacin) {
    if (nacin == 1) // s --> HH:MM:SS
        printf("%ds=%02d:%02d:%02d\n", n, h, m, s);
    else if (nacin == 2) // HH:MM:SS --> s
        printf("%d ura, %d minut, %d sekund je %d sekund.", h, m, s, n);
}

int main(int argc, char *args[]) {

    int nacin = atoi(args[1]);
    if (nacin == 1) {
        int zacetek = atoi(args[2]);
        int konec = atoi(args[3]);
        for (int i = zacetek; i <= konec; i++) {
            izpisi(i, p(i, 'h'), p(i, 'm'), p(i, 's'), 1);
        }
    } else if (nacin == 2) {
        int n = atoi(args[2]);
        izpisi(n, pH(n), pM(n), pS(n), 1);
    } else if (nacin == 3) {
        int h = atoi(args[2]);
        int m = atoi(args[3]);
        int s = atoi(args[4]);
        int skupaj = s + m*60 + h*3600;
        izpisi(skupaj, h, m, s, 2);
    }


}

