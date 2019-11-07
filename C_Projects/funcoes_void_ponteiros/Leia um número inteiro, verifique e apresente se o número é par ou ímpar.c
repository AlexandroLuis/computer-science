#include <stdio.h>
#include <stdlib.h>
void Comparacao(int Numero, int *Teste);

void Comparacao(int Numero, int *Teste)
{
   *Teste = Numero % 2;
}

int main()
{
    int Numero, Teste;

    scanf("%d", &Numero);
    Comparacao(Numero, &Teste);

    if(Teste == 0)
    {
        printf("Par");
    }
    else
    {
        printf("impar");
    }
    return 0;
}
