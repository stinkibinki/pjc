#define N 100
#define M 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int stevila[N];

    // generiramo N random stevil
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        stevila[i] = rand() % 100 + 1;
        printf("%d ", stevila[i]);
    }
    printf("\n");
    int ponavljanja[M] = {0};
    for (int j = 0; j < M; j++) {
        for (int k = 0; k < N; k++) {
            if (j*10 + 1 <= stevila[k] && stevila[k] <= ((j+1)*10)) {
                ponavljanja[j] += 1;
            }
        }

    }
    int najvecji = 0;
    for (int l = 0; l < M; l++) {
        if (ponavljanja[l] > najvecji) najvecji = ponavljanja[l];
        //printf("%d ", ponavljanja[l]);
    }
    //printf("\n");

    for (int o = najvecji; o > 0; o--) {
        for (int p = 0; p < M; p++) {
            printf("   %c   ", ponavljanja[p] >= o ? 'o' : ' ');
        }
    printf("\n");
    }
    for (int r = 0; r < M*7; r++) putchar('-');
    printf("\n");
    for (int s = 0; s < M; s++) printf("%3d-%-3d", s*10+1, (s+1)*10);
}
