#include <iostream>
#include <list>

using namespace std;

int main(){
    int Nodd = 0, Yodd = 0, Mb5 = 0;
    list <int> ListOfNumbers;

    for(int i = 0; i < 10; i++)
        ListOfNumbers.push_back(i+1);

    for(list <int> ::iterator Var = ListOfNumbers.begin(); Var != ListOfNumbers.end(); Var++){
        if(*Var % 5 == 0){
            Mb5 += 1;
            if(*Var % 2 == 0)
                Nodd++;
            else
                Yodd++;
        }
        else if(*Var % 2 == 0)
            Nodd = Nodd + 1;
        else
            Yodd++;
    }
    printf("Pair = %d\nOdd = %d\nMpB5 = %d\n", Nodd, Yodd, Mb5);
}
