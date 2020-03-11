#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size *sizeof(int)
#define loop auto i = 0; i < tamanho; i++
int main()
{
    auto *ponteiro, tamanho, maior = 0;

    scanf("%d", &tamanho);

    ponteiro = malloc(tamanho size);

    (ponteiro == NULL)?printf("memoria insuficiente"),exit(0): "";

    for(loop)
        scanf("%d", ponteiro+i);

    for(loop)
        (*(ponteiro+i) > maior)? maior = *(ponteiro+i): "";

    printf("%d", maior);

    free(ponteiro);
    ponteiro = NULL;

}

