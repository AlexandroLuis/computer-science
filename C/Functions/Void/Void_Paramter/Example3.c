#include <stdio.h>
#include <stdlib.h>

void parouimpar(A)
{
    if(A % 2 == 0)
    {
        printf("par");
    }
    else
    {
        printf("impar");
    }
}

int main()
{
    int A;

    scanf("%d", &A);
    parouimpar(A);
    return 0;
}
