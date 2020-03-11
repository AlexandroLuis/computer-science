#include <stdio.h>
#include <stdlib.h>

typedef struct tag{
    int info;
    struct tag *next;
}no;

void clear(no **L){
    *L = NULL;
}

void percorre(no **L){
    no *C;
    C = *L;

    do{
        if(C != NULL){
            printf("%d\t%d\n", C->info, & C->next);
            C = C->next;
        }
        else
            C =  
    }while(C);
}

int main()
{
    no *L;
    clear(&L);
    L->info = 1;
    percorre(&L);
}
