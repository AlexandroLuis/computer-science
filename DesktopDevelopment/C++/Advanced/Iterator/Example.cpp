#include <iostream>
#include <iterator>
#include <list>

using namespace std;

typedef struct estrutura{
    list <string> Nome;
}Data;

int main(){
    Data EstruturaLista;
    string VariavelRecebeNome;

    for(int i = 0; i < 2; i++){
        cin >> VariavelRecebeNome;
        cin.get();
        EstruturaLista.Nome.push_front(VariavelRecebeNome);
    }
    for(list <string> ::iterator PonteiroDoIterador = EstruturaLista.Nome.begin(); PonteiroDoIterador != EstruturaLista.Nome.end(); PonteiroDoIterador++)
        cout << *PonteiroDoIterador << " ";

}
