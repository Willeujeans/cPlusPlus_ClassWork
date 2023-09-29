/*
LINKED-LISTS
-Important to understand how and when to check for the end condition of a linked list.
FUNCTION:
 int addLists(Node* listA, Node* listB){
    The two linked lists represent numbers
 }
 

 Each element in the list is a digit with the least significant number in the first link position ie: the number 1234 will be represented as list->4 ->3 -> 2->1. Your job is to add the two numbers and return the sum.
 
 (There is 25 points available in the tests, the tests will check if you correctly return the sum when the two numbers are relatively close in size, when A is much bigger than B ect.)
 
 EXTRA-CREDIT (Not tested) 5pts:
 Write a recursive algorithm
 -That traverses the lists that sums the numbers recursively
 -No global variables, the accumulate must be based on and returned in the recursive call.
 */


//============================================================================
// Name        :
// Author      : Bonnie Bell
// Version     :
// Copyright   : Your copyright notice
// Description : Linked List Fun
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include "Node.h"
using namespace std;
typedef unsigned int uint;

//Simply iterates through the list to print it
void printList(Node* list) {
    while (list != nullptr) {
        cout << list->data << "  ";
        list = list->next;
    }
    cout << endl;
}

int addLists(Node* listA, Node* listB) {
    /*
     REQUIREMENTS:
     -The linked lists {listA, listB} represents numbers
     -Each element in the list is a digit
     -[1234] becomes [list->4 ->3 -> 2->1]
     -Add the two lists together
     -Return the sum
     
     TODO:
     -Traverse the lists
     -Put the stored integers into numbers
     -Add them together
     -Return the sum
     */
    cout << listA << endl;
    cout << listB << endl;
    
    return 0;
}

Node* genList(int number) {
    //takes in number
    //Creates a new node
    Node* headOfList = new Node(number%10);
    Node* listIterator = headOfList;
    
    number = number / 10;
    while (number > 0) {
        //listIterator's next becomes a new node
        listIterator->next = new Node(number%10);
        //ListIterator is now a new ndoe
        listIterator = listIterator->next;
        number = number/10;
    }
    
    //returns a new node
    return headOfList;
}

int main() {
    //Initilizes the randomization
    srand(time(NULL));
    
    //Creating a random List
    int numA = rand()%10000000;
    int numB = rand()%10000000;
    Node* listA = genList(numA);
    Node* listB = genList(numB);
    
    //Calling our Addlists with the new random Lists
    int sum = addLists(listA, listB);
    
    //Pass Checker
    if ( sum == (numA + numB)) {
        cout<<"PASSED basic test (9 pts)"<<endl;
    }else{
        cout<<"FAILED expected: "<<numA + numB<<" actual: "<<sum<<endl;
    }
    
    //Creating a random List
    int numC = rand()%100<<12;
    int numD = rand()%100;
    Node* listC = genList(numC);
    Node* listD = genList(numD);
    
    //Calling our Addlists with the new random Lists
    sum = addLists(listC, listD);
    
    //Pass Checker
    if ( sum == (numC + numD)) {
    //cout<<"PASSED A: "<<numA<<" much greater than B:"<<numD<<endl;
        cout<<"PASSED A much greater than B (8 pts)"<<endl;
    }else{
        cout<<"FAILED expected: "<<numC + numD<<" actual: "<<sum<<endl;
    }

    //Create Random List
    int numF = rand()%100<<12;
    int numE = rand()%100;
    Node* listE = genList(numE);
    Node* listF = genList(numF);
    
    //Calling our Addlists with the new random Lists
    sum = addLists(listE, listF);
    if ( sum == (numE + numF)) {
    //cout<<"PASSED B: "<<numF<<" much greater than A:"<<numE<<endl;
        cout<<"PASSED B much greater than A (8 pts)"<<endl;
    }else{
        cout<<"FAILED expected: "<<numE + numF<<" actual: "<<sum<<endl;
    }

    //standard return
    return 0;
}

