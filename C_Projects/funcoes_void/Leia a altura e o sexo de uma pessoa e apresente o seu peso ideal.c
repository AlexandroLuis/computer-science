#include <stdio.h>
#include <stdlib.h>

void mult()
{
    int i = 0;
    float C, altura;
    char S;

    while(i == 0)
    {
        scanf("%f", &altura);
        fflush(stdin);
        scanf("%c", &S);

        if(S == 'm')
        {
            C = (72.7 * altura) - 58;
            printf("%f", C);
        }
        else
        {
            C = (62.1 * altura) - 44.7;
            printf("%f", C);
        }
        scanf("%d", i);
    }
}

int main()
{
    mult();
    return 0;
}
