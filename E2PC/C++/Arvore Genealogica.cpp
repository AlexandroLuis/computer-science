#include <iostream>
#include <list>
#include <stack>
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
    stack <string> nomes;
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
    /*
    cout << endl;
    for(i = 0; i < val; i++)
    {
        cout << V[i].nome << ": ";
        for(I = V[i].rel.begin(); I != V[i].rel.end(); I++)
        {
            cout << *I << " ";
        }
        cout << endl;
    }
    */
    for( i = 0; i < val; i++)
    {
        if(V[i].vis == 0)
        {
            cont++;
            V[i].vis = 1;
            for(I = V[i].rel.begin(); I != V[i].rel.end(); I++)
            {
                if(V[procurar(V, *I)].vis == 0)
                    nomes.push(*I);
            }
            while(!nomes.empty())
            {
                T = procurar(V, nomes.top());
                nomes.pop();
                if(V[T].vis == 0)
                {
                    V[T].vis = 1;
                    for(I = V[T].rel.begin(); I != V[T].rel.end(); I++)
                    {
                        if(V[procurar(V, *I)].vis == 0)
                            nomes.push(*I);
                    }
                }
            }

        }
    }
    cout << cont << endl;

}
