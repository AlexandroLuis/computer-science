#include <stdio.h>
#include <stdlib.h>

void add(int V[], int T){
    for(int i = 0; i < T; i++)
        scanf("%d", &V[i]);
}

void rem(int V[]){
    int v1;

    scanf("%d", &v1); // ler a posição do valor a ser excluido
    V[v1] = 0;// remover valor de vetor?
}

void list(int V[], int T){//MOSTRA OS ELEMENTOS DO VETOR
    for(int i = 0; i < T; i++)
        printf("%d ", V[i]);
    printf("\n");
}

void ordma(int V[], int T){// ORDENA DO MENOR AO MAIOR, BUBBLE SORT
    int aux, menor = -999;
    for(int i = 0; i < T - 1; i++){
         for(int j = 0; j < T - 1; j++){
             if(V[j] > V[j + 1]){
                 aux = V[j];
                 V[j] = V[j + 1];
                 V[j + 1] = aux;
             }
         }
     }
}

void ordme(int V[], int T){// ORDENA DO MENOR PARA O MAIOR, BUBBLE SORT
    int aux, menor = 999;
    for(int i = 0; i < T - 1; i++){
         for(int j = 0; j < T - 1; j++){
             if(V[j] < V[j + 1]){
                 aux = V[j];
                 V[j] = V[j + 1];
                 V[j + 1] = aux;
             }
         }
     }
}


int main()
{
    const int T = 5;
    int V[]={-1,-1,-1,-1,-1};
    int val = 0;

    do{
        scanf("%d", &val);//LER INSTRUÇÃO
        switch(val){
            case 1:
                add(V, T);
            break;
            case 2:
                rem(V);
            break;
            case 3:
                list(V, T);
            break;
            case 4:
                ordma(V, T);
                list(V, T);
            break;
            case 5:
                ordme(V, T);
                list(V, T);
            break;
        }
    }while(val != 0);

}
