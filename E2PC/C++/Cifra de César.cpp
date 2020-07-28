#include <iostream>
#include <string>

using namespace std;

int main()
{
    string texto, resultado;
    int c, c2, i;

    cin >> c;
    cin.get();

    for(i = 0; i < c; i++)
    {
        getline(cin, texto, '\n');
        cin >> c2;
        cin.get();
        for(int j = 0; j < texto.size(); j++)
        {
            resultado[j] = texto[j] - c2;

            if(resultado[j] < 65)
                resultado[j] = 90 - (64 - (texto[j] - c2));

            cout << resultado[j];
        }
        cout << endl;
    }
}
