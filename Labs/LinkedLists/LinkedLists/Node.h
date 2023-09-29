/*
 *   Created on: Jan 30, 2021
 *      Author: cj6bo
 */
//READ ONLY
#include <iostream>
//standard Node used within a linked list
class Node {
    //Anyone can access these
    public:
        //data being held within node
        int data;
        //pointer to next node
        Node* next;
        //constructor for a node class object
        Node(int data, Node* next=nullptr);
};
