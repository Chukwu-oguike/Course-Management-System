#include "Semester.h"
#include "Course.h"

// default constructor that creates a linked list of four courses
Semester::Semester()
{
  int count;//loop control variable 
    
  head = NULL;//initialize head
   
  Course *newCourse;// create new pointer to create linked list
   
  for(count = 0; count < INIT_COURSE_SIZE; count++)// create a linked list of length 4 
  {
  
     newCourse = new Course;//creates a node
     
     newCourse->courseNumber = INIT_COURSE_NAME; //initializes this member of the node 
     
     newCourse->courseGrade = INIT_COURSE_GRADE;//initializes this member of the node
     
     newCourse->next = NULL;
       
     if(head == NULL)//if first is NULL then the list is empty
      {
	head = newCourse;
	tail = newCourse;
      }
       
     else//the list is not empty
     {
       tail->next = newCourse; // insert newCourse at the end of the list
       tail = newCourse;//set tail to point to the last node
     }
     
  }
  
  courseCapacity = INIT_COURSE_SIZE; // update the courseCapacity
  
  numCourses = 0;// initialize the member
  
  semesterName = INIT_COURSE_NAME;// initialize the member
  
  semesterYear = 0;// initialize the member
   
   
}

//check if any courses have been registered
bool Semester::isCourseListEmpty() 
{
  return (head->courseNumber == INIT_COURSE_NAME);// return true if no courses have been registered
}

// check if the linked list of courses has been exhausted
bool Semester::isCourseListFull()
{
  Course* current;// create loop control pointer
  
  current = head;// initialize it to head
  
  while(current->next != NULL)//iterate to the last node in the list
  {
    current = current->next;
  }
  
  return(current->courseNumber != INIT_COURSE_NAME);//check if the last node on the list is still initialized to 0
}

// expands the linked list to include more courses
void Semester::expandCourse()
{
    Course* newCourse = new Course;// create a new node
    
    newCourse->next = //NULL;initialize the pointer in this node to NULL
    
    tail->next = newCourse;//point the last node in the list to this node
    
    tail = newCourse; //set tail to point to the last node
}

string Semester::getSemesterName()//function makes this value aaccessable
{
  return semesterName;
}

Course* Semester::getHead()//function makes this value accessable
{
  return head; 
}

int Semester::getSemesterYear()//function makes this value aaccessable
{
  return semesterYear;
}

int Semester::getnumCourses()//function makes this value aaccessable
{
  return numCourses;
}

void Semester::semesterIdentity(string sem_Name, int yea_r)
// Function takes a string for and an integer and uses these arguments to give semesters their identity 
{
  
  semesterName = sem_Name;
  
  semesterYear = yea_r;
}

// adds a course to the linked list
void Semester::addCourse(string cNum)
{
  if(isCourseListFull())//check if the linked list is full
  {
    expandCourse();//if so, add another node
    
    tail->courseNumber = cNum;//store the course number in this new node
    
    courseCapacity++;// update the course capacity
    
    numCourses  = courseCapacity;// number of courses must be equal to the course capacity
  }
  
  else// if the linked list is not full
  {
     Course* current;//create loop control pointer
  
     current = head;// initialize it to head
  
     while(current->courseNumber != INIT_COURSE_NAME)// search for the next empty node in the list
       {
         current = current->next;
       }
  
     current->courseNumber = cNum;//add course to the node found
     
     numCourses++; //update the number of courses
  }
}

//search for a course and give it a grade
bool Semester::addGrade(string courseNum, string g_rade)
{
  Course* current;// creates a dummy node
  
  current = head;// initialize it to head
  
  bool found = false;// initialize the bool function
  
  int count;//loop variable
  
  for(count = 0; count < courseCapacity; count++ )// create loop to iterate through the linked list
  {
     if(courseNum == current->courseNumber)// check if the course number of the node matches the course number given
     {
       found = true;//if so, update found
       
       current->courseGrade = g_rade;// give this course a grade
       
       break;//exit the loop
     }
     
     else//check if the course number of the node doesn't matche the course number given
     {
       current = current->next;
     }
     
  }
  
  
  return found;// return true if the you were able to add a grade to the course
}


