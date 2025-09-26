#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct tocka {
    char ime [5];
    float x;
    float y;
}t;

// uredi tabelo tab velikosti n
// nacin 1 -> po abecedi, nacin 2 -> po oddaljenosti od koor izhodisca
void uredi(t tab[], int n, int nacin) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((nacin == 1 && (strcmp(tab[j].ime, tab[j+1].ime) > 0)) ||
                (nacin == 2 && (fabs(tab[j].x) + fabs(tab[j].y) > fabs(tab[j+1].x) + fabs(tab[j+1].y)))) {
                //A > B -> -1
                char tmp[5];
                strcpy(tmp, tab[j].ime);
                strcpy(tab[j].ime, tab[j+1].ime);
                strcpy(tab[j+1].ime, tmp);

                // zamenjaj elementa na j-tem in (j+1)-tem mestu
                float tmp1  = tab[j].x;
                tab[j].x   = tab[j+1].x;
                tab[j+1].x = tmp1;

                float tmp2  = tab[j].y;
                tab[j].y    = tab[j+1].y;
                tab[j+1].y  = tmp2;
            } else if (nacin != 1 && nacin != 2) {
                printf("Napacen nacin");
                exit(-1);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    FILE *dat = fopen(argv[1], "r");

    t tocke[N];
    int i = 0;
    while (!feof(dat)) {
        fscanf(dat, "%s %f %f", tocke[i].ime, &tocke[i].x, &tocke[i].y);
        i++;
    }
    fclose(dat);

    // uredi po abecedi
    uredi(tocke, i, 1);
    for (int j = 0; j < i; j++) {
        printf("%s %.2f %.2f\n", tocke[j].ime, tocke[j].x, tocke[j].y);
    }

    printf("\n");

    // uredi po oddaljenosti od koor izhodisca
    uredi(tocke, i, 2);
    for (int j = 0; j < i; j++) {
        printf("%s %.2f %.2f\n", tocke[j].ime, tocke[j].x, tocke[j].y);
    }

}
