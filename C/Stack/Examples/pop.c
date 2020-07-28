int pop(no **L, int prox){
    
    no *P;
	int aux;
	P = malloc(sizeof(no)); // endereça memoria para o novo ponteiro do tipo no
	P = *L;
	if(&P->dado !== NULL){	// verifica se existe dados na pilha
		return pop(P->dado); // chama de forma recursiva a pilha
		aux = P->prox; // variavel auxiliar recebe o proximo da pilha
		P->dado = aux; // o proximo dado é mandado para o ponteiro auxiliar
		free(aux);
	}
	else
		return 0; // caso não exista valor na pilha retorna 0
    
   }
