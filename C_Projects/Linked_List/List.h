typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

void inicializa_Lista(no **L) {
	*L = NULL;
}

void exibe_Lista(no **L) {
	no *P;
	P = *L;

	while(P != NULL) {
		printf("%d  ", P->info);
		P = P->link;
	}
}

void insere_Lista(no **L, int x) {
	no *N, *P, *ANT;

    N = (no *) malloc (sizeof(no));
    N->info = x;

    if (*L == NULL){
        *L = N;
        N->link = NULL;
    }
    else {
        P = *L;

        while((P != NULL) && (x <= P->info)) {
            ANT = P;
            P = P->link;
        }
        if (P == *L) {
            N->link = *L;
            *L = N;
        }
        else {
            if (P == NULL) {
                ANT->link = N;
                N->link = NULL;
            }
            else {
                ANT->link = N;
                N->link = P;
            }
        }
    }
}

//Use to remove values
/*
void remove_Lista(no **L, int *n) {
	no *AUX;

	if (*L != NULL) {
        *n = (*L)->info;
		AUX = *L;
		*L = (*L)->link;
		free(AUX);
	}
}

int verificaSeVazia_Lista(no **L) {
	if (*L == NULL)
		return 1;
	else
		return 0;
}
*/
