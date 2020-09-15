/*
    Struct Outside Main
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char funcao;
    float salario[5][2];
    float aumento;
} Trabalho;

typedef struct{
    char nome[20];
    int idade;
    char trabalho;
    Trabalho var;
} Formulario;

void Cadastro (Formulario *registro){
    float soldo;

    printf("Digite o nome");
    fgets(registro->nome, 39, stdin);

    printf("Digite a idade");
    scanf("%d", &registro->idade);

    fflush(stdin);
    printf("Digite o trabalho");
    scanf("%d", &registro->trabalho);

    fflush(stdin);
    printf("Digite a funcao");
    scanf("%d", &registro->var.funcao);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            printf("Digite o soldo de %d", (2019 + j));
            scanf("%f", &soldo);
            &registro->var->salario[i][j] = soldo;
            &registro.var.aumento += soldo;
        }
    }

}

void imprime(Formulario registro){
    Cadastro(&registro);

    printf("Nome : %s, Idade : %d, Trabalho : %s\n", registro.nome, registro.idade, registro.trabalho);
    printf("Funcao : %s, Aumento: %f", registro.var.funcao, registro.var.aumento);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++)
            printf("%f", registro.var.salario[i][j]);
    }
}

int main(){
    Formulario registro;
    imprime(registro);
}
