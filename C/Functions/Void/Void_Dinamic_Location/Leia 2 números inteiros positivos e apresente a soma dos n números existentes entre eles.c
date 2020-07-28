#include <stdio.h>
#include <stdlib.h>
void prog(int , int , int *);

void prog(int A, int B, int *C)
{
    int i;

    for(i = A+1; i < B; i++)
    {
        *C += i;
    }
}

int main()
{
    int A, B, C = 0;

    scanf("%d %d", &A, &B);
    prog(A, B, &C);
    printf("%d", C);
    return 0;
}
