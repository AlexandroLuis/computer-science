#include <iostream>
#include <list>
using namespace std;

typedef struct
{
    int vis;
    string nome;
    list <string> rel;
} lista;

int procurar(lista V[], string nomee)
{
    int i = 0;
    while(V[i].nome != nomee)
        i++;
    return i;
};

int main()
{
    lista cod;
    int tam, val, i, cont = 0, T;
    cin >> val >> tam;

    string rela, nome[tam], nome2[tam], nomee;
    list <string> ::iterator I;
    list <string> temp;
    lista V[val];

    for(i = 0; i < tam; i++)
    {
        cin.get();
        cin >> nome[i] >> rela >> nome2[i];
        temp.push_back(nome[i]);
        temp.push_back(nome2[i]);
    }

    temp.sort();
    temp.unique();
    I = temp.begin();

    for(i = 0; i < val; i++)
    {
        V[i].nome = *I;
        I++;
        V[i].vis = 0;
    }

    for(i = 0; i < tam; i++)
    {
        nomee = nome[i];
        V[procurar(V, nomee)].rel.push_back(nome2[i]);
        nomee = nome2[i];
        V[procurar(V, nomee)].rel.push_back(nome[i]);
    }

    for(i = 0; i < val; i++)
    {
        if(V[i].vis == 0)
        {
            
        }
    }
}
