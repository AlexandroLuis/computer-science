#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b; // le a entrada
    int quociente = (b*2)-a ;
    if(quociente < 0)
        quociente = quociente*(-1);

    cout << quociente << endl; // escreve a resposta
    return 0;
}
