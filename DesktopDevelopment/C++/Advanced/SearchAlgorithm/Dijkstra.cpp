#include <iostream>

#define MAX 999
int matriz[MAX][MAX];

using namespace std;

int dijkstra(int a, int b, int c){
    int Distancia[MAX], MenorDistancia, pv = 0;
    bool Visitados[MAX];

    for(int i = 1; i < a+1; i++){
        Distancia[i] = MAX;
        Visitados[i] = false;
    }

    Distancia[b] = 0;

    for(int i = 1; i < a+1; i++){
        MenorDistancia = MAX;

        if(Visitados[c]) break;

        for(int j = 1; j < a+1; j++){
            if(!Visitados[j] && (Distancia[j] < MenorDistancia)){
                MenorDistancia = Distancia[j];
                pv = j;
            }
        }

        if(MenorDistancia == MAX) break;

        Visitados[pv] = true;

        for(int j = 1; j < a+1; j++){
            int Soma = MenorDistancia + matriz[pv][j];
            if(Soma < Distancia[j])
                Distancia[j] = Soma;
        }
    }
    return Distancia[c];
}

int main(){
    int a, b, c, d, e, f, g, h;

    while(scanf("%d%d", &a, &b) && (a||b)){
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= a; j++)
                matriz[i][j] = MAX;
        }
        for(int i = 1; i <= b; i++){
            scanf("%d%d%d", &c, &d, &e);
            matriz[c][d] = e;
            if(matriz[d][c] != MAX)
                matriz[d][c] = matriz[c][d] = 0;
        }

        scanf("%d", &f);
        for(int i = 0; i < f; i++){
            scanf("%d%d", &g, &h);
            int Result = dijkstra(a, g, h);
            if(Result == MAX)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", Result);
        }
        printf("\n");
    }
    return 0;
}
