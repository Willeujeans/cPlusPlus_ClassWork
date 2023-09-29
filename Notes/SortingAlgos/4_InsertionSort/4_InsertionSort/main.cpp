#include <stdio.h>
#include <iostream>
using namespace std;

void display(int array[], int size){
    for(int i=0;i<size;i++){
       cout << array[i] << " ";
    }
    cout <<endl;
}
//Pass in the array and size
//We start our loop at 1
void insertElementAtPosition(int array[], int size, int step){
    //we grab the value our stepper is currently over
    int valueAtStep = array[step];
    //foot will start 1 behind our step
    int foot = step - 1;
    //Runner
    //Comparitor
    while(foot>=0 && array[foot] > valueAtStep){
        //everytime our foot is greater than the value we pulled
        //set the element ahead of the foot equal to the foot element
        cout << array[foot+1] << " = " << array[foot] << endl;
        array[foot+1] = array[foot];
        foot = foot-1;
    }
    //This will happen on first call
    cout << array[foot+1] << " = " << valueAtStep << endl;
    array[foot+1] = valueAtStep;
    display(array, size);
}

void insertionSort(int array[], int size){
    //stepper
    int step = 1;
    while(step < size){
        insertElementAtPosition(array,size,step);
        step++;
    }
}

int main(){
    int array[] = {10,5,6,3,1,2,7,8,9,4};
    int size = sizeof(array)/sizeof(int);
    insertionSort(array, size);
    display(array, size);
    return 0;
}



