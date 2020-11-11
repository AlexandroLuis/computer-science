//EM CONSTRUÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>

typedef struct Player{
    char nome[30];
    int classe;
    struct Player *prox;
}data;

void salvar(int **jogador, int tipo, char nome[]){
    data *aux_jogador;
    aux_jogador = (data*)malloc(sizeof(data));
    for(int i = 0; i < 10; i++)
        aux_jogador->nome[i] = nome[i];
    aux_jogador->classe = tipo;

    *jogador = aux_jogador;
}
void Mapa(int Cenario[][50], int T){
    int i, j, marcacao = 1, fimmapa = 0;
    bool continua = true;

    while(continua){
        if(marcacao == 1){
            for(i = 0; i < T; i++)
                printf("-");
            printf("\n");
        }
        else{

            if(fimmapa = 1)
                marcacao = 1;
        }
        marcacao = 0;
    }
}

int main(){
    const int T = 50;
    int Cenario[T][T];
    char nome[50];
    int tipo, i;
    data *jogador;

    setlocale(LC_ALL, "Portuguese");

    for(i = 0; i < 2; i ++){
        printf("Bem vindo Jogador %d, digite seu nome!\n", i+1);
        scanf("%s", &nome);
        printf("%s é seu nome? Não para um:", nome);
        printf("\n1 - Guerreiro\n2 - Mago\n3 - Arqueiro\n");
        scanf("%d", &tipo);
        salvar(&jogador, tipo, nome);
        system("cls");
    }


    //Mapa(Cenario, T);

}
