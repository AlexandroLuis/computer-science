#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 5;
    int v[]= {9, 8, 4, 6, 3}, i, j, aux = 0;

    for(i = 0; i < N; i++)
        printf("%d\t", v[i]);

     printf("\n");

    for(i = 0; i < N-1; i++)
    {

        for(j = 0; j < N-1- i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

    for(i = 0; i < N; i++)
        printf("%d\t", v[i]);
}
