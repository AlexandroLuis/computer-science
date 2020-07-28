#include <stdio.h>
#include <stdlib.h>

int leitura(int *V, int tam){
    printf("\nDigite os valores : ");
    for(int i = 0; i < tam; i++)
        scanf("%d", (V+i));
}

int binario(int *V, int tam, int procura){
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


int main(){
    int *V, tam, procura;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    V = malloc(tam * sizeof(int));

  
    printf("Busca binaria Escolhida.\n");
    printf("digite o valor a ser procurado :  ");
    scanf("%d", &procura);
    leitura(V, tam);
    printf("%d",binario(V, tam, procura));

    free(V);
    V = NULL;
}