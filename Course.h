#ifndef COURSE_H
#define COURSE_H
#include <iostream>

using namespace std;

class Course
{ 
  public:
   string courseNumber;
   // store the coures name
   
   string courseGrade;
   //stores the course grade
   
   Course* next;
   // points to next course in a given semester
};

#endif