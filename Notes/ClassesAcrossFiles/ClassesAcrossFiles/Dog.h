#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"

class Dog : public Animal {
    public:
        Dog(std::string name);
        void bark();
};
