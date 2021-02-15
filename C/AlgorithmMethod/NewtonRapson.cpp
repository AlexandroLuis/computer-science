#include<bits/stdc++.h>
#define Erro 0.001
using namespace std;

/** Função Inicial **/
double Funcao(double Valor){
    return Valor*Valor*Valor - Valor*Valor + 2;
}

/** Função Derivada **/
double FuncaoDerivada(double Valor){
    return 3*Valor*Valor - 2*Valor;
}

/** Médodo newton-Raphson **/
void newtonRaphson(double Valor){
    double h = Funcao(Valor) / FuncaoDerivada(Valor);
    int i = 0;

    while(abs(h) >= Erro){
        h = Funcao(Valor)/FuncaoDerivada(Valor);
        i++;

        Valor = Valor - h;
        cout << "No instante " << i << " o Valor da Raiz e: " << Valor << endl;
    }
}

int main(){
    double Valor = -20; /** Valor Inicial Assumido **/
    newtonRaphson(Valor);
    return 0;
}
