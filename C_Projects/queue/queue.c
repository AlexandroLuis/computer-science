#include <stdio.h>
#include <stdlib.h>
#include "Fila_LE.h"

int main()
{
    no *P1, *P2, *P3;
    int i, n;

    inicializa_Fila(&P1);
    inicializa_Fila(&P2);
    inicializa_Fila(&P3);

    for(i = 10; i < 30; i++)
        insere_Fila(&P1, i);

    printf("Valores da Pilha 1:\n");
    exibe_Fila(&P1);
    printf("\n\n\n");

    comparar(&P1, &P2, &P3);

    printf("Valores da Pilha par:\n");
    exibe_Fila(&P2);
    printf("\n\n");

    printf("Valores da Pilha impar:\n");
    exibe_Fila(&P3);
    printf("\n\n\n");

    printf("Valores da nova Pilha 1:\n");
    exibe_Fila(&P1);
}
