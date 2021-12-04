#include <stdio.h>
#include <stdlib.h>

void parouimpar()
{
    int A;

    scanf("%d", &A);
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
    parouimpar();
    return 0;
}
