#include <stdio.h>
#include <stdlib.h>


int main()
{
    const int N = 5;
    int V[]={5, 4, 3, 2, 1};
    int i, j, k, min;

    for(i =4; i < N; i++)
    {
        min = V[i];
        j = i-1;
        while(j >= 0 && V[j] > min)
        {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = min;

        for(k = 0; k < N; k++)
            printf("%d\t", V[k]);
        printf("\n");
    }
}
