#include <iostream>

using namespace std;

class Mammal{
public:
  void Sound(){
    cout << "Mammal Sounds: ";
  }
};

class Cow: public Mammal{
public:
  void CowSound(){
    cout << "Muuu";
  }
};

int main( )
{
  Mammal animal;
  Cow animalcow;

  Mammal *Pointer_mammal = &animalcow;

  Cow *Pointer_animalcow =  (Cow *) &animal;

  Pointer_mammal -> Sound();
  Pointer_animalcow -> CowSound();

  return 0;
}
