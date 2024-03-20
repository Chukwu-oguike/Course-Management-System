#include "Transcript.h"
#include "Semester.h"

Transcript::Transcript()//defaut constructor that creates an array of 14 semesters
{
  semesterList = new Semester[INIT_SEM_SIZE];// creates a dynamic array of 14 semesters
  
  semesterCapacity = INIT_SEM_SIZE;// updates the semesterCapacity
  
  semesterCount = 0;// updates the semesterCount
}


//checks if the array of semesters have not been given a semester name and returns true if so
bool Transcript::isSemesterEmpty()
{
  return(semesterList[0].getSemesterName() == EMPTY_SEM );// if the first semester is still initialize to 0 then the semester list is empty
}


//checks if the array of semesters have all been given semester names
bool Transcript::isSemesterFull()
{
  return(semesterList[semesterCapacity].getSemesterName() != EMPTY_SEM );// if the last semester on the list is no longer initialized to 0 then the list is full
}

string Transcript::getStudentID()
{
 return student_ID; 
}

int Transcript::getSemesterCount()
{
  return semesterCount;
}

// give a transcript a student ID
void Transcript::transcriptIdentity(string stdID)
{
  string student_ID = stdID;
}


// expands the array of semesters to accommodate more semesters
void Transcript::expandSemester()
{
  semesterCapacity = semesterCapacity + 2;// add two more semesters
  
  Semester* newSemesterList = new Semester[semesterCapacity];// creates a new, larger array of semesters  
  
  int count;// loop variable
  
  for(count = 0; count < INIT_SEM_SIZE; count++)
  // shalllow copying will suffice since we are not returning a copy of 
  //the semesters and this function will not be used often
  {
    newSemesterList[count] = semesterList[count];//shallow copying of each semester object in the array
  }
  
  semesterList = newSemesterList;// let go of the old array and holds onto a new one!
}


//fuction gives a name and a year to a given semester in the array of semesters
bool Transcript::addSemester(string semName, int semYear)
{
  bool found = false;// initialize to false
  
  if(isSemesterFull())//if the array of semesters has been exhausted, we will have to add more semesters to the array
  {
    expandSemester();// add more semesters
    
    semesterList[semesterCount].semesterIdentity(semName, semYear);//the value of the semester will be the index of the next empty array. give this semester a name and a year
    
    semesterList[semesterCount + 1].semesterIdentity(EMPTY_SEM, INIT_YEAR);// initialize the last semester to EMPTY
    
    semesterCount++;//update the semesterCount
    
    found = true;// update bool
  }
  
  else// if semester is not full
  {
     int count;// loop variable
  
     for(count = 0; count < semesterCapacity; count++)// search for the next semester initialized to 0 and use it
     {
         if(semesterList[count].getSemesterName() == EMPTY_SEM)// if a semester's name is still initialized to 0, use it
         {
	    semesterList[count].semesterIdentity(semName, semYear); 
	    
	    semesterCount++;//udate semesterCount
	   
	    found = true;// update the bool
	
	    break;// once the nearest empty semester has been found, leave this loop
         }
  
    }
  }
  
  return found; //return the bool function: true if the addfunction was successfull
}