#include <stdio.h>
#include <stdlib.h>

void selectionsort(int v[], int n)
{
    int i, j, aux, min;

    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(v[j] < v[min])
                min = j;
        }
        if(i!= min)
        {
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
        for(int k = 0; k < n; k++)
            printf("%d\t", v[k]);
        printf("\n");
    }
}
int main()
{
    const int n = 9;
    int v[]={71, 63, 46, 80, 39, 92, 55, 14, 27};
    selectionsort(v, n);

    /*
    14      63      46      80      39      92      55      71      27
    14      27      46      80      39      92      55      71      63
    14      27      39      80      46      92      55      71      63
    14      27      39      46      80      92      55      71      63
    14      27      39      46      55      92      80      71      63
    14      27      39      46      55      63      80      71      92
    14      27      39      46      55      63      71      80      92      
    */
}
