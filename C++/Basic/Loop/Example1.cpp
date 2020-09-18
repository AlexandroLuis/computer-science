#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int *P, i;

    P = (int*) malloc(10* sizeof(int));

    for(i = 0; i < 10; i++)
        *(P+i) = i;

    i = -1;
    while(i++ < 9){
        cout << *(P+i) << " ";
    }
}
