#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <int> pares;
    list <int> impares;
    list <int> ::iterator l;

    int i, j, entrada, valor;

    cin >> entrada;

    for(i = 0; i < entrada; i++)
    {
        cin >> valor;

        if(valor % 2 == 0)
            pares.push_front(valor);
        else
            impares.push_front(valor);
    }
    pares.sort();
    impares.sort();
    impares.reverse();

    for(l = pares.begin(); l != pares.end(); l++)
        cout << *l << endl;

    for(l = impares.begin(); l != impares.end(); l++)
        cout << *l << endl;
}
