/*
    Struct Inside Main
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[30];
    int i = 0;

    scanf("%s", &nome);
    //scanf("[^\n]", &nome);

    while((nome[i] != '\0'))
    {
        printf("%c\n", nome[i]);
        i++;
    }
}
