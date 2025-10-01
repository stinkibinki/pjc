#define MAX 50
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// besede st besed: 37
// slovenija st besed: 931
typedef struct bes {
    char beseda[MAX];
    struct bes *nasl; // kazalec na naslednji element seznama
    struct bes *nCrka; // kazalec na naslednjo crko e.g. a->b, b->c etc
} beseda;

typedef int fIsci(beseda *, char *);

void dodajU(beseda **b, beseda **z) {
    if (*z == NULL) { // ce je seznam prazen
        (*b)->nasl = NULL;
        *z = *b;
    } else { // ima vsaj 1 element
        beseda *t = *z;
        if (strcmp((*b)->beseda, (*z)->beseda) < 0) { // na zacetku
             (*b)->nasl = *z;
             *z = *b;
        } else {
            while (t->nasl != NULL && (strcmp((*b)->beseda, t->nasl->beseda) > 0))
                t = t->nasl;
            if (t->nasl == NULL) { // ce je zadna beseda
                (*b)->nasl = NULL;
                t->nasl = *b;
            } else if (strcmp((*b)->beseda, t->beseda) > 0
                && strcmp((*b)->beseda, t->nasl->beseda) != 0) { // ce je nekje vmes
                (*b)->nasl = t->nasl;
                t->nasl = *b;
            }
        }
    }
}

void izpisi(beseda* z) {
    beseda *t = z;
    int i = 0;
    while (t != NULL) {
        printf("%s\n", t->beseda);
        t = t->nasl;
        i++;
    }
    printf("St besed: %d\n", i);
}

int poisci(beseda *z, char *word) {
    int i = 0;
    beseda *t = z;
    while (strcmp(word, t->beseda) != 0) {
        if (t->nasl == NULL) return -1;
        t = t->nasl;
        i++;
    }
    return i;
}

int poisciHitreje(beseda *z, char *word) {
    int i = 0;
    beseda *t = z;
    while (strcmp(word, t->beseda) != 0) {
        if (word[0] > t->beseda[0]) {
            t = t->nCrka;
            i++;
        } else {
            if (t->nasl == NULL || word[0] < t->beseda[0]) return -1;
            t = t->nasl;
            i++;
        }
    }
    return i;
}

int povprecnoIskanje(fIsci i, beseda *z) {
    int vsota = 0;
    int stBesed = 0;
    beseda *t = z;
    while (t->nasl != NULL) {
        vsota += i(z, t->beseda);
        stBesed++;
        t = t->nasl;
    }
    vsota += poisci(z, t->beseda);
    stBesed++;
    return vsota/stBesed;
}

void dopolniSeznam(beseda *z) {
    beseda *u = z; // zadnja unique crka
    beseda *t = u->nasl;
    while (t != NULL) {
        if (u->beseda[0] < t->beseda[0]) {
            u->nCrka = t;
            u = t;
        } else u->nCrka = NULL;
        t = t->nasl;
    }
}

void pocistiSeznam(beseda *z) {
    while (z != NULL) {
        free(z);
        z = z->nasl;
    }
}

int main(int argc, char *argv[]) {
    FILE *f = fopen("../res/besede.txt", "r");

    beseda *z = NULL;
    while (!feof(f)) {
        beseda *b = malloc(sizeof(beseda));
        fscanf(f, "%49[a-zA-Z]%*[^a-zA-Z]", b->beseda);
        for (int i = 0; i < strlen(b->beseda); i++) {
            b->beseda[i] = (char) tolower(b->beseda[i]);
        }
        dodajU(&b, &z);
    }
    fclose(f);
    izpisi(z);
    dopolniSeznam(z);
    //printf("%d\n", poisci(z, "bir"));
    //printf("povp iskanje: %d\n", povprecnoIskanje(z));

    // while(1) {
    //     char trb[MAX];
    //     printf("vpisi iskano besedo:");
    //     scanf("%s", trb);
    //     printf("%d\n", poisci(z, trb));
    //     printf("%d\n", poisciHitreje(z, trb));
    // }

    printf("PI1: %d\n", povprecnoIskanje(poisci, z));
    printf("PI1: %d\n", povprecnoIskanje(poisciHitreje, z));

    pocistiSeznam(z);

}
