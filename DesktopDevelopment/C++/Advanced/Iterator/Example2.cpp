#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> Numbers;
    int NumbersToFillTheList, Higher = -100, Lower = 999;

    for(int i = 0; i < 10;i++){
        NumbersToFillTheList = i+3 ;
        Numbers.push_back(NumbersToFillTheList);
    }
    for(list <int> ::iterator Var = Numbers.begin(); Var != Numbers.end(); Var++){
        if(Higher < *Var)
            Higher = *Var;
        if(Lower > *Var)
            Lower = *Var;
    }
    cout << "H " <<Higher << " - L " << Lower<< endl; /** H 12 - L 3 **/
}
