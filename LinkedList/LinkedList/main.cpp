#include <iostream>
using namespace std;
/*
 Linked Lists
 Librarian{
    head: node
    tail: next of last node
 }
 node{
    data: anything
    next: points to next of another node
 }
*/

struct node {
  int data; //data
  node *next; //pointer to another node instance
};

void printLinkedList(node *root, node *conductor){
    conductor = root;
    if ( conductor != NULL ) {
      while ( conductor->next != NULL ) {
        cout<< conductor->data <<endl;
        conductor = conductor->next;
      }
      cout << conductor->data << endl;
    }
}


void appendNode(node *conductor, int data){
    if (conductor != NULL) { //as long as conductor exsists
        //the conductor traverses the list
        while (conductor->next != NULL){
            //setting itself equal to where its pointing will give it a new pointer
            //Until it hits the last node in the list
            conductor = conductor->next;
        }
    }
    
    //we make a new node
    node *myNode = new node;
    myNode->data = data;
    myNode->next = NULL;
    conductor->next = myNode;
    //make the conductor equal to that node
    conductor = conductor->next;
    //set its next to Null to show we are at the end of the list
    conductor->next = NULL;
    
}

int main(int argc, const char * argv[]) {
    node *root = new node; //Created our first node
    root->next = NULL; //Because the list is one node long we point to nothing
    root->data = 14; //we populated the root nodes data, this could be anything
    
    node *conductor = root; //Now our conductor is a pointer to the root node
    //Conductor is now a node with a next: NULL, data of 14
    
    cout << "Conductor's Data: " << conductor->data << endl;
    cout << "Conductor's Next: " << conductor->next << endl;
    
    appendNode(conductor,17);
    appendNode(conductor,16);
    appendNode(conductor,6);
    
    printLinkedList(root, conductor);
    
    return 0;
}
