#include<stdio.h>
#include<math.h>

/** Função A Ser Executada **/
float Funcao(float x){
    return cos(x) - x*exp(x);
}

/** Método Regula Falsi **/
void regulaFalsi(float *x, float x0, float x1, float fx0, float fx1, int *Interacoes){
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*Interacoes);

    printf("%d Intecacao, Valor = %7.5f \n", *Interacoes, *x);
}

void main(){
    int Interacoes = 0, MaxIteracoes;
    float x0,x1,x2,x3,Erro;

    printf("Entre com os Valores x0 & x1,Erro Maximo e Maximo de Interacoes:\n");
    scanf("%f %f %f %d", &x0, &x1, &Erro, &MaxIteracoes);
    regulaFalsi(&x2, x0, x1, Funcao(x0), Funcao(x1), &Interacoes);

    do{
        if(Funcao(x0)*Funcao(x2) < 0)
            x1=x2;
        else
            x0=x2;

        regulaFalsi(&x3, x0, x1, Funcao(x0), Funcao(x1), &Interacoes);

        if(fabs(x3-x2) < Erro){
            printf("\nApos %d Interacoes, Raiz = %6.4f\n", Interacoes, x3);
            return 0;
        }

        x2=x3;
    }while (Interacoes < MaxIteracoes);

    printf("\nSolucao nao converge, ou numero de iteracoes insuficiente.\n");
    return 1;
}
