#include <stdio.h>
#include <stdlib.h>
void incrementa_num(int *, int *);


void incrementa_num(int *A, int *C)
{
    *C = *A % 4;

}

int main()
{
    int A, C;

    scanf("%d", &A);
    incrementa_num(&A, &C);

    if( C != 0)
    {
        printf("Não e divisivel por 4");
    }
    else
    {
        printf("Divisivel por 4");
    }

    return 0;
}
