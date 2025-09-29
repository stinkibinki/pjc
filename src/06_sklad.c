#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int n; // velikost sklada
    int vrh; // kje se nahajamo
    int *tab; // sklad itself
}sklad;

void init(sklad *s, int n) {
    s->n = n;
    s->tab = (int *) malloc(sizeof(int)*n);
    s->vrh = 0;
}

void push(sklad *s, int x) {
    s->tab[s->vrh] = x;
    s->vrh++; // kaze na "praznega"
}

int pop(sklad *s) {
    s->vrh--;
    return s->tab[s->vrh];
}

int isEmpty(sklad s) {
    if (s.vrh == 0) {
        printf("Sklad je prazen.\n");
        return 1;
    }
    return 0;
}

int isFull(sklad s) {
    if (s.vrh == s.n) {
        printf("Sklad je poln!\n");
        return 1;
    }
    return 0;
}