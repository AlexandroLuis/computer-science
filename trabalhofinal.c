#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int leitura(int *V, int tam)
{
    printf("Digite os valores\n");
    for(int i = 0; i < tam; i++)
        scanf("%d", (V+i));
}

void bubble(int *V, int tam)
{
    int aux = 0, Cont;
    Cont = 0;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = 0; j < tam-1- i; j++)
        {
            if(*(V+j) > *(V+j+1))
            {
                aux = *(V+j);
                *(V+j) = *(V+j+1);
                *(V+j+1) = aux;
                Cont++;
            }
        }
    }
    system("cls");
    printf("Crescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\nContador: %d", Cont);

    Cont = 0;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = 0; j < tam-1- i; j++)
        {
            if(*(V+j) < *(V+j+1))
            {
                aux = *(V+j);
                *(V+j) = *(V+j+1);
                *(V+j+1) = aux;
                Cont++;
            }
        }
    }
    printf("\n\nDecrescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\nContador: %d", Cont);

}

void selection(int *V, int tam)
{
    auto min, aux, Cont, nome;

    Cont = 0;
    for(int i = 0; i < tam-1; i++)
    {
        min = i;
        for(int j = i+1; j < tam; j++)
        {
            if(*(V+j) < *(V+min))
                min = j;
        }
        if(i!= min)
        {
            aux = *(V+i);
            *(V+i) = *(V+min);
            *(V+min) = aux;
            Cont++;
        }
    }
    system("cls");
    printf("Crescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\nContador: %d", Cont);

    Cont = 0;
    for(int i = 0; i < tam-1; i++)
    {
        min = i;
        for(int j = i+1; j < tam; j++)
        {
            if(*(V+j) > *(V+min))
                min = j;
        }
        if(i!= min)
        {
            aux = *(V+i);
            *(V+i) = *(V+min);
            *(V+min) = aux;
            Cont++;
        }
    }
    printf("\n\nDecrescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\nContador: %d", Cont);

}

void insertion(int *V, int tam)
{

}

void merge(int *V, int tam)
{

}

int main()
{
    system("color 6");

    auto *V, tipo, tam;

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
