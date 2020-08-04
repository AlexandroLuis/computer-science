#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

typedef struct DataPlane{ //Estrutura da fila
    int id; //id do avião
    int priority; // prioridade
    char Spec;
    struct DataPlane *next; //proximo endereço
}data;

void startValueZ(data **Plane){ // Função para inicializar a fila de prioridades
	*Plane = NULL; //preenche a estrutura DataPlane com NULO
}

void push(data **Plane, int valid, int valpriority, char valspec){//Insere Valores na fila
    data *aux_Plane, *auxtemp_Plane; // Aloca 2 ponteiros auxiliares

    aux_Plane = *Plane; // Ponteiro auxiliar recebe o valor do ponteiro principal
    auxtemp_Plane = (data*)malloc(sizeof(data)); // Aloca tamanho pro 2° ponteiro auxiliar

    auxtemp_Plane->id = valid; // id referenciado é gravado pelo 2 ponteiro
    auxtemp_Plane->priority = valpriority;
    auxtemp_Plane->Spec = valspec; // 2° ponteiro recebe prioridade referenciada
    auxtemp_Plane->next = NULL; // Proximo nó recebe nulo

    if (*Plane == NULL) { // Verifica se o ponteiro principal não consta valores
        *Plane = auxtemp_Plane; // ponteiro principal recebe valores do 2° ponteiro
    }
    else if((*Plane)->priority > valpriority){// Verifica prioridades do ponteiro principal ser maior que a prioridade referenciada atual
        auxtemp_Plane->next = *Plane;//ponteiro auxiliar 2, na proxima posição recebe ponteiro principal
        (*Plane) = auxtemp_Plane;//ponteiro principal recebe o valores atuais do 2 ponteiro auxiliar
    }
    else{
        while(aux_Plane->next != NULL && aux_Plane->next->priority < valpriority)// enquanto o 1° ponteiro auxiliar no proximo nó ser diferente nulo & a prioridade ser menor que a prioridade referenciada
            aux_Plane = aux_Plane->next;// a posição atual do ponteiro recebe os valores do proximo nó

        auxtemp_Plane->next = aux_Plane->next;// armazena a proxima posição do nó 1 pónteiro no proximo nó do 2 ponteiro
        aux_Plane->next = auxtemp_Plane;//proxima posição do 1 ponteiro recebe a posição atual do ponteiro 2
    }
}

void pop(data **Plane, int *valid, int *valpriority, int *valspec){//Função pop comum
    data *aux_Plane; // aloca um ponteiro auxiliar
	if(*Plane != NULL) { //verifica se o ponteiro da estrutura não é vazio
		*valid = (*Plane)->id;
		*valpriority = (*Plane)->priority;
		*valspec = (*Plane)->Spec;
		aux_Plane = *Plane;
		*Plane = (*Plane)->next;
		free(aux_Plane);
	}
}

int showPlane(data **Plane){//ESSA FUNÇÃO VAI APENAS MOSTRAR O RESULTADO
    return (*Plane)->id; // retorna o numero do avião
}

void showPlaneQueue(data **Plane){
    data *P = *Plane;
//Função que mostra os aviões em sequencia, mostrando suas especificações
    if(P != NULL){
        printf("Aviões em espera : ");
        while (P != NULL) {
            printf("\n\t|Número do Avião: %d, Tipo do Voo: %c, Prioridade: %d|",P->id, P->Spec, P->priority);
            P = P->next;
        }
    }
    else//caso seja falso
         printf("Sem Aviões em espera!\n");
    printf("\n");
}

void pushNormal(data **Plane, int valid, int valpriority, int L){
    data *P, *N;
    N = (data *) malloc (sizeof(data));
    N->id = valid;
    N->priority = valpriority;
    N->Spec = L;
    N->next = NULL;
    if(*Plane == NULL)
            *Plane = N;
     else {
        P = *Plane;
        while(P->next != NULL)
            P = P->next;
        P->next = N;
    }
}

int main(){//Função principal, vai ler e mostrar os aviões
    data *Plane, *Result; //ponteiros
    const int Const = 70, hour = 17;
    int i, ut = 10, T;
    int valpriority, valid, L;
    bool continua = true;
    char ler;

    setlocale(LC_ALL, "Portuguese");
    startValueZ(&Plane);//inicia os ponteiros com nulo
    startValueZ(&Result);
    system("color 3");

    printf("Digite quantos a quantidade de voos: ");
    scanf("%d", &T);//quantos aviões querem sair/entrar no aeroporto?
/*
    for(i = 0; i < T; i++){//ler os valores
        fflush(stdin);
        printf("\nDigite qual o tipo do voo: ");
        scanf("%c", &ler);
        printf("\nDigite o numero do voo: ");
        scanf("%d", &valid);
        if(ler == 80 || ler == 2){//Força a inclusao do tipo do voo
            printf("\nDigite a prioridade: ");
            scanf("%d", &valpriority);
            push(&Plane, valid, valpriority, 'P');
        }
        else
            push(&Plane, valid, 3, 'D');
    }
*/
    for(i = 0; i < 20; i++){
        valid = rand() % 700;
        valpriority = rand() % 4;
        ler = rand() % 26;
        if(ler > 17){
            if(valpriority > 1)
                push(&Plane, valid, 2, 'P');
            else
                push(&Plane, valid, 1, 'P');
        }
        else
             push(&Plane, valid, 3, 'D');
    }


    system("cls");
    system("color 6");

    printf("Lista de Aviões na Fila!\n");//mostra os aviões que estão no ponteiro 1
    showPlaneQueue(&Plane);

    while(continua) {//enquanto continua tem o valor true
        printf("\n");
        for(i = 0; i < Const; i++)//mostra informações do mapa
            printf("-");
        printf("\nHorário %d:%d",hour, ut+1);
        for(i = 0; i < 3; i++) {//faz a alocação dos 3 novos aviões na fila 2
            if(Plane != NULL) {
                pop(&Plane, &valid, &valpriority, &L);
                pushNormal(&Result, valid, valpriority, L);
            }
        }
        printf("\n");
        showPlaneQueue(&Result);
        if((ut % 2 == 0) && (continua)){//mostra os avioes que estão utilizando a pista e seu tempo
            if(Result != NULL)
                printf("\nAviões utilizando a pista no momento:");
            for(i = 0; i <= 1; i++){
                if(Result != NULL){
                    pop(&Result, &valid, &valpriority, &L);
                    if(L == 'P')
                        printf("\n\t|Avião %d pousando na pista %d|", valid, i);
                    else
                        printf("\n\t|Avião %d decolando na pista %d|", valid, i);
                }
                else{
                    printf("\n");
                    for(i = 0; i < Const; i++)
                        printf("-");
                    printf("\nHorário %d:%d",hour, ut+1);
                    printf("\n\nTodos os pousos e decolagens realizados!\n\n");
                    continua = false;
                    break;
                }
            }
        }
        else
            printf("\nExistem Aviões utilizando as pistas no momento : 17:%d\n", ut+1);
    ut++;
    }
    return 0x29A;
}
