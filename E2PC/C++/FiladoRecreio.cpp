#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <int> fila;
    list <int> ::iterator c;

    int cont1, cont2, valor, r;

    cin >> cont1;

    for(int i = 0; i < cont1; i++)
    {
        cin >> cont2;
        for(int j = 0; j < cont2; j++)
        {
            cin >> valor;
            fila.push_front(valor);
        }
        r = cont2;
        for(c = fila.begin(); c != fila.end(); c++)
        {
            if(*c < (*c++))
                r--;
        }
        cout << r << endl;
    }
}
