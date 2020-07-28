#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro
{
    int ra;
    int cpf;
    float mesada;
}cadastro;

int main()
{
    cadastro aluno ={57019, 17058, 53.06};
    cadastro aluno_turista = aluno;

    //printf("ra = %d, cpf = %d, mesada = %0.2f.\n", aluno.ra, aluno.cpf, aluno.mesada);
    printf("ra = %d, cpf = %d, mesada = %0.2f.\n", aluno_turista.ra, aluno_turista.cpf, aluno_turista.mesada);

}



/*
    struct cadastro{
        int ra;
        int cpf;
        float mesada;
    }aluno;

    scanf("%d", &aluno.ra);
    scanf("%d", &aluno.cpf);
    scanf("%f", &aluno.mesada);

    printf("ra = %d, cpf = %d, mesada = %0.2f.\n", aluno.ra, aluno.cpf, aluno.mesada);
 */
