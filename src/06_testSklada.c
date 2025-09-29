#include <stdio.h>
#include "06_sklad.c"

int main(int argc, char *argv[]) {
    int n; // število skladov
    printf("Vnesite število skladov:");
    scanf("%d", &n);
    sklad vsiSkladi[n];
    for (int i = 0; i < n; i++) {
        int v = 0;
        printf("Velikost %d. sklada:", i+1);
        scanf("%d", &v);
        init(&vsiSkladi[i], v);
        //printf("velikost: %d\n", (int) sizeof(vsiSkladi[i]));
    }

    int ukaz;
    int i = 0;
    int konec = 0;
    printf("Trenutno ste na skladu: %d\n", i+1);
    while (!konec) {
        printf("\n0 - konec programa\n"
           "1 - dodaj element na sklad\n"
           "2 - briši element s sklada\n"
           "3 - izpiši vsebino sklada\n"
           "4 - preklopi med skladi\n"
           "Vnesi ukaz:");
        scanf("%d", &ukaz);
        switch (ukaz) {
            case 0:
                konec = 1;
                for (int i = 0; i < n; i++) {
                    free(vsiSkladi[i].tab);
                }
                break;
            case 1:
                if (!isFull(vsiSkladi[i])) {
                    printf("Dodaj:");
                    int el;
                    scanf("%d", &el);
                    push(&vsiSkladi[i], el);
                }
                break;
            case 2:
                if (!isEmpty(vsiSkladi[i]))
                    printf("Izbrisan element: %d\n", pop(&vsiSkladi[i]));
                break;
            case 3:
                if (!isEmpty(vsiSkladi[i])) {
                    printf("Vsebina sklada %d:\n", i+1);
                    for (int j = 0; j < vsiSkladi[i].vrh; j++) {
                        printf("%d\n", vsiSkladi[i].tab[j]);
                    }
                }
                break;
            case 4:
                printf("Preklopite na sklad (%d-%d):",
                    1, (int) sizeof(vsiSkladi)/ (int) sizeof(sklad));
                scanf("%d", &i);
                i--;
                printf("Zdaj ste na skladu: %d\n", i+1);
                break;
            default:
                break;
        }

    }
}