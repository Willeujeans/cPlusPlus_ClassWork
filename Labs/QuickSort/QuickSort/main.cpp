//============================================================================
// Name        :
// Author      : Bonnie Bell
// Version     :
// Copyright   : Your copyright notice
// Description : Quick and Merge Sort
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include "SortTester.h"
using namespace std;
typedef unsigned int uint;

//Bugged, only swapping with same element
uint partition(SortTester &tester, uint low, uint high) {
   unsigned int midpoint = low + (high-low)/2;
   cout << "MidPoint: " << midpoint << endl;
   unsigned int lo = low;
   unsigned int hi = high;
   
   bool done = false;
   while (!done) {
      while (tester.compare(lo,midpoint) < 0) {
        lo=lo+1;
      }
      while (tester.compare(midpoint, hi) < 0) {
         hi=hi-1;
      }
      if (lo >= hi) {
         done = true;
      }
      else{
         tester.swap(hi,lo);
         cout << "Swapped" << endl;
         lo=lo+1;
         hi=hi-1;
      }
   }
   cout << "THIS IS HI: " << hi << endl;
   return hi;
}



//MotherFunction, Good nothing wrong here
void quickSort(SortTester &tester, uint low, uint high) {
    if (high <= low) {
        return;
    }
        int pos = partition(tester, low, high);
        //Left
        quickSort(tester, low, pos);
        //Right
        quickSort(tester, pos+1, high);
}

//Good nothing wrong here
int main() {
    uint size = 20;
    SortTester tester = SortTester(size);
    cout<<"Unsorted"<<endl;
    tester.print();
    quickSort(tester, 0, size-1);
    if (tester.isSorted()) {
        tester.print();
        cout<<"PASSED List Sorted (5 pts)"<<endl;
    }
    else {
        tester.print();
        cout<<"FAILED List not Sorted"<<endl;
    }
}
