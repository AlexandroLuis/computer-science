#include <stdio.h>
#include <stdlib.h>

int main()
{
    float A = 0.000;

    while(A < 10){
        printf("%0.3f", A);
        A += 0.001;
        printf("\n");
    }
}
