/*
 * SortTester.h
 *
 *  Created on: Jan 30, 2021
 *      Author: cj6bo
 */

#include <fstream>
#include <vector>


class SortTester {
    private:
        std::vector<int> testList;
        int midpoint;
        bool stableSort;

    public:
        SortTester(unsigned int numEntries);
        void swap(unsigned int a, unsigned int b);
        //returns positive number if a > b, 0 if a==b, and negative number if a < b
        int compare(unsigned int a, unsigned int b);
        void print();
        void print(std::ofstream& testFeedback);
        void setMidPoint(uint start, uint end);
        bool verifyPartition(uint index, uint start, uint end);

        bool isSorted();
};
