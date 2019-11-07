#include <stdio.h>
#include <stdlib.h>

void raio()
{
    const int PI = 3.1415;
    int R, V;

    scanf("%d", &R);
    V = (4*PI*(R*R*R))/3;
    printf("%d", V);
}

int main()
{
    raio();
    return 0;
}
