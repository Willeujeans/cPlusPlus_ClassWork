/*
Selection Sort
Its a simple sorting algorithm with 3 parts
Mother function
    -Searcher
    -Swapper
The Mother Function (stepper)
    -She will slowly step through the array element by element
    -She will then call the searcher given the step she is on
    -The searcher will activate a runner that will compare every element right of the step to see if anything is lesser
    -Once it finds a lower element it returns that to the mother Function
    -The mother function then activate the swapper, given the step and smallest element
    -Swapper will swap, and the stepper will move to the next step in the array
*/

#include <iostream>
using namespace std;

//Display
void print(int array[],int size){
    int i = 0;
    while(i < size){
        cout << array[i] << " ";
        i++;
    }
    cout << endl;
}

//Swapper
void swap(int array[], int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

//Searcher
int index_Of_Smallest(int array[], int index, int size){
    int foot = index;
    int index_smallest = foot;
    //Runner
    while(foot <= size){
        //Comparitor
        if(array[foot] < array[index_smallest]){
            //Indexer
            index_smallest = foot;
        }
        foot++;
    }
    return index_smallest;
}

//Mother_Function
void selectionSort(int array[], int size){
    int steps = 0;
    //Stepper
    while(steps < size-1){
        int index_smallestElm = index_Of_Smallest(array,steps,size-1);
        //we swap the current index with the smallest element ahead of it
        swap(array, steps, index_smallestElm);
        steps++;
        print(array,size);
    }
}

//Execution_Point
int main(){
    int array[] = {10,5,4,2,1,6,7,8,9};
    //Gives you the amount of elements in your array
    int size = sizeof(array)/sizeof(int);
    selectionSort(array, size);
    return 0;
}


