#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, s, soma = 0;

    scanf("%d", &n);
    int x[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &s);
        s += s;
        x[s] = 1;
        printf("%d", x[s]);
    }
  
    printf("%d", s);
}
