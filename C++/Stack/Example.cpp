#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> name;

    for(int i = 0; i < 10; i++)
        name.push(i);

    for(int i = 0; i < 10; i++){
        cout << name.top() << " ";
        name.pop();
    }
}
