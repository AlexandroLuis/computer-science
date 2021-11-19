#include <stdio.h>
#include <stdlib.h>

void media()
{
    float A, B;

    scanf("%f %f", &A, &B);
    //scanf("%f", &B);
    printf(“%f”,(A+B)/2);
}

int main()
{
    media();
    return 0;
}
