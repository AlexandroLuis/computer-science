#include <stdio.h>
#include <conio.h>

typedef struct JogoDaVelha{
    int id;
    char nome[50];
    struct JogoDaVelha *prox;
    struct JogoDaVelha *prev;
}Info;

typedef struct MapaJogoDaVelha{
    char Mapa[9];
}Tabuleiro;


void Limpar(Info **Jogador, Tabuleiro **Informacoes){
    *Jogador = NULL;
    *Informacoes = NULL;

    char GravarValoresNomapa[9];
    Tabuleiro *aux;
    aux = malloc(sizeof(Tabuleiro));

    for(int i = 0; i < 9; i++){
        GravarValoresNomapa[i] = i+49;
        aux->Mapa[i] = GravarValoresNomapa[i];
    }
    *Informacoes = aux;

}

int VerificacaoDeVitoria(Tabuleiro **Informacoes){
    Tabuleiro *VerificadorDeVitoria = *Informacoes;

    /** COMPARAR QUEM GANHOU **/
         if(VerificadorDeVitoria->Mapa[0] == VerificadorDeVitoria->Mapa[1] && VerificadorDeVitoria->Mapa[1] == VerificadorDeVitoria->Mapa[2])return 1;
    else if(VerificadorDeVitoria->Mapa[3] == VerificadorDeVitoria->Mapa[4] && VerificadorDeVitoria->Mapa[4] == VerificadorDeVitoria->Mapa[5])return 1;
    else if(VerificadorDeVitoria->Mapa[6] == VerificadorDeVitoria->Mapa[7] && VerificadorDeVitoria->Mapa[7] == VerificadorDeVitoria->Mapa[8])return 1;
    else if(VerificadorDeVitoria->Mapa[0] == VerificadorDeVitoria->Mapa[3] && VerificadorDeVitoria->Mapa[3] == VerificadorDeVitoria->Mapa[6])return 1;
    else if(VerificadorDeVitoria->Mapa[1] == VerificadorDeVitoria->Mapa[4] && VerificadorDeVitoria->Mapa[4] == VerificadorDeVitoria->Mapa[7])return 1;
    else if(VerificadorDeVitoria->Mapa[2] == VerificadorDeVitoria->Mapa[5] && VerificadorDeVitoria->Mapa[5] == VerificadorDeVitoria->Mapa[8])return 1;
    else if(VerificadorDeVitoria->Mapa[0] == VerificadorDeVitoria->Mapa[4] && VerificadorDeVitoria->Mapa[4] == VerificadorDeVitoria->Mapa[8])return 1;
    else if(VerificadorDeVitoria->Mapa[2] == VerificadorDeVitoria->Mapa[4] && VerificadorDeVitoria->Mapa[4] == VerificadorDeVitoria->Mapa[6])return 1;

    /** COMPARAR SE EMPATOU **/
    else if(VerificadorDeVitoria->Mapa[0] != '1' && VerificadorDeVitoria->Mapa[1] != '2' && VerificadorDeVitoria->Mapa[2] != '3' &&
            VerificadorDeVitoria->Mapa[3] != '4' && VerificadorDeVitoria->Mapa[4] != '5' && VerificadorDeVitoria->Mapa[5] != '6' &&
            VerificadorDeVitoria->Mapa[6] != '7' && VerificadorDeVitoria->Mapa[7] != '8' && VerificadorDeVitoria->Mapa[8] != '9')return 0;

    /** VERIFICA SE AIDA NÃO ACABOU **/
    else return  - 1;
}

void FuncaoPrintarMapa(Info **Jogador, Tabuleiro **Informacoes, int P){
    Info *MostrarJogador = *Jogador;
    Tabuleiro *MostrarMapa = *Informacoes;
    system("cls");
    printf("\n\n\t\tJogo da Velha\n\n");

    if(P % 2 == 0)
        printf("\tJogador %s (X)\tJogador %s (O)\n\n\n", MostrarJogador->nome, MostrarJogador->prox->nome);
    else
        printf("\tJogador %s (O)\tJogador %s (X)\n\n\n", MostrarJogador->nome, MostrarJogador->prox->nome);

    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", MostrarMapa->Mapa[0], MostrarMapa->Mapa[1], MostrarMapa->Mapa[2]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", MostrarMapa->Mapa[3], MostrarMapa->Mapa[4], MostrarMapa->Mapa[5]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", MostrarMapa->Mapa[6], MostrarMapa->Mapa[7], MostrarMapa->Mapa[8]);
    printf("\t\t     |     |     \n\n");
}

void push(Info **Jogador, char nome[], int i){
    Info *aux, *ULT;
	aux = (Info *) malloc (sizeof(Info));

	aux->id = i;
	for(int j = 0; j < 30; j++)
        aux->nome[j] = nome[j];
    aux->prox = NULL;

	if(*Jogador == NULL){
		aux->prev = aux;
		aux->prox = aux;
	}
	else{
		ULT = (*Jogador)->prev;
		aux->prev = ULT;
		(*Jogador)->prev = aux;
		aux->prox = *Jogador;
		ULT->prox = aux;
	}
	*Jogador = aux;
}

int main(){
    Info *Jogador;
    int i, Ponto, P = 0;
    char nome[50], Valor;
    Tabuleiro *Informacoes;

    Limpar(&Jogador, &Informacoes);

    for(i = 0; i < 2; i++){
        printf("DIGITE O NOME DO %d' JOGADOR:\t", i+1);
        scanf("%s", &nome);
        push(&Jogador, nome, i);
        system("cls");
    }

    i = 0;
    do{
        FuncaoPrintarMapa(&Jogador, &Informacoes, P);

        printf("Jogador %s, Digite a Posicao Escolhida:  ", Jogador->nome);
        scanf("%d", &Ponto);

        Valor = (Jogador->id == 0) ? 'O' : 'X';

        if (Ponto == 1 && Informacoes->Mapa[0] == '1')
            Informacoes->Mapa[0] = Valor;

        else if (Ponto == 2 && Informacoes->Mapa[1] == '2')
            Informacoes->Mapa[1] = Valor;

        else if (Ponto == 3 && Informacoes->Mapa[2] == '3')
            Informacoes->Mapa[2] = Valor;

        else if (Ponto == 4 && Informacoes->Mapa[3] == '4')
            Informacoes->Mapa[3] = Valor;

        else if (Ponto == 5 && Informacoes->Mapa[4] == '5')
            Informacoes->Mapa[4] = Valor;

        else if (Ponto == 6 && Informacoes->Mapa[5] == '6')
            Informacoes->Mapa[5] = Valor;

        else if (Ponto == 7 && Informacoes->Mapa[6] == '7')
            Informacoes->Mapa[6] = Valor;

        else if (Ponto == 8 && Informacoes->Mapa[7] == '8')
            Informacoes->Mapa[7] = Valor;

        else if (Ponto == 9 && Informacoes->Mapa[8] == '9')
            Informacoes->Mapa[8] = Valor;

        P++;
        i = VerificacaoDeVitoria(&Informacoes);
        Jogador = Jogador->prox;
    }while (i ==  - 1);

    FuncaoPrintarMapa(&Jogador, &Informacoes, P);

    if (i == 1)
        printf("Jogador %s Ganhou!\n", Jogador->prox->nome);
    else
        printf("Empate!\n");
}
