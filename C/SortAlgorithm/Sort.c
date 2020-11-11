#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int leitura(int *V, int tam)
{
    printf("\nDigite os valores : ");
    for(int i = 0; i < tam; i++)
        scanf("%d", (V+i));
}

void bubble(int *V, int tam) //1
{
    int aux = 0, Cont = 0, *Vp;
    Vp = malloc(tam * sizeof(int));

    for(int i =0; i < tam; i++)
        *(Vp+i) = *(V+i);

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = 0; j < tam-1-i; j++)
        {
            if(*(Vp+j) > *(Vp+j+1))
            {
                aux = *(Vp+j);
                *(Vp+j) = *(Vp+j+1);
                *(Vp+j+1) = aux;
                Cont++;
            }
        }
    }
    system("cls");
    printf("Crescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(Vp+i));
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
    free(Vp);
    Vp = NULL;
}

void selection(int *V, int tam) //2
{
    int min, aux, Cont, *Vp;
    Vp = malloc(tam * sizeof(int));

    for(int i =0; i < tam; i++)
        *(Vp+i) = *(V+i);

    Cont = 0;
    for(int i = 0; i < tam-1; i++)
    {
        min = i;
        for(int j = i+1; j < tam; j++)
        {
            if(*(Vp+j) < *(Vp+min))
                min = j;
        }
        if(i!= min)
        {
            aux = *(Vp+i);
            *(Vp+i) = *(Vp+min);
            *(Vp+min) = aux;
            Cont++;
        }
    }
    system("cls");
    printf("Crescente:\n\t");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(Vp+i));
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
    free(Vp);
    Vp = NULL;
}

void insertion(int *V, int tam) //3
{
    system("cls");
    int i, j, min, Cont = 0, *Vp;
    Vp = malloc(tam * sizeof(int));

    for(int i =0; i < tam; i++)
        *(Vp+i) = *(V+i);

    for(i = 0; i < tam; i++)
    {
        min = *(Vp+i);
        j = i-1;
        while(j >= 0 && *(Vp+j) > min)
        {
            *(Vp+j+1) = *(Vp+j);
            j--;
            Cont++;
        }
        *(Vp+j+1) = min;
    }
    printf("Crescente\n\t");
    for(i = 0; i < tam; i++)
        printf("%d\t", *(Vp+i));
    printf("\nContador : %d\n", Cont);

    Cont = j = min = 0;
    for(i = 0; i <  tam; i++)
    {
        min = *(V+i);
        j = i-1;
        while(j >= 0 && *(V+j) < min)
        {
            *(V+j+1) = *(V+j);
            j--;
            Cont++;
        }
        *(V+j+1) = min;
    }
    printf("\nDecrescente\n\t");
    for(i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\nContador : %d", Cont);
    free(Vp);
    Vp = NULL;
}

void intercalar(int *V, int *R, int ini1, int ini2, int fim2)
{
    int in1 = ini1, in2 = ini2, fim1 = in2-1, au = 0, i;
    while(in1 <= fim1 && in2 <= fim2)
    {
        if (*(V+in1) < *(V+in2))
            *(R+au++) = *(V+in1++);
        else
            *(R+au++) = *(V+in2++);
    }
    while(in1 <= fim1)
        *(R+au++) = *(V+in1++);

    while(in2 <= fim2)
        *(R+au++) = *(V+in2++);

    for(i =0; i < au; i++)
        *(V+i+ini1) = *(R+i);
}

int merge(int *V,int *R,int esq,int dir)
{
    int meio;

    if (esq < dir)
    {
        meio = (esq+dir)/2;
        merge(V, R, esq, meio);
        merge(V, R, meio+1, dir);
        intercalar(V, R, esq, meio+1, dir);
    }
}

void mostramerge(int *V, int tam)
{
    printf("Crescente:\n\t");
    for(int i =0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\n");
}

void intercalard(int *V, int *R, int ini1, int ini2, int fim2)
{
    int in1 = ini2, in2 = ini1, au = 0, i, fim1 = in2-1;
    while(in1 >= fim1 && in2 >= fim2)
    {
        if (*(V+in1) > *(V+in2))
            *(R+au++) = *(V+in1++);
        else
            *(R+au++) = *(V+in2++);
    }
    while(in1 >= fim1)
        *(R+au++) = *(V+in1++);

    while(in2 >= fim2)
        *(R+au++) = *(V+in2++);

    for(i =0; i < au; i++)
        *(R+i)=*(V+i+ini1);
}

int merged(int *V,int *R,int esq2,int dir2)
{
    int meio;

    if (esq2 > dir2)
    {
        meio = (esq2+dir2)/2;
        merged(V, R, esq2, meio);
        merged(V, R, meio+1, dir2);
        intercalard(V, R, esq2, meio+1, dir2);
    }
}

void mostramerged(int *V, int tam)
{
    printf("Decrescente:\n\t");
    for(int i =tam-1; i > -1; i--)
        printf("%d\t", *(V+i));
}


int sequencial(int *V, int tam, int procura) //5 1
{
    for(int i = 0; i < tam; i++)
    {
        if(*(V+i) == procura)
            printf("Achou i : %d", i+1);
    }
}

int binario(int *V, int tam, int procura) //5 2
{
    int meio, fim = (tam-1), i = 0, g = 0, aux = 0, Cont = 0;


    for(int i = 0; i < tam-1; i++)
    {
        for(int j = 0; j < tam-1-i; j++)
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
    printf("Vetor ordenado: ");
    for(int i = 0; i < tam; i++)
        printf("%d\t", *(V+i));
    printf("\n");

    while(fim >= i)
    {
        meio = (i+fim)/2;
        if(procura == *(V+meio))
            return 1;
        else
        {
            if(procura < *(V+meio))
                fim = meio-1;
            else
                i = meio+1;
        }
    }
    return 0;
}

int main()
{
    system("color 6");

    auto *V, *R, tipo, tam, procura, esq = 0, dir, esq2, dir2 = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    dir=esq2= tam-1;
    V = malloc(tam * sizeof(int));
    R = malloc(tam * sizeof(int));

    printf("\n1- Para Bubble Sort\n2- Para Selection Sort\n3- Para Insertion Sort\n4- Para Merge Sort\n5- Para Buscar um numero\n");
    scanf("%d", &tipo);
    system("cls");

    switch(tipo)
    {
    case 1:
        printf("Bubble Escolhido.\n");
        leitura(V, tam);
        bubble(V, tam);
        break;

    case 2:
        printf("Selection Escolhido.\n");
        leitura(V, tam);
        selection(V, tam);
        break;

    case 3:
        printf("Insertion Escolhido.\n");
        leitura(V, tam);
        insertion(V, tam);
        break;

    case 4:
        printf("Merge Escolhido.\n");
        leitura(V, tam);
        merge(V, R, esq, dir);
        mostramerge(V, tam);
        merged(V, R, esq, dir);
        mostramerged(V, tam);
        break;

    default:
        printf("1- Sequencial\n2- Binario\n");
        scanf("%d", &tipo);
        system("cls");

        switch(tipo)
        {
        case 1:
            printf("Busca sequencial Escolhida.\n");
            printf("digite o valor a ser procurado :  ");
            scanf("%d", &procura);
            leitura(V, tam);
            sequencial(V, tam, procura);
            break;

        default:
            printf("Busca binaria Escolhida.\n");
            printf("digite o valor a ser procurado :  ");
            scanf("%d", &procura);
            leitura(V, tam);
            printf("%d",binario(V, tam, procura));
        }
    }
    free(V);
    V = NULL;
}
