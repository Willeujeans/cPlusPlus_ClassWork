#include "Animal.h"
#include <string>

//Constructor function
Animal::Animal(std::string name) {
    myName = name;
}

void Animal::eat(){
    std::cout << myName << " is eating." << std::endl;
}
