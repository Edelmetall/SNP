#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 5; // any positive number
    
    printf("Gib eine positive Zahl an: \n");
    scanf("%d", &a);

    if(a > 0 && ((a & (a - 1)) == 0)){
        printf("%d is a power of 2 \n", a);
    } else {
	printf("%d is not a power of 2 \n", a);
    }

    return EXIT_SUCCESS;
}
