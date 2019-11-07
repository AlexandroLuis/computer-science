#include <stdio.h>
#include <stdlib.h>

void mult()
{
    int R = 1, X, Y, i;

    scanf("%d", &X);
    scanf("%d", &Y);

    for(i = 0; i < Y; i++)
    {
       R *= X;
    }
    printf("%d", R);

}

int main()
{
    mult();
    return 0;
}
