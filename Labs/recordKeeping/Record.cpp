#include "Record.h"
#include <string>

using namespace std;

//This is a constructor, we pass in arguments which will then create a Record object with predefined structure
Record::Record(std::string first, std::string last, int years, int grade , int review) {
    firstName = first;
    lastName = last;
    yearsInService = years;
    incomeGrade = grade;
    reviewPerformance = min(3,review);
}

//A function Records have allowing them print results themselves
void Record::print() {
    cout << "Name: " << lastName <<", "<< firstName << ", years in service:" << yearsInService << ", grade: " << incomeGrade << ", last review: ";
    
    //This is used to format the review to display as words instead of numbers
    switch (reviewPerformance) {
    case 0: cout<<"Improvement Plan"<<endl; break;
    case 1: cout<<"Below Expectations"<<endl; break;
    case 2: cout<<"Meets Expectations"<<endl; break;
    case 3: cout<<"Outstanding"<<endl; break;
    }
}

//Exsists within a Record, is given (field to sort by, Record to Compare with)
int Record::compare(Record::fieldType field, Record* compareRecord) {
    //we use -> instead of . because we are accessing a pointer
    //we can call "this"
    if(field == 0){
        return this->firstName.compare(compareRecord->firstName);
        
    }else if(field == 1){
        return this->lastName.compare(compareRecord->lastName);
        
    }else if(field == 2){
        return  this->yearsInService - compareRecord->yearsInService;
        
    }else if(field == 3){
        return this->incomeGrade - compareRecord->incomeGrade;
        
    }else if(field == 4){
        return this->reviewPerformance - compareRecord->reviewPerformance;
    }else{
        return 0;
    }
    
    return 0;
}
