#include <stdio.h>
#include <string.h>

#define stBesed 100
#define dolzinaBesed 50

int main() {
    char besede[stBesed][dolzinaBesed];

    for (int i = 0; i < stBesed; i++) {
        scanf("%s", besede[i]);
        if (strcmp(besede[i], "EOF") == 0) {
            for (int j = i - 1; j >= 0; j--) {
                printf("%s\n", besede[j]);
            }
            break;
        }
        if (i == stBesed - 1) {
            for (int k = i; k >= 0; k--) {
                printf("%s\n", besede[k]);
            }
            break;
        }

    }
}
