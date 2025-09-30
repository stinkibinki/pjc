#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *ime;
    char *priimek;
    char *telefon;
} oseba;

int uredi(const void* a, const void* b) {
    oseba o1 = *(oseba *)a;
    //oseba o2 = *(oseba *)b;
    return strcasecmp(o1.priimek, (*(oseba*)b).priimek);
}

int main(int argc, char *argv[]) {
    unsigned long long rezervirano = 0;

    FILE *f = fopen("../res/osebe.txt", "r");
    int stOseb = 0;
    fscanf(f, "%d", &stOseb);

    oseba *osebe = malloc(sizeof(oseba)*stOseb);
    rezervirano += sizeof(oseba)*stOseb;

    char vrstica[100];
    for (int i = 0; i < stOseb; i++) {
        fscanf(f, "%s", vrstica);
        char *p = strtok(vrstica, ":");
        osebe[i].ime = malloc(strlen(p)+1);
        strcpy(osebe[i].ime, p);

        p = strtok(NULL, ":");
        osebe[i].priimek = malloc(strlen(p)+1);
        strcpy(osebe[i].priimek, p);

        p = strtok(NULL, ":");
        osebe[i].telefon = malloc(strlen(p)+1);
        strcpy(osebe[i].telefon, p);

        rezervirano += strlen(osebe[i].ime) +
            strlen(osebe[i].priimek) + strlen(osebe[i].telefon) + 3;
        //printf("%d", rezervirano);
        //fflush(stdout);
    }

    qsort(osebe, stOseb, sizeof(oseba), uredi);

    for (int j = 0; j < stOseb; j++) {
        printf("%s %s %s\n", osebe[j].ime, osebe[j].priimek,
            osebe[j].telefon);
        free(osebe[j].ime);
        free(osebe[j].priimek);
        free(osebe[j].telefon);
    }


    // rezerviran prostor za tabelo oseb in vsako osebo posebej
    printf("\nrezerviran prostor: %llu", rezervirano);
    free(osebe);
}
