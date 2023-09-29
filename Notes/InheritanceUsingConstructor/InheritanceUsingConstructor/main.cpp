#include <stdio.h>
#include <iostream>
#include <string>

//ParentClass
class MenuItem{
    public:
        std::string name;
    
    //Default Constructor
    MenuItem(){
        name = "unknown";
        std::cout << "MenuItem Class Constructor" << std::endl;
    }
    
    //Constructor w/ Parameters
    MenuItem(std::string set_name){
        name = set_name;
        std::cout << "Base Class Constructor with Params" << std::endl;
    }
    
    //Function
    void sayMyName(){
        std::cout << name << std::endl;
    }
};

//Child Class
class Drink : public MenuItem{
    public:
    int size;
    
    //Child now inherits all Parent constructors
    using MenuItem::MenuItem;
};


int main(){
    //Instance Created with params
    Drink lemonade("steve");
    //Method called from ParentClass
    lemonade.sayMyName();
    return 0;
}




