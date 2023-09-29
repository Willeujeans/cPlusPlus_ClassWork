#include <iostream>
using namespace std;
//We split the array
//Compare the elements at the start of both arrays
//If one is less, place it in final array, increment on that array
void display(int array[], int size){
    for(int i=0;i<size;i++){
       cout << array[i] << " ";
    }
    cout <<endl;
}

void combine(int array[], int start, int midPoint, int end){
    int* buffer = new int [end+1]; //This is the total size of array
    int k = start;
    
    while(k<=end){
        buffer[k] = array[k];
        k=k+1;
    }
    //These are our bounds
    int i = start;
    int j = midPoint+1;
    k = start;
    
    while(i<=midPoint && j <= end){
        if(buffer[i] <= buffer[j]){
            array[k] = buffer[i];
            i++;
        }else{
            array[k] = buffer[j];
            j++;
        }
        k=k+1;
    }
    while(i <= midPoint){
        array[k] = buffer[i];
        i++;
        k++;
    }
    while(j<=end){
       array[k] = buffer[j];
       j++;
       k++;
    }
    delete[] buffer;
}

//Runner
void mergeSorter(int array[], int start, int end){
    if(start >= end){
        return;
    }
    int midPoint = (start+end)/2;
    //leftSide
    mergeSorter(array,start,midPoint);
    //RightSide
    mergeSorter(array,midPoint+1,end);
    combine(array, start, midPoint, end);
}

//Mother Function
void mergeSort(int array[], int size){
    mergeSorter(array, 0 , size-1);
}

int main(){
    int array[] = {10,5,6,3,1,2,7,8,9,4};
    int size = sizeof(array)/sizeof(int);
    display(array, size);
    mergeSort(array, size);
    display(array, size);
    return 0;
}

