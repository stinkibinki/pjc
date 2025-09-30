#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *args[]) {
    printf("%d\n", (int) RAND_MAX);
    // printf("st. podanih argumentov: %d", argc);
    // for (int i = 1; i < argc; i++)    
    //     printf("argument %d: %s", i, args[i]);
    // return 0;


    // random
    // srand(time(NULL)); //stdlib, time
    // int x = rand();
    // printf("%d", x);

    // char c;
    // while (c = getchar())
    //     printf("%c\n", c);

    char str[100];
    int n[10] = {0};
    scanf("%s", str);
    printf("%s\n", str);
}