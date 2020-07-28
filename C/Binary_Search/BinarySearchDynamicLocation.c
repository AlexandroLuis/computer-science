#include <stdio.h>
#include <stdlib.h>
#define N 5

void preenche(int *V)
{
    for(int i = 0; i < N; i++)
        scanf("%d", (V+i));
}

int buscabin(int *V, int procura)
{
    int meio, fim = (N-1), i = 0;
    while(fim >= i)
    {
        meio = (i+fim)/2;
        if(procura == *(V+meio))
            return 1;
        else
        {
            if(procura < *(V+meio))
                fim = (meio - 1);
            else
            {
                if( procura > *(V+meio) )
                    i = (meio +1);
            }
            return 0;
        }

    }

}

int main()
{
    int *V, i, procura;

    V = malloc(N * sizeof(int));
    preenche(V);

    scanf("%d", &procura);

    if(buscabin(V, procura) == 1)
        printf("Achou");
    else
        printf("nao achou");
}
