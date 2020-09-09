#include <iostream>
#include <string>
using namespace std;

int main()
{
  string name;
  cout << "Hello, What's your name? " << endl;
  getline (cin, name);
  cout << "Hello, " << name << "!\n";
}
