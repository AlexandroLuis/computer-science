#include <stdio.h>
#include <stdlib.h>

void soma(int a, int b)
{
    int r;

    r = a + b;
    printf("%d",r);
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    soma(a, b);
    return 0;
}
