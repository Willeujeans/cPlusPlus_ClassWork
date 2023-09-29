//
//  main.cpp
//  LinkedListScratch
//
//  Created by Will Schmitz on 9/29/23.
//

#include <iostream>

class Node {
  public:
    int data;
    Node* next;
    
    
    //constructors
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    
    Node(int data){
        this->data = data;
    }
};

class List{
    public:
    Node* permHead;
    
    List(){
        permHead = NULL;
    }
    
    void prePendNode(int t_data){
        Node* newGuy = new Node(t_data);
        newGuy->next = permHead;
        permHead = newGuy;
    }
    
    
    void appendNode(int t_data){
        Node* walker = this->permHead;
        std::cout << walker->data << std::endl;
        while(walker->next != NULL){
            walker = walker->next;
            std::cout << walker->data << std::endl;
        }
        Node* newGuy = new Node(t_data);
        walker->next = newGuy;
        newGuy->next = NULL;
        
        std::cout << "added new node!" << std::endl;
    }
    
    void print(){
        std::cout << "PRINTING..." << std::endl;
        Node* walker = this->permHead;
        std::cout << walker->data << std::endl;
        while(walker->next != NULL){
            walker = walker->next;
            std::cout << walker->data << std::endl;
        }

        
        
    }
};

int main(int argc, const char * argv[]) {
    List myList;
    myList.permHead = new Node(1);
    myList.permHead->next = NULL;
    myList.appendNode(55);
    myList.prePendNode(700);
    myList.print();
}
