#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include <cstdlib>
#include "Course.h"

using namespace std;

const int INIT_COURSE_SIZE = 4;

const string INIT_COURSE_NAME = "Empty course";

const string INIT_COURSE_GRADE = "No Grade";

class Semester
{
  public:
    void addCourse(string cNum);
    //adds a course to the semester
    
    bool isCourseListEmpty();
    // checks if there are any courses taken in a given semester
    //returns true if the sequence is empty
    // otherwise returns false
    
    bool isCourseListFull();
    // checks if course list is full
    //returns true if the sequence is full
    // otherwise returns false
    
    bool addGrade(string courseNum, string g_rade);
    //assigns a grade to a certain course
    
    void semesterIdentity(string sem_Name, int year);
    //function initializes the semesterName and semesterYear (private members)
    
    void expandCourse();
    
    string getSemesterName();
    // function allows other classes make reference to the semesterName
    
    Course* getHead();
    // function allows other classes make reference to the Head pointer 
    
    int getSemesterYear();
    // function allows other classes make reference to the semesterYear
    
    int getnumCourses();
    // function allows other classes make reference to the numCourses
    
    
    Semester();
    //default constructor that creates a linked list of length 4 ( average amount of courses taken per semester)
    
  private:
    
    string semesterName;
    //stores the name of the semester
    
    int semesterYear;
    //stores the year of the semester
    
    int numCourses;
    //keeps track of the number of courses taken in a semester
    
    int courseCapacity;
    //keep track of the number of courses that can be added
    
    Course* head;
    //pointer to the first node on the list
    
    Course* tail;
    //pointer to the last node on the list
};

#endif

