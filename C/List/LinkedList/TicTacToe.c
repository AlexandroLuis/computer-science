#include <stdio.h>
#include <conio.h>

typedef struct JogoDaVelha{
    int id;
    int Ponto[5];
    char nome[50];
    struct JogoDaVelha *prox;
    struct JogoDaVelha *prev;
}Info;

void Limpar(Info **Jogador){
    *Jogador = NULL;
}

int VerificacaoDeVitoria(char Mapa[])
{
    if(Mapa[0] == Mapa[1] && Mapa[1] == Mapa[2])
        return 1;
    else if(Mapa[3] == Mapa[4] && Mapa[4] == Mapa[5])
        return 1;
    else if(Mapa[6] == Mapa[7] && Mapa[7] == Mapa[8])
        return 1;
    else if(Mapa[0] == Mapa[3] && Mapa[3] == Mapa[6])
        return 1;
    else if(Mapa[1] == Mapa[4] && Mapa[4] == Mapa[7])
        return 1;
    else if(Mapa[2] == Mapa[5] && Mapa[5] == Mapa[8])
        return 1;
    else if(Mapa[0] == Mapa[4] && Mapa[4] == Mapa[8])
        return 1;
    else if(Mapa[2] == Mapa[4] && Mapa[4] == Mapa[6])
        return 1;
    else if(Mapa[0] != '1' && Mapa[1] != '2' && Mapa[2] != '3' &&
            Mapa[3] != '4' && Mapa[4] != '5' && Mapa[5] != '6' &&
            Mapa[6] != '7' && Mapa[7] != '8' && Mapa[8] != '9')
        return 0;
    else return  - 1;
}

void FuncaoPrintarMapa(Info **Jogador, char Mapa[]){
    Info *Mostrar = *Jogador;
    system("cls");
    printf("\n\n\t\tJogo da Velha\n\n");

    printf("\tJogador %s (X)\tJogador %s (O)\n\n\n", Mostrar->nome, Mostrar->prox->nome);


    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", Mapa[0], Mapa[1], Mapa[2]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", Mapa[3], Mapa[4], Mapa[5]);
    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");
    printf("\t\t  %c  |  %c  | %c  \n", Mapa[6], Mapa[7], Mapa[8]);
    printf("\t\t     |     |     \n\n");

}

void push(Info **Jogador, char nome[], int i){
    Info *fim, *aux, *aux_prev;

    aux = (Info*) malloc(sizeof(Info));
    aux->id = i;
	for(int j = 0; j < 30; j++)
        aux->nome[j] = nome[j];
    aux->prox = NULL;
    aux->prev = NULL;

    if(*Jogador == NULL)
        *Jogador = aux;
	else{
		fim = *Jogador;
		while(fim->prox != NULL)
			fim = fim->prox;
		fim->prox = aux;
		fim->prev = *Jogador;
		*Jogador = fim;
	}
}

int main(){
    Info *Jogador;
    int i, Ponto;
    char nome[50], Valor;
    char Mapa[9]={'1','2','3','4','5','6','7','8','9'};

    Limpar(&Jogador);
    for(i = 0; i < 2; i++){
        printf("DIGITE O NOME DO %d' JOGADOR:\t", i+1);
        scanf("%s", &nome);
        push(&Jogador, nome, i);
        system("cls");
    }

    i = 0;
    do{
        FuncaoPrintarMapa(&Jogador, Mapa);

        printf("Jogador %s, Digite A Posicao Escolhida:  ", Jogador->nome);
        scanf("%d", &Ponto);

        Valor = (Jogador->id == 0) ? 'X' : 'O';

        if (Ponto == 1 && Mapa[0] == '1')
            Mapa[0] = Valor;

        else if (Ponto == 2 && Mapa[1] == '2')
            Mapa[1] = Valor;

        else if (Ponto == 3 && Mapa[2] == '3')
            Mapa[2] = Valor;

        else if (Ponto == 4 && Mapa[3] == '4')
            Mapa[3] = Valor;

        else if (Ponto == 5 && Mapa[4] == '5')
            Mapa[4] = Valor;

        else if (Ponto == 6 && Mapa[5] == '6')
            Mapa[5] = Valor;

        else if (Ponto == 7 && Mapa[6] == '7')
            Mapa[6] = Valor;

        else if (Ponto == 8 && Mapa[7] == '8')
            Mapa[7] = Valor;

        else if (Ponto == 9 && Mapa[8] == '9')
            Mapa[8] = Valor;

        else{
            printf("Movimento Invalido!");
            getch();
        }
        i = VerificacaoDeVitoria(Mapa);

        //if(Jogador->prox != NULL)
           // Jogador = Jogador->prox;
       // else
           // Jogador = Jogador->prev;

    }while (i ==  - 1);

    FuncaoPrintarMapa(&Jogador, Mapa);

    if (i == 1)
        printf("Jogador %s Ganhou!\n", Jogador->nome);
    else
        printf("Empate!\n");
}
