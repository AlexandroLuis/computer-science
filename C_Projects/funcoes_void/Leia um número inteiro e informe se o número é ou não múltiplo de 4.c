#include <stdio.h>
#include <stdlib.h>

void div4()
{
    int A;

    scanf("%d", &A);
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
    div4();
    return 0;
}
