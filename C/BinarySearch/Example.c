#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Sort(int *V, int tam){
    int aux = 0;

    for(int i = 0; i < tam-1; i++){
        for(int j = 0; j < tam-1-i; j++){
            if(*(V+j) > *(V+j+1)){
                aux = *(V+j);
                *(V+j) = *(V+j+1);
                *(V+j+1) = aux;
            }
        }
    }
}

bool BinarySearch(int *V, int tam, int procura){
    int meio, fim = (tam-1), i = 0, aux = 0;
    Sort(V, tam);

    while(fim >= i){
        meio = (i+fim)/2;
        if(procura == *(V+meio))
            return true;
        else{
            if(procura < *(V+meio))
                fim = meio-1;
            else
                i = meio+1;
        }
    }
    return false;
}


int main(){
    int *V, tam, procura;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    V = malloc(tam * sizeof(int));

    printf("\ndigite o valor a ser procurado :  ");
    scanf("%d", &procura);

    printf("\nDigite os valores:\n");
    for(int i = 0; i < tam; i++)
        scanf("%d", (V+i));

    (BinarySearch(V, tam, procura) == true)?printf("Encontrado!"):printf("Não Encontrado!");

    free(V);
    V = NULL;
}
