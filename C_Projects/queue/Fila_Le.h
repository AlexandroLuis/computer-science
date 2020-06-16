/*
 ***** FILA_LE.h
 ***** FILA IMPLEMENTADA COMO LISTA ENCADEADA
*/

typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

// inicializa Fila
void inicializa_Fila(no **L) {
	*L = NULL;
}

void exibe_Fila(no **L) {
	no *P;
	P = *L;	// P recebe o endereco do primeiro no da lista

	while(P != NULL) { // enquanto P apontar para um nó da Fila
		printf("%d  ", P->info);	// exibe o valor do nó
		P = P->link;	// P recebe o endere?o do pr?ximo nó da Fila
	}
}

// função que insere item no final da Fila
void insere_Fila(no **L, int x) {
	no *P, *N;

	// aloca memória para armazenar o novo nó e atribui o endereço alocado para N
	N = (no *) malloc (sizeof(no));
	N->info = x; // Insere o valor no novo n?
	N->link = NULL; // como será inserido no final da Fila, link do novo nó recebe NULL

		// se a Fila estiver vazia, o novo nó será o primeiro da Fila
	if (*L == NULL){ // verifica se Fila vazia
		*L = N;
	}
	else { // se a Fila não estiver vazia, é preciso encontrar o final da Fila para inserir o novo item
		P = *L;	// P recebe o endereco do primeiro no da lista

		while(P->link != NULL) {
			P = P->link;
		}
			// o while é interrompido quando P apontar para o último nó da Fila
		P->link = N; 	// o link do nó apontado por P recebe o endereço do novo nó
	}
}

// função que remove o item do início da Fila
void remove_Fila(no **L, int *n) {
	no *AUX;

	// verifica se Fila não está vazia
	if (*L != NULL) {
		// *n guarda o valor do nó que será excluído
		*n = (*L)->info;
		// um ponteiro auxiliar recebe o endereço do primeiro nó da Fila
		AUX = *L;
		// *l aponta para o próximo nó da Fila
		*L = (*L)->link;
		// Libera a area de memória do nó excluido da Fila
		free(AUX);
	}
}

// função que verifica se Fila Vazia
int verificaSeVazia_Fila(no **L) {
	if (*L == NULL)
		return 1;
	else
		return 0;
}

void comparar(no **L1, no **L2, no **L3){
    no *aux_stack;
    int i;

    for(i = 0; i < 19; i++){
        aux_stack = *L1;
        if(aux_stack % 2 == 0){
            insere_Fila(&L2, &L1);
            *L2 = (*L2)->link;
        }
        else{
            insere_Fila(&L3, &L1);
            *L3 = (*L3)->link;
        }
        *L1  = (*L1)->link;
    }
    remove_Fila(&L1, i);
}
