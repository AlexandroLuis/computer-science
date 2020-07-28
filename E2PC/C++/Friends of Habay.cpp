#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <string> amigos;
    list <string> naoamigos;
    list <string> ::iterator l;

    int i;
    string nome, valor, maior = "";


    do{
        cin >> nome;
        if(nome != "FIM")
        {
            cin >> valor;

            if(valor == "YES")
            {
                amigos.push_front(nome);
                if(nome.size() > maior.size())
                {
                    maior = nome;
                }
            }
            else{
                naoamigos.push_front(nome);
            }
        }
    }
    while(nome != "FIM");

    amigos.sort();
    amigos.unique();
    naoamigos.sort();
    naoamigos.unique();

    for(l = amigos.begin(); l != amigos.end(); l++)
        cout << *l << endl;
    for(l = naoamigos.begin(); l != naoamigos.end(); l++)
        cout << *l << endl;

    cout << endl << "Amigo do Habay:" << endl << maior << endl;
}
