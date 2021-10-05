#include <iostream>

#define MAX 999
using namespace std;

int dijkstra(int a, int b, int c, int matriz[MAX][MAX]){
    int Distancia[a], MenorDistancia, pv = 0;
    bool Visitados[a];

    for(int i = 0; i < a; i++){
        Distancia[i] = 0;
        Visitados[i] = false;
    }

    Distancia[b] = -1;

    for(int i = 0; i < a; i++){
        MenorDistancia = 0;

        if(Visitados[c]) break;

        for(int j = 0; j < a; j++){
            if(!Visitados[j] && (Distancia[j] < MenorDistancia)){
                MenorDistancia = Distancia[j];
                pv = j;
            }
        }

        if(MenorDistancia == 0) break;

        Visitados[pv] = true;

        for(int j = 0; j < a; j++){
            int Soma = MenorDistancia + matriz[pv][j];
            if(Soma < Distancia[j])
                Distancia[j] = Soma;
        }
    }
    return Distancia[c];
}

int main(){
    int a, b, c, d, e, f, g, h;
    int Val[MAX][MAX];

    while(scanf("%d%d", &a, &b) && (a||b)){
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++)
                Val[i][j] = 0;
         }
         for(int i = 0; i < a; i++){
            scanf("%d%d%d", &c, &d, &e);
            Val[c][d] = e;
            if(Val[d][c] != 0){
                Val[d][c] = 0;
                Val[c][d] = 0;
            }
         }

         scanf("%d", &f);

         for(int i = 0; i < f; i++){
            scanf("%d%d", &g, &h);
            int Result = dijkstra(a, g, h, Val);
            if(Result == 0)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", Result);
         }
         printf("\n");
    }
    return 0;
}
