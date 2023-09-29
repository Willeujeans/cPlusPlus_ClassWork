#include <iostream>
using namespace std;

void print(int array[], int size){
    for(int i =0;i<size;i++){
        cout << array[i] << " ";
    }
}

void swap(int array[], int a, int b){
    cout << "swapped" << array[a] << " <-> " << array[b] << endl;
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void bubble(int array[], int size){
    //Runner
    for(int foot = size-1;foot>0;foot--){
        int footBefore = foot-1;
        if(array[foot] < array[footBefore]){
            swap(array, foot, footBefore);
        }
    }
}

void bubbleSort(int array[], int size){
    int steppers_steps = 0;
    //Stepper
    for(int step = 0;step<size-1;step++){
        steppers_steps++;
        bubble(array,size);
    }
    cout << "steps: " << steppers_steps << endl;
}

int main(){
    int array[] = {10,5,6,3,4,2,1,7,8,9};
    int size = sizeof(array)/sizeof(int);
    print(array, size);
    bubbleSort(array, size);
    print(array, size);
    return 0;
}

