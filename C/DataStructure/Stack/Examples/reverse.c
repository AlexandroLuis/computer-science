#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
	int value;
	struct pilha *link;
}no;

void begin(no **stack) {
	*stack = NULL;
}

void showstack(no **stack) {
	no *aux_stack;
	aux_stack = *stack;
	while(aux_stack != NULL) {
		printf("%d", aux_stack->value);
		aux_stack =aux_stack->link;
	}
}

void push(no **stack, int x){
	no *aux_stack;
	aux_stack = (no *) malloc(sizeof(no));
	aux_stack->value = x;
	aux_stack->link = *stack;
	*stack = aux_stack;
}

void pop(no **stack, int *x){
	no *aux_stack;
	if(*stack != NULL) {
        printf("%d", &stack);
		aux_stack = *stack;
		*x = (*stack)->value;
		*stack = (*stack)->link;
		free(aux_stack);
	}
}

void charge(char read[], no **stack){
	int n, i, c;
	char d;
	n = strlen(read);

	for(i = 0; i < n; i++){
        d = read[i];
        push(stack,d - 48);
    }
}

int main () {
	no *stack;
	int x, y = 0, resp;
	char read[40];

	begin(&stack);
	scanf("%s", read);
	charge(read, &stack);
	showstack(&stack);
}
