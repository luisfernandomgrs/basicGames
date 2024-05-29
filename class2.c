#include <stdio.h>

int main() {
    int notas[10];

    notas[0] = 10;
    notas[2] = 9;
    notas[3] = 8;
    notas[5] = 4;
    notas[9] = 10;

    printf("Your avaliation are: %d, %d %d, %d, %d\n", notas[0], notas[2], notas[3], notas[5], notas[9]);

    return 0;
}