#include "Dog.h"
#include <string>

//Constructor function
Dog::Dog(std::string name) {
    myName = name;
}

void Dog::bark(){
    std::cout << myName << " is barking" << std::endl;
}
