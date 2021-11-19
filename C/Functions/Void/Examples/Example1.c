#include <stdio.h>
#include <stdlib.h>

void sumseq()
{
    int A, B, S = 0, i;

    scanf("%d", &A);
    scanf("%d", &B);
    for(i = A+1; i < B; i++)
    {
      S += i;
    }
    printf("%d", S);
}

int main()
{
    sumseq();
    return 0;
}
