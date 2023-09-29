#include <iostream> //Console input and output
#include <vector> //Resizable array
#include "Record.h" //File that we are pulling the record structure

using namespace std;

//takes in (employees array)
void printRecords(vector<Record*> employees) {
    //for each loop, that will print out each employee in the array
    for ( auto it:employees) {
        it->print();
    }
}

//takes in (field to sort by, the employee array)
void sortBy(Record::fieldType sortField, vector<Record*> &employees) {
    bool sorted = false;
    
    //While the array is not sorted
    while (!sorted) {
        
        //We assume array is sorted at the start
        sorted = true;
        
        //unsigned means it can't be negative, we loop through the entire array
        for (unsigned int i=0; i < employees.size()-1; i++) {
            
            //Standard bubble sort
            //our compare function, if greater than 0 then swap
            if (employees[i]->compare(sortField, employees[i+1]) > 0 ) {
                Record* temp = employees[i];
                employees[i] = employees[i+1];
                employees[i+1] = temp;
                
                //Set to false sorted because we had to swap data
                sorted = false;
            }
        }
     }
}


int main() {
    //creates a resizable array of employees, pointing to the type that is "Record"
    std::vector<Record*> employees;
    
    //Uses a record constructor to make a new record, then places it into the employee array
    employees.push_back(new Record("David", "Bowie", 5,  8,  0));
    employees.push_back(new Record("Kim",   "Kardashian", 15, 9, 2));
    employees.push_back(new Record("Khloe", "Kardashian", 5, 10, 3));
    employees.push_back(new Record("David", "Lee Roth", 9, 4, 1));
    employees.push_back(new Record("Greta", "Garbo", 1, 3, 5));
    
    //Start
    cout<<"Unsorted"<<endl;
    printRecords(employees);
    cout<<"enter a field (0-4) to sort by:";
    
    //user interaction
    int sortField;
    cin>>sortField;
    
    //Choice affects which field is passed into the function for sorting
    switch (sortField) {
        case 0: sortBy(Record::firstNameField, employees); break;
        case 1: sortBy(Record::lastNameField, employees); break;
        case 2: sortBy(Record::yearsInServiceField, employees); break;
        case 3: sortBy(Record::incomeGradeField, employees); break;
        case 4: sortBy(Record::reviewPerformanceField, employees); break;
        //nothing matches
        default:cout<<"Unknown field"<<endl;
    }
    
    //End
    cout<<endl;
    cout<<"Sorted"<<endl;
    printRecords(employees);
    
    return (0);
}

