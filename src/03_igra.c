#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W 7
#define H 7

// IGRAJ V LINUX KONZOLI
// ./connect4 ali PATH=.:$PATH, connect4

char znak[] = {'o', 'x'};
char igralnaDeska[H][W];
int vStolpca[W]; // do kam je napolnjen stolpec

void deska() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            igralnaDeska[i][j] = '-';
    }
}

void visinaStolpca() {
    for (int g = 0; g<W; g++) {
        vStolpca[g] = H;
    }
}

void izpisi() {
    //printf("\033[3;0H");
    for (int i = 0; i < H; i++) {
        printf("\r");
        for (int j = 0; j < W; j++)
            printf("%c", igralnaDeska[i][j]);
        printf("\n");
    }
}


int preveriVodoravno() {
    char prejsnji = '?';
    for (int i = 0; i < H; i++) {
        int ponovitev = 1;
        for (int j = 0; j < W; j++) {
            if (igralnaDeska[i][j] == prejsnji && (prejsnji == 'o' || prejsnji == 'x')) {
                ponovitev++;
                if (ponovitev == 4) {
                    return 1;
                }
            } else {
                ponovitev = 1;
            }
            prejsnji = igralnaDeska[i][j];
        }
    }
    return 0;
}

int preveriNavpicno() {
    char prejsnji = '?';
    for (int j = 0; j < W; j++) {
        int ponovitev = 1;
        for (int i = 0; i < H; i++) {
            if (igralnaDeska[i][j] == prejsnji && (prejsnji == 'o' || prejsnji == 'x')) {
                ponovitev++;
                if (ponovitev == 4) {
                    return 1;
                }
            } else {
                ponovitev = 1;
            }
            prejsnji = igralnaDeska[i][j];
        }
    }
    return 0;
}

int preveriDiagonalno() {
    char prejsnji = '?';
    for (int n = 0; n < H+W - 1; n++) {
        int ponovitev = 1;
        int j = n < H ? 0 : n-(H-1);
        for (int i = n < H ? n : H-1; i >= 0; i--) {
            if (j < W) {
                if (igralnaDeska[i][j] == prejsnji && (prejsnji == 'o' || prejsnji == 'x')) {
                    ponovitev++;
                    if (ponovitev == 4) {
                        return 1;
                    }
                } else {
                    ponovitev = 1;
                }
                prejsnji = igralnaDeska[i][j];
                j++;
            } else break;

        }
    }
    prejsnji = '?';
    for (int n = 0; n < H+W - 1; n++) {
        int ponovitev = 1;
        int i = n < W ? H-1 : n-(W-1);
        for (int j = n < W ? n : W-1; j >= 0; j--) {
            if (i < H) {
                if (igralnaDeska[i][j] == prejsnji && (prejsnji == 'o' || prejsnji == 'x')) {
                    ponovitev++;
                    if (ponovitev == 4) {
                        return 1;
                    }
                } else {
                    ponovitev = 1;
                }
                prejsnji = igralnaDeska[i][j];
                i--;
            } else break;
        }
    }
    return 0;
}

void zmage(int z1, int z2) {
    printf("Zmage 1. igralca: %d | Zmage 2. igralca: %d", z1, z2);
}

int main() {
    visinaStolpca();
    deska();
    int z1 = 0, z2 = 0;
    zmage(z1, z2);
    printf("\n");
    izpisi();
    char a[6];//stolpec
    for (int i = 0; i < H*W; i++) {
        printf("Na vrsti je igralec %d (%c). Vpiši stolpec:     \b\b\b\b", i%2 + 1, znak[i%2]);
        fgets(a, 6, stdin);
        int s = atoi(a);
        if (1 > s || s > W) {
            printf("Ta stolpec ne obstaja. Stolpci so od %d do %d\033[1A\r", 1, W);
            i--;
            continue;
        }

        if (igralnaDeska[0][s-1] != '-') {
            printf("Ta stolpec je poln.\033[1A\r");
            i--;
            continue;
        }
        vStolpca[s-1]--;
        igralnaDeska[vStolpca[s-1]][s-1] = znak[i%2];
        printf("\033[%dA", H+1);
        izpisi();
        if (preveriVodoravno() || preveriNavpicno() || preveriDiagonalno()) {
            printf("KONEC IGRE!%35c", ' ');
            if (i%2 + 1 == 1) z1++;
            else z2++;
            printf("\033[%dA\r", H+1);
            zmage(z1, z2);
            printf("\033[%dB\r", H+2);
            int ponovno = 0;
            while (1) {
                printf("Zmagal je igralec %d. Igraj ponovno? (y/n): ", i%2 + 1);
                char odgovor[10];
                fgets(odgovor, 10, stdin);
                if (strchr(odgovor, 'y')) {
                    i = -1;
                    deska();
                    visinaStolpca();
                    ponovno = 1;
                    break;
                }
                if (strchr(odgovor, 'n'))
                    break;
                printf("\033[1A");
            }
            if (ponovno) {
                printf("\033[%dA", H+2);
                izpisi();
                continue;
            } break;
        } // \033[%d;0H
        printf("\033[1B%50c\033[1A\r", ' ');
    }
}