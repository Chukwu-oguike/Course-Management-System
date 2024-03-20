#include<iostream>
#include<cstdlib>
#include "Course.h"
#include "Transcript.h"
#include "Semester.h"
#include "TOT.h"

using namespace std;

int main()
{
  string st_ID = "1120365";// variable to store student id
  
  string Sem_ester = "Fall Semester";//variable to store semester name
  
  string cour_se = "comp15";//variable to store course name
  
  string gra_de = "A+";// variable to store course grade
  
  int ye_ar = 2013;//variable to store semeter year
  
  Transcript test3;// declare a transcript object
  
  Transcript* testPtr;// declare a pointer to store the address of this object
  
  cout<<test3.isSemesterEmpty()<<endl;// print out the result of this function
  
  cout<<test3.isSemesterFull()<<endl;// print out the result of this function
  
  test3.transcriptIdentity(st_ID);//give the transcript a name
  
  test3.addSemester(Sem_ester, ye_ar);// name a semester in the transcript and give the semester a year
  
  test3.semesterList[0].addCourse(cour_se);// add a course to the semester
  
  test3.semesterList[0].addGrade(cour_se, gra_de);//add a grade to this course
  
  testPtr = &test3;// store the address of this object
  
  TOT testTOT;// declare an object of class TOT
  
  testTOT.addTranscript(testPtr);// test the add function with the transcript just created
  
  cout<<testTOT.getTranscriptCopy(st_ID);// test the add function with the transcript just created
  
  
  return 0;
}