#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>

typedef struct Piloto{
    int id;
    char nome[30];
    char equipe[30];
    int terminou;
    int pontuacao;
    struct Piloto *prox;
    struct Piloto *prev;
}data;

void limpar(data **piloto) {
	*piloto = NULL;
}

void push(data **piloto, int i, char nome[], char equipe[]){
    data *aux_piloto, *fim;

    aux_piloto = (data*)malloc (sizeof(data));
	aux_piloto->id = i;
	for(int i = 0; i < 30; i++){
        aux_piloto->nome[i] = nome[i];
        aux_piloto->equipe[i] = equipe[i];
	}
	aux_piloto->prox = NULL;
	aux_piloto->pontuacao = 0;
    /* LISTA LIGADA SIMPLES, ARMAZENANDO VALOR NA ULTIMA POSIÇÃO */
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

void atualizarpontuacao(data **piloto, int j, int colocacao){
    data *aux_piloto = *piloto;
    while(aux_piloto->id != j){
        aux_piloto = aux_piloto->prox;
    }
    aux_piloto->pontuacao += colocacao;
}

int pontuacao(int colocacao, char terminou){
    if(colocacao < 4 && terminou == 'S' || terminou == 's')
        return 10;
    else if(colocacao > 3 && colocacao < 7 && terminou == 'S' || terminou == 's')
            return 7;
        else if(colocacao < 20 && terminou == 'S' || terminou == 's')
                return 5;
            else
                return 0;
}

void ajustar(){
    int i;
    for(i = 0; i < 50; i++)
        printf("-");
    printf("\n");
}

void mostrarcolocacao(data **Colocacao){
    data *aux_piloto;
    int i = 1;

    aux_piloto = *Colocacao;
    while(aux_piloto != NULL){
        ajustar();
        printf("PILOTO %s DA EQUIPE %s\n", aux_piloto->nome, aux_piloto->equipe);
        printf("FICOU NA COLOCAÇÃO %d, COM %d PONTOS.\n", i, aux_piloto->pontuacao);
        aux_piloto = aux_piloto->prox;
        i++;
    }
    ajustar();
}

void atualizarpilotos(data **piloto, data **Colocacao){
    data *aux_piloto, *auxtemp_piloto;

    aux_piloto = *piloto;
    auxtemp_piloto = (data*)malloc(sizeof(data));

    if (*Colocacao == NULL)
        *Colocacao = piloto;
    else{
        while(aux_piloto->prox != NULL && aux_piloto->pontuacao < aux_piloto->prox->pontuacao)
            aux_piloto = aux_piloto->prox;

        auxtemp_piloto->prox = aux_piloto->prox;
        (*Colocacao)->prox = auxtemp_piloto->prox;
    }
}
/**

**/
int main(){
    const int PL = 2, CR = 2;
    char nome[30], equipe[30], terminou;
    int colocacao, i, j;
    data *piloto, *Colocacao;

    setlocale(LC_ALL, "Portuguese");
    system("color 3");
    limpar(&piloto);

    /* ARMAZENAR INFORMAÇÕES DO PILOTO NUMA LISTA SIMPLES */

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

    /* PONTUAÇÃO DOS PILOTOS NAS CORRIDAS */
    for(i = 0; i < CR; i++){
        for(j = 0; j < PL; j++){
            ajustar();
            printf("DIGITE OS RESULTADOS DO PILOTO %d NA CORRIDA %d!\n",j+1, i+1);
            ajustar();
            printf("\ndigite a Posição do piloto na corrida: ");
            scanf("%d", &colocacao);
            fflush(stdin);
            printf("\nO Piloto Terminou a Corrida? ");
            scanf("%c", &terminou);
            colocacao = pontuacao(colocacao, terminou);
            atualizarpontuacao(&piloto, j, colocacao);
            system("cls");
        }
    }
    atualizarpilotos(&piloto, &Colocacao);
    mostrarcolocacao(&Colocacao);
}
