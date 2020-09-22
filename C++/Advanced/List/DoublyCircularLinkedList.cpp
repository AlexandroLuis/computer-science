#include <iostream>
#include <string>

using namespace std;
/**

**/
typedef struct corredor{
    int id;
    int pontuacao;
    string nome;
    string equipe;
    /**/
    struct corredor *next;
    struct corredor *prev;
}data;
/**

**/
void inicializa(data **piloto, data **Fcolocacao){
    *piloto = NULL;
    *Fcolocacao = NULL;
}
/**

**/
void push(data **piloto, int i, string nome, string equipe){
    data *aux_data, *verificacao;
    aux_data = (data*)malloc (sizeof(data));

    aux_data->id = i;
    aux_data->pontuacao = 0;
    aux_data->nome = nome;
    aux_data->equipe = equipe;
    aux_data->next = NULL;

    if(*piloto == NULL)
        *piloto = aux_data;
    else{
        verificacao = *piloto;

        while(verificacao->next != NULL)
            verificacao = verificacao->next;
        verificacao = aux_data;
    }
}
/**

**/
string nomepiloto(data **piloto, int i){
    data *aux;
    aux = *piloto;

    while (aux->id != i)
        aux = aux->next;

    return aux->nome;
}
/**

**/
void atualizarpontuacao(){
    
}
/**

**/
int main(){
    const int QTDC = 2, QTDP = 2;/** Quantidade de corridas e pilotos **/
    string nome, equipe;
    int colocacao, i, j;
    data *piloto, *Fcolocacao;

    system("color 3");
    inicializa(&piloto, &Fcolocacao);

    /**/
    for(i = 0; i < QTDP; i++){
        cout << "Digite o Nome do piloto " << i+1 << endl;
        cin >> nome;
        cout <<"Digite a Equipe do piloto " << nome <<endl;
        cin >> equipe;
        system("cls");
        push(&piloto, i+1, nome, equipe);
    }
    /**/
    for(i = 0; i < QTDP; i++){
        for(j = 0; j < QTDC; j++){
            cout << "Corrida " << j+1 << " do piloto ";printf("%s!\n", nomepiloto(&piloto, i));
            cout << "Digite a Colocação: ";
            cin >> colocacao;/** 0 para não terminou **/
            atualizarpontuacao(&piloto, colocacao);
            system("cls");
        }
    }

}
