// C++ program for the above approach
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    // Default constructor for making new nodes
    Node(){
        data = 0;
        next = NULL;
    }
    
    //Constructor if using parameters for making new Nodes
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//This is our MotherClass
//It will store a node that holds the head data, aka our runner
//We can create multiple instances of it and make many linkedLists
class Linkedlist {
    Node* head;
public:
    // Default constructor
    Linkedlist(){
        head = NULL;
        
    }
    
    void appendNode(int data);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int position);
};


//FUNCTIONS FOR THE LINKED LIST

//PREPENDING
//INSERTION

//DELETION
void Linkedlist::deleteNode(int position){
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < position) {
        cout << "Index out of range"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (position == 1) {
        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (position-- > 1) {
        // Update temp2
        temp2 = temp1;
        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}


//APPENDING
void Linkedlist::appendNode(int data){
    // Create the new Node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // append at the last.
    temp->next = newNode;
}

//DISPLAY
void Linkedlist::printList(){
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Driver Code
int main(){
    Linkedlist list;

    // appending nodes
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);

    cout << "Elements of the list are: ";

    // Print the list
    list.printList();
    cout << endl;

    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    return 0;
}
