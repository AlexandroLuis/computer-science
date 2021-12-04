#include <stdio.h>
#include <string.h>

int main ()
{
  char palavra[1100], aux;
  unsigned casos;
  unsigned short i, j, tam, metade;

  scanf("%u", &casos);

  while (casos)
  {

    scanf(" %[^\n]", palavra);

    tam = strlen(palavra);
    metade = tam/2;

    for (i = 0; i < tam; i++ )
      if ((palavra[i] >= 'a' && palavra[i] <= 'z') ||(palavra[i] >= 'A' && palavra[i] <= 'Z'))
        palavra[i] = palavra[i] + 3;

    for (i = 0, j = tam - 1; i < metade; i++, j--)
    {

      aux = palavra[j];
      palavra[j] = palavra[i];
      palavra[i] = aux;

    }
    for (i = metade; i < tam; i++ )
      if ((palavra[i] >= 32 && palavra[i] <= 176 ))
        palavra[i] = palavra[i] - 1;
    printf("%s\n", palavra);
    memset(palavra, 0 , sizeof(palavra));
    casos--;
  }
  return 0;
}