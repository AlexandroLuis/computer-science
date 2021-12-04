#include <stdio.h>
#include <stdlib.h>

void div4(A)
{

    if(A % 4 == 0)
    {
        printf("Divisivel por 4");
    }
    else
    {
        printf("Não divisivel por 4");
    }
}

int main()
{
    int A;

    scanf("%d", &A);
    div4(A);
    return 0;
}
