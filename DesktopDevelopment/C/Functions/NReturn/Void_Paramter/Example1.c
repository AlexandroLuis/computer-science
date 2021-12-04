#include <stdio.h>
#include <stdlib.h>

void sumseq(int A, int B)
{
    int S = 0, i;

    for(i = A+1; i < B; i++)
    {
      S += i;
    }
    printf("%d", S);
}

int main()
{
    int A, B;

    scanf("%d %d", &A, &B);
    sumseq(A, B);
    return 0;
}
