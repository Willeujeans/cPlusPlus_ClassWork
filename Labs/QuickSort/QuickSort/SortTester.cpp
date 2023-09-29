
//============================================================================
// Name        : Sort Testing code
// Author      : Bonnie Bell
// Version     :
// Copyright   : Your copyright notice
// Description : Basic searching examples
//============================================================================
//READ ONLY
#include <iostream>
#include <time.h>
#include <cmath>
#include <fstream>

#include "SortTester.h"

using namespace std;

SortTester::SortTester(unsigned int numEntries) {
    srand(time(NULL));
    for (unsigned int i=0; i < numEntries; i++ ) {
        testList.push_back( rand() % 100);
    }
}

void SortTester::print() {
    for (auto & it : testList) {
        cout<<it<<" ";
    }
    cout<<"\n";
}

void SortTester::print(std::ofstream& testFeedback) {
    for (auto & it : testList) {
        testFeedback<<it<<" ";
    }
    testFeedback<<"\n";
}

int SortTester::compare(unsigned int a, unsigned int b) {
    return testList[a] - testList[b];
}

void SortTester::swap(unsigned int a, unsigned int b) {
    if ((testList[a] == testList[b]) and (a != b)) {
        stableSort= false;
    }
    if ( (a > testList.size()) or (b > testList.size()) ) {
        cout<<"Invalid swap request of "<<a<<" and "<<b<<" no swap performed"<<endl;
        return;
    }
    int temp = testList[a];
    testList[a] = testList[b];
    testList[b] = temp;
    return;
}

bool SortTester::isSorted() {
    bool sorted = true;
    for (unsigned int i=0; i < testList.size() - 1; i++) {
        if (testList[i] > testList[i+1] ) {
            sorted = false;
        }
    }
    if ( sorted ) {
        return true;
    } //implied else
    print();
    return false;
}
void SortTester::setMidPoint(uint start, uint end) {
   midpoint = testList[ (start + end)/2 ];
   return;
}

bool SortTester::verifyPartition(uint index, uint start, uint end) {
   for (uint i = start; i<=index; i++) {
      if (testList[i] > midpoint) {
         return false;
      }
   }
   for (uint i=index+1; i<=end; i++) {
      if (testList[i] < midpoint) {
         return false;
      }
   }
   return true;
}
