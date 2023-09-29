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
    
    //Default Constructor
    Drink(){
        int size = 0;
        std::cout << size << std::endl;
    }
    
    //Constructor w/ params
    //':' allows us to set its menuItem type to the same name
    Drink(std::string set_name, int set_size) : MenuItem(set_name){
        size = set_size;
    }
};


int main(){
    //Instance Created with params
    Drink lemonade("steve", 20);
    
    //Method called from ParentClass
    lemonade.sayMyName();
    return 0;
}



