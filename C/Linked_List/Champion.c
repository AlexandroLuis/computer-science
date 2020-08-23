#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>

typedef struct Piloto{
    int id;
    char nome[30];
    char equipe[30];
    int colocacao;
    struct Piloto *prox;
}data;

void limpar(data **piloto) {
	*piloto = NULL;
}

void push(data **piloto, int i, char nome, char equipe, int colocacao){
    data *aux_piloto, *fim;

    aux_piloto = (data*)malloc (sizeof(data));
	aux_piloto->id = i;
	/*
	for(int i = 0; i < 30; i++){
        aux_piloto->nome[i] = nome[i];
        aux_piloto->equipe[i] = equipe[i];
	}
	*/
	aux_piloto->colocacao = colocacao;
	aux_piloto->prox = NULL;

	if (*piloto == NULL){
		*piloto = aux_piloto;
	}
	else {
		fim = *piloto;

		while(fim->prox != NULL) {
			fim = fim->prox;
		}
		fim->prox = aux_piloto;
	}
}

int main(){
    char nome[30], equipe[30];
    int colocacao, i;
    data *piloto;

    setlocale(LC_ALL, "Portuguese");
    system("color 3");
    limpar(&piloto);

    for(i = 0; i < 20; i++){
        printf("Digite o nome do piloto:\n");
        scanf("%s", nome);
        printf("Digite o nome ds equipe:\n");
        scanf("%s", equipe);
        printf("Digite o a colocação do piloto:\n");
        scanf("%d", colocacao);
        push(&piloto, i, nome, equipe, colocacao);
        system("cls");
    }



}
