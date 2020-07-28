#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    int prior;
    struct node *link;
} no;

void inicializa_FP(no **L){
    *L = NULL;
}

void insere_FP(no **L, int valor, int prior){
    no *N, *P, *ANT;

    N = (no *) malloc(sizeof(no));
    N->info = valor;
    N->prior = prior;

    if (*L == NULL) {
        *L = N;
        N->link = NULL;
    }
    else {
        P = *L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == *L) {
            N->link = *L;
            *L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
}

void remove_FP(no **L, int *n) {
	no *AUX;

	if (*L != NULL) {
		*n = (*L)->info;
		AUX = *L;
		*L = (*L)->link;
		free(AUX);
	}
}

void exibe_FP(no **L){
    no *P = *L;

    while (P != NULL) {
        printf("P %d - %d \n", P->prior, P->info);
        P = P->link;
    }
}
