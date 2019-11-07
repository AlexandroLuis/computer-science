#include <iostream>

using namespace std;

int main()
{
    int cont, maior = -1;

    cin >> cont;
    int voto[cont];
    for(int i = 0; i < cont; i++)
    {
        cin >> voto[i];
        if(voto[i] > maior)
            maior = voto[i];

    }
    if( maior == voto[0])
        cout << "S" << endl;
    else
        cout << "N" << endl;
}
