#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
    if (argc != 4) {
        printf("Napačno število argumentov!");
    } else {
        int n = atoi(args[1]);
        int m = atoi(args[3]);
        for (int i = 0; i < n; i++) {
            for (int j = m * i; j > 0; j--) {
                printf("%c", '.');
            }
            printf("Pozdravljen, %s\n", args[2]);
        }
    }
}
