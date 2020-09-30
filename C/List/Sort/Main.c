#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>

/**
    Estrutura Piloto, armazena informações na fila de prioridades
**/
typedef struct Piloto{
    int id;
    char nome[30];
    char equipe[30];
    int pontuacao;
    struct Piloto *prox;
}data;

/**
    Função para limpar o ponteiro piloto da fila
**/
void limpar(data **piloto){
	*piloto = NULL;
}

/**
    Função push, para armazenar os valores da estrutura piloto no ponteiro piloto
**/
void push(data **piloto, int i, char nome[], char equipe[]){
    data *aux_piloto, *fim;

    aux_piloto = (data*)malloc (sizeof(data));

    /**
        Informações a serem guardadas na estrutura piloto
        id, nome, equipe, e pontuação
    **/
	aux_piloto->id = i;
	for(int i = 0; i < 30; i++){
        aux_piloto->nome[i] = nome[i];
        aux_piloto->equipe[i] = equipe[i];
	}
	aux_piloto->prox = NULL;
	aux_piloto->pontuacao = 0;

    /**
        LISTA LIGADA SIMPLES, ARMAZENANDO VALOR NA ULTIMA POSIÇÃO
    **/
	if(*piloto == NULL)
        *piloto = aux_piloto;
	else{
		fim = *piloto;
		while(fim->prox != NULL)
			fim = fim->prox;
		fim->prox = aux_piloto;
		*piloto = fim;
	}
}

/**
    Função para incrementar a pontuação obtida pelos pilotos na corrida
**/
void atualizarpontuacao(data **piloto, int j, int colocacao){
    data *aux_piloto = *piloto;
    while(aux_piloto->id != j){
        aux_piloto = aux_piloto->prox;
    }
    aux_piloto->pontuacao += colocacao;
}

/**
    Função para retornar a pontuação de acordo com a colocação
**/
int pontuacao(int colocacao){
    if(colocacao > 0 && colocacao < 4)
        return 10;
    else if(colocacao > 3 && colocacao < 7)
            return 7;
        else if(colocacao < 21 && colocacao != 0)
                return 5;
            else
                return 0;
}

/**
    Função para desenhar a interface
**/
void ajustar(){
    int i;
    for(i = 0; i < 50; i++)
        printf("-");
    printf("\n");
}

/**
    Função para mostrar a colocação dos pilotos
**/
void mostrarcolocacao(data **piloto){
    data *aux_piloto;
    int i = 1;

    aux_piloto = *piloto;
    while(aux_piloto != NULL){
        ajustar();
        printf("PILOTO %s DA EQUIPE %s\n", aux_piloto->nome, aux_piloto->equipe);
        printf("FICOU NA COLOCAÇÃO %d, COM %d PONTOS.\n", i, aux_piloto->pontuacao);
        aux_piloto = aux_piloto->prox;
        i++;
    }
    ajustar();
}

/**
    Função para fazer a ordenação dos pilotos de acordo com a sua pontuação
    FALTA :
            PRECISA ORDENAR O PILOTO PASSANDO PILOTO PARA SORT
**/
void Sort(data **piloto){
	data *N, *P = NULL;
	int trade;

	N = (data*) malloc(sizeof(data));
	N = *piloto;

	while(N != NULL){
        P = N;

        while(P->prox != NULL){
            if(P->pontuacao > P->prox->pontuacao){
                trade = P->pontuacao;
                P->pontuacao = P->prox->pontuacao;
                P->prox->pontuacao = trade;
            }
            P = P->prox;
        }
        N = N->prox;
	}
}
/**

**/
int main(){
    const int PL = 2, CR = 2;
    char nome[30], equipe[30];
    int colocacao, i, j;
    data *piloto;

    /**
        Funções para UI
    **/
    setlocale(LC_ALL, "Portuguese");
    system("color 3");
    limpar(&piloto);

    /**
        ARMAZENAR INFORMAÇÕES DO PILOTO NUMA LISTA SIMPLES
    **/
    for(i = 0; i < PL; i++){
        ajustar();
        printf("DIGITE AS INFORMAÇÕES DE CADASTRO DO PILOTO %d!\n", i+1);
        ajustar();
        printf("\nDigite o nome do piloto:\t", i+1);
        scanf("%s", &nome);
        printf("\nDigite o nome da equipe:\t");
        scanf("%s", &equipe);
        push(&piloto, i, &nome, &equipe);
        system("cls");
    }

    /**
        PONTUAÇÃO DOS PILOTOS NAS CORRIDAS
    **/
    for(i = 0; i < CR; i++){
        for(j = 0; j < PL; j++){
            ajustar();
            printf("DIGITE OS RESULTADOS DO PILOTO %d NA CORRIDA %d!\n",j+1, i+1);
            ajustar();
            printf("\ndigite a Posição do piloto na corrida: ");
            scanf("%d", &colocacao);
            fflush(stdin);
            colocacao = pontuacao(colocacao);/** 0 para não terminou **/
            atualizarpontuacao(&piloto, j, colocacao);
            system("cls");
        }
    }

    /**
        Atualiza e mostra a pontuação dos pilotos
    **/
    Sort(&piloto);
    printf("PONTUAÇÃO FINAL DO CAMPEONATO!\n");
    mostrarcolocacao(&piloto);
}
