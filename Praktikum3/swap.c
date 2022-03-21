#include <stdlib.h>
#include <stdio.h>

int main(){
    int a = 3;
    int b = 4;
    printf("a: %d; b: %d\n", a, b);

    a = a + b; // a = 7 , b = 4
    b = a - b; // a = 7, b = 3
    a = a - b; // a = 4 b = 3

    printf("a: %d; b: %d\n", a, b);
    return EXIT_SUCCESS;
}
