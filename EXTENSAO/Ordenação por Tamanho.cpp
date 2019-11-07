#include <iostream>
#include <list>
using namespace std;

typedef struct{
    string nome;
    int tam;
}Palavra;

bool operator < (Palavra const &ma, Palavra const &me){
    return (ma.tam > me.tam);
}

int main(){
    list <Palavra> ordem;
    list <Palavra> ::iterator l;

    Palavra elemento;
    string leitura;
    int i, c, d;

    cin >> c;
    cin.get();

    for(i = 0; i < c; i++)
    {
        getline(cin, leitura, '\n');
        for(int j = 0; j < leitura.size(); j++)
        {
            d = leitura.find(" ");
            elemento.nome = leitura.substr(0, d);
            elemento.tam = elemento.nome.size();
            ordem.push_front(elemento);
            leitura = leitura.substr(d + 1);
        }
    }
    ordem.reverse();

    for(l = ordem.begin(); l != ordem.end(); l++)
        cout << (*l).nome << " " << endl;
}
