#include <iostream>
//#include "Animal.h"  DONT NEED because defined within dog.h
#include "Dog.h"
#include <string>

int main(){
    Dog guy("mister");
    guy.eat();
    return 0;
}
