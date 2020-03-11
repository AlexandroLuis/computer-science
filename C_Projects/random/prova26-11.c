#include <stdio.h>
#include <stdlib.h>

/* EXERCICIO 1:
void insert(int *V, int tam)
{
    for(int i =0; i < tam; i++)
        scanf("%d", (V+i));
}
void modo(int *V, int tam)
{
    insert(V, tam);
    int aux = 0, j;

    for(int i = 0; i < tam-1; i++)
    {
        j = i;
        while(*(V+j+1) > *(V+j))
        {
            aux = *(V+j+1);
            *(V+j+1) = *(V+j);
            *(V+j) = aux;
            j--;
        }
        aux =0;
    }
}

void show(int *V,int tam)
{
    modo(V, tam);
    for(int i = 0; i < tam; i++)
        printf("%d", *(V+i));
}
int main()
{
    int *V, tam;
    scanf("%d", &tam);
    V = malloc(tam*sizeof(int));

    show(V, tam);
}
*/
/* EXERCICIO 2:
void bubble(int *V, int tam)
{
    int aux = 0;

    for(int i = 0; i < tam-1; i++)
    {
        for(int j =0; j < tam-i; j++)
        {
            if(*(V+j) > *(V+j+1))
            {
                aux = *(V+j);
                *(V+j) = *(V+j+1);
                *(V+j+1) = aux;
            }
        }
    }
    for(int i = 0; i < tam; i++)
        printf("%d", *(V+i));
}
int main()
{
    int *V, tam;
    scanf("%d", &tam);
    V = malloc(tam*sizeof(int));
    for(int i =0; i < tam; i++)
        scanf("%d", (V+i));

    bubble(V, tam);
}

*/
/* EXERCICIO 3:
int busca(int V[], int tam, int procura)
{
    int g = 0, inicio = 0, fim = tam, meio;

    while(fim >= inicio)
    {
        meio = (inicio+fim)/2;
        if(V[meio] == procura)
        {
            return 1;
        }
        else
        {
            if(procura > meio)
            {
                fim  = meio -1;
            }
            else
            {
                inicio  = inicio +1;
            }
        }
    }
    return 0;
}

int main()
{
    int tam, procura;
    printf("tam\t");
    scanf("%d", &tam);
    int V[tam];
    printf("vet\t");
    for(int i =0; i < tam; i++)
        scanf("%d", &V[i]);
    printf("procura\t");
    scanf("%d", &procura);

    printf("%d", busca(V, tam, procura));

}

*/
