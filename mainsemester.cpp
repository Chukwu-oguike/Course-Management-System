#include<iostream>
#include<cstdlib>
#include"Semester.h"

using namespace std;

int main()
{
  Semester testS;//declare an object of class semester
  
  cout<<testS.isCourseListEmpty();//test function
  
 testS.addCourse(comp11);// test function in Semester class
 
 testS.addCourse(comp40);// test function in Semester class
 
 testS.addCourse(comp104);// test function in Semester class
 
 testS.addCourse(ECOOO5);
 
 testS.addCourse(comp15);// test function in Semester class
 
 cout<<numCourses<<semesterCapacity<<endl;// test function in Semester class
  
  
  
  return 0;
}