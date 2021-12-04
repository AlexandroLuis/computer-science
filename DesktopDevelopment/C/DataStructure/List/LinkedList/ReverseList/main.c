#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(){
    no *P1;
    int i, val;

    inicializa_Lista(&P1);

    for(i = 0; i < 5; i++){
        scanf("%d", &val);
        insere_Lista(&P1, val);
    }

    exibe_Lista(&P1);
}
