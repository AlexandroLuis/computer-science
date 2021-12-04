#include <iostream>
#include <string>
using namespace std;

int main(){
  string name;
  cout << "Hey, What's your name? " << endl;
  getline (cin, name);
  cout << "How's going, " << name << "?\n";
}
