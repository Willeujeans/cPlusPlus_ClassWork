// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    cout << "=========================" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "=========================" << endl;

}

int partition(int arr[], int start, int end){
    //Pivot value is always the element at start
    int pivotValue = arr[start];
    cout <<"Checking Element at " << start << endl;
    cout << "setting pivot value: " << pivotValue <<endl;
    
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivotValue){
            cout << "[" << i << " < " << pivotValue << "] ";
            count++;
        }
    }
    cout << endl;

    // Giving pivot element its correct position
    cout << "Moving our pivot elment " << count << " spaces right" << endl;
    int pivotIndex = start + count;
    cout << "PIVOT INDEX:" << pivotIndex <<endl;
    
    //We swap the elm at pivotIndex with our start, pivot index is the start+ amount of elements that are less than the pivot
    //EG. First run the pivot would be array[0] so its 9
    //we check every element that is less than 9
    //we then swap the pivot with our new pivot index
    //9 <->
    swap(arr[pivotIndex], arr[start]);
    cout << "SWAP: " << arr[pivotIndex] << " <-> " << arr[start] << endl;
    
    int i = start;
    int j = end;
    //While the start is less than the pivotIndex and the j is greater
    //We are insuring we don't wrap around
    //Once both sides close into eachother we know we are done.
    while (i < pivotIndex && j > pivotIndex) {
        cout<<"WHILELOOP"<<endl;
        while (arr[i] <= pivotValue) {
            cout << "WhileLoop for i: "<< i << endl;
            i++;
        }
        cout << "we found an element greater than the pivotValue! Its: " << arr[i] << " > " << pivotValue << endl;
        while (arr[j] > pivotValue) {
            cout << "WhileLoop for j: "<< j << endl;
            j--;
        }
        cout << "we found an element less than the pivotValue! Its: " << arr[j] << " < " << pivotValue << endl;
        
        if (i < pivotIndex && j > pivotIndex) { //this is a last check to make sure
            swap(arr[i], arr[j]); //swap them because we found a value greater than pivot before the pivot
            cout << "SWAPED: " << arr[i] << " <-> " << arr[j] << endl;
            i++; //Increment this will break the while loop
            j--; //Decrement this will break the while loop
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end){
    cout << "QUICK_SORTING..." << endl;
    cout << "START:" << start << " END:" << end << endl;
    
    // base case
    if (start >= end){
        cout << "BASE CASE!" << endl;
        return;
    }
    
    //whatever our pivot index was that is what our partition will be
    int p = partition(arr, 1, 7);
    cout << "PARTITION:" << p << endl;
    
    printArray(arr, 10);

//     //Calling quick sort on left side of partition
//     quickSort(arr, start, p - 1);
//     //Calling a quick sort on right side of partition
//     quickSort(arr, p + 1, end);
}

int main(){
    int arr[] = {10, 75, 51, 60, 70, 91, 83, 46};
    int size = 8;
    printArray(arr, size);
    //first quick sort call, array, 0 end = n-1
    cout << "First call will always be 0->sizeOfArray-1" << endl;
    quickSort(arr, 0, size - 1);
    printArray(arr,size);
    return 0;
}








