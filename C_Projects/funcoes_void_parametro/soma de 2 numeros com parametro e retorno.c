#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b)
{
    int r;

    r = a + b;
    return r;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d", soma(a, b));
    return 0;
}
