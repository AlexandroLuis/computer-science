#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct pilha {
	int value;
	struct pilha *link;
}no;

void begin(no **stack) {
	*stack = NULL;
}
void wrong(){
    system("cls");
    printf("Sintaxe incorreta");
}
void right(){
    system("cls");
    printf("Sintaxe correta");
}

int compara(char c, char d){
	if ((d ==  ')' ) && (c != '(' ))
		return(0);
	if ((d ==  ']' ) && (c != '[' ))
		return(0);
	if ((d ==  '}' ) && (c != '{' ))
		return(0);
	return(1);
}

void showstack(no **stack) {
	no *aux_stack;
	aux_stack = *stack;
	while(aux_stack != NULL) {
		printf("\n%d", aux_stack->value);
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
		aux_stack = *stack;
		*x = (*stack)->value;
		*stack = (*stack)->link;
		free(aux_stack);
	}
}

void compare(char read[], no **stack){
	int n, i, c;
	char d;
	n = strlen(read);

	for(i = 0; i < n; i++){
		d = read[i];

		if(d ==  '(' || d ==  '[' || d ==  '{' )
            push(stack,d);
        else if(d == ')' || d ==  ']' || d ==  '}' ){
            if (*stack == NULL)
                wrong();
            pop(stack, &c);
            if (!compara(c,d))
                wrong();
        }
	}
	if(*stack != NULL)
		wrong();
	else
        right();
}

int main () {
	no *stack;
	int x, y = 0, resp;
	char read[40];

	begin(&stack);
	scanf("%s", read);
	compare(read, &stack);
}
