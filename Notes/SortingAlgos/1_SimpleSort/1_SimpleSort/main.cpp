#include <iostream>

using namespace std;

int main(){
    int array[4] = {2,3,1,5};
    int size = 4;
    
    //Stepper
    for(int i=0; i < size; i++){
        //Runner
        for(int j=i; j < size; j++){
            //Comparitor
            if(array[i] > array[j]){
            //swapper
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
        }
    }
    
    for(int k=0; k < size; k++){
        cout << array[k] << endl;
    }
    return 0;
}

