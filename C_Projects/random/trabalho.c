#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int leitura(int V, int tam)
{
    printf("Digite os valores\n");
    for(auto i = 0; i < tam; i++)
        scanf("%d", (V+i));
}

void bubble(int V, int tam)
{

}

void selection(int V, int tam)
{

}

void insertion(int V, int tam)
{

}

void merge(int V, int tam)
{

}

int main()
{
    system("color 6");

    int *V, tipo, tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    V = malloc(tam * sizeof(int));

    printf("1- Para Bubble Sort\n2- Para Selection Sort\n3- Para Insertion Sort\n4- Para Merge Sort\n");
    scanf("%d", &tipo);
    system("cls");

    if(tipo == 1)
    {   printf("Bubble Escolhido.\n");
        leitura(V, tam);
        bubble(V, tam);
    }
    else
    {
        if(tipo == 2)
        {   printf("Selection Escolhido.\n");
            leitura(V, tam);
            selection(V, tam);
        }
        else
        {
            if(tipo == 3)
            {   printf("Insertion Escolhido.\n");
                leitura(V, tam);
                insertion(V, tam);
            }
            else
            {   printf("Merge Escolhido.\n");
                leitura(V, tam);
                merge(V, tam);
            }
        }
    }
    V = (free);
    V = NULL;
}
