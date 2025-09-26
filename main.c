#include <stdio.h>

void odstevanje(int n) {
    for (int i=n; i>=0; i--) {
        printf("%d\n", i);
    }
}

int main() {
    int n = 10;
    odstevanje(10);
}