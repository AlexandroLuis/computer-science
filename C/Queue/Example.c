#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct DataPlane{ //Estrutura da fila
    int id; //id do avião
    int priority; // prioridade
    struct DataPlane *next; //proximo endereço
}data;

void startValueZ(data **Plane){ // Função para inicializar a fila de prioridades
	*Plane = NULL; //preenche a estrutura DataPlane com NULO
}

void push(data **Plane, int valid, int valpriority){//Insere Valores na fila
    data *aux_Plane, *auxtemp_Plane; // Aloca 2 ponteiros auxiliares

    aux_Plane = *Plane; // Ponteiro auxiliar recebe o valor do ponteiro principal
    auxtemp_Plane = (data*)malloc(sizeof(data)); // Aloca tamanho pro 2° ponteiro auxiliar

    auxtemp_Plane->id = valid; // id referenciado é gravado pelo 2 ponteiro
    auxtemp_Plane->priority = valpriority; // 2° ponteiro recebe prioridade referenciada
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

void pop(data **Plane, int *valid, int *valpriority){//Função pop comum
    data *aux_Plane;
	if (*Plane != NULL) {
		*valid = (*Plane)->id;
		*valpriority = (*Plane)->priority;
		aux_Plane = *Plane;
		*Plane = (*Plane)->next;
		free(aux_Plane);
	}
}

int NotEmpty(data **Plane){//Verifica se o ponteiro não está vazio
    //if(*Plane == NULL)
		//return 0xf001;
    return (*Plane) == 0xf001; //Forma de retornar caso o ponteiro seja nulo
}

void showPlane(data **Plane, int aux,int Time, int T, int c){//ESSA FUNÇÃO VAI APENAS MOSTRAR O RESULTADO
    int i;

    if(aux % 2 == 0){//só faz o risco se for par
        for(i = 0; i < 21; i++)
            printf("-");
        printf("\n");
        aux = 0;
    }
    else
        aux = 1;// aux é a posta de pouso/decolagem

    printf("Aviao %d, Na pista %d.\n",(*Plane)->id, aux);//ID do avião

    if(aux == 1)
        printf("Tempo gasto %d\n", Time);//Tempo gasto

    if(T == c && T % 2 != 0){//Fechar função caso seja impar
        printf("Tempo gasto %d\n", Time);
        for(i = 0; i < 20; i++)
            printf("-");
    }
}

int main(){//Função principal, vai ler e mostrar os aviões
    data *Plane;
    int i, valpriority, valid, aux = 0, Time = 2, T, c = 0;
    int V;

    startValueZ(&Plane);
    printf("Digite quantos voos\n");
    scanf("%d", &T);//quantos aviões querem sair/entrar no aeroporto?

    for(i = 0; i < T; i++){//ler os valores
        printf("Digite qual o tipo, P  = 1 ou D = 2\n");
        scanf("%d", &V);
        printf("Digite o numero do voo\n");
        scanf("%d", &valid);
        if(V == 1){
            printf("Digite a prioridade\n");
            scanf("%d", &valpriority);
            push(&Plane, valid, valpriority);
        }
        else
            push(&Plane, valid, 3);
    }

    system("cls");
    system("color 6");

    while(NotEmpty != 0xf001){//Vai mostrar o mapa e percorrer a estrutura
        c++;
        showPlane(&Plane, aux, Time, T, c);
        pop(&Plane, &valid, &valpriority);
        aux++;
        Time += 2;
    }
}
