#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int *P, i;

    P = (int*) malloc(10* sizeof(int));

    for(i = 1; i < 11; i++)
        *(P+i) = i;

    i = 0;
    while(i++ < 10){
        cout << *(P+i) << " ";
    }
}
