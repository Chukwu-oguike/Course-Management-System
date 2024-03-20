#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#include <iostream>
#include <cstdlib>
#include "Course.h"
#include "Semester.h"
using namespace std;

const int INIT_SEM_SIZE = 14;// we are starting with 14 semesters
const string EMPTY_SEM = "Empty semester";
const int INIT_YEAR = 0;

class Transcript
{
  public: 
    bool addSemester(string semName, int semYear);
    //takes in a sring for the semester's name and an integer for the semester year
    // then it labels one of the elements in the semester array with these 
    
    bool isSemesterEmpty();
    // checks if array of semesters is empty
    //returns true if the sequence is empty
    // otherwise returns false
    
    bool isSemesterFull();
    // checks if the array of semesters is full
    //returns true if the sequence is full
    // otherwise returns false
    
    void expandSemester();
    //expands the dynamic array of semesters 
    //and copies the content of the old array into the new array
    
    string getStudentID();
    // function allows other classes make reference to the student_ID
    
    int getSemesterCount();
    // function allows other classes make reference to the semesterCount
    
    Transcript();
    //Constructor creates an array of 14 semesters and initializes the studentID
  
    void transcriptIdentity(string stdID);
    //takes in a string and gives a transcript a studentID with the string
  
    Semester *semesterList;
    // pointer to an array of semesters
    
  private:
    
    string student_ID;
    //store the studentID 
    
    int semesterCount;
    // stores the number of semsters taken
    
    int semesterCapacity;
    
    
   
};

#endif


