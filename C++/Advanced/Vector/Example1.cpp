/**
    This Example is one of My Studies of Google Software Engineer Interview
    You Can check it here : https://www.youtube.com/watch?v=XKu_SEDAykw
**/
#include <iostream>
#include <vector>
#include <stdbool.h>
#include <unordered_set>

using namespace std;

bool TrueValue(vector<int> Numbers, int Searched){
    unordered_set<int> aux;
    for(int i : Numbers){
        if(aux.find(i) != aux.end())
            return true;
        aux.insert(Searched - i);
    }
    return false;
}

int main(bool){
    vector <int> Numbers;

    //for(int i = 0; i < 4; i++)
    Numbers.push_back(1);
    Numbers.push_back(2);
    Numbers.push_back(4);
    Numbers.push_back(4);

   return TrueValue(Numbers, 8);
}
