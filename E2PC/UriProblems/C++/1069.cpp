#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string valor;
    int cont,i ,j , d;

    cin >> cont;
    cin.get();

    for(i = 0; i < cont; i++)
    {
        stack <char> diamantes;
        d = 0;
        getline(cin, valor, '\n');
        for(j = 0; j < valor.size(); j++)
        {
            if(valor[j] == '<')
            {
                diamantes.push('<');
            }
            else
            {
                if(valor[j] == '>' && !diamantes.empty())
                {
                    d++;
                    diamantes.pop();
                }
            }
        }
        cout << d << endl;
    }
    return 0;
}
