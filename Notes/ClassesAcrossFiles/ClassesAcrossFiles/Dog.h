#include <iostream>
#include <fstream>
#include <string>

class Dog : public Animal {
    public:
        Dog(std::string name);
        void bark();
};
