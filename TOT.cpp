#include "TOT.h"
#include "Transcript.h"
#include "Semester.h"
#include "Course.h"

//default constructor creates an array of pointers
TOT::TOT()
{
  
  Transcript** transcripts = new Transcript*[INIT_SIZE];//declares an array of pointers
  
  int count;// loop control variable
  
  for(count = 0; count < INIT_SIZE; count++)//loop initializes all pointers to NULL
  {
    transcripts[count] = NULL;//set all pointers to NULL
  }
  
  currentCapacity = INIT_SIZE;//update currentCapacity
  
  currentCount = 0;//update currentCount
}


// constructor creates a dynamic array of pointer to transcripts
TOT::TOT(Transcript* transcriptList, int listSize)
{
  Transcript** transcripts = new Transcript*[listSize];//declare an array of size listSize
  
  currentCapacity = listSize;// update currentCapacity
  
  int count1;
  
  newTranscript1 = new Transcript[listSize];
  
  for(count1 = 0; count1 < currentCapacity; count1++)
  {
    newTranscript1[count1] = transcriptList[count1];
  }
  
  currentCount = 0;//initializes currentCount
  
  int count;//loop control variable
  
  for(count = 0; count < currentCapacity; count++)//add all these pointers to the dynamic memory created
  {
    transcripts[count] = &newTranscript1[count];
  }
}

//function takes in a pointer to a transcript and adds this to the dynamic array of pointers
bool TOT::addTranscript(Transcript* t)
{
  bool con_firm = false;//bool to check if a transcript was successfully added
  
  if(currentCapacity == currentCount)// check if the array of pointers is full
  {
    expand();//if full then expand array
    
    transcripts[currentCount] = t;//add pointer (t) to the list of transcripts
    
    currentCount++;//update currentCount
    
    con_firm = true;// update boolean
    
  }
  
  else// the list my have space if it is not empty
  {
    transcripts[currentCount] = t;//add pointer (t) to the list of transcripts
	
    currentCount++;//update currentCount
	
    con_firm = true;// update boolean
    
  }
  
  return con_firm;
}


//function to expand dynamic array of transcripts 
void TOT::expand()
{
  currentCapacity = (currentCapacity * RESIZE_FACTER ); //update the new currentCapacity
  
  Transcript** newTranscript = new Transcript*[currentCapacity];// make an array of the size of the new capacity
  
  int count;//loop control variable
  
  for(count = 0; count < currentCount; count++) //shallow copying
  {
    newTranscript[count] = transcripts[count];//shallow copying of the old transcript to the new one
  }
  
  transcripts = newTranscript;// let go of the old array and then cling onto a new one
  
}


//function takes in a student ID and returns a pointer to a copy of the transcript with this student ID
Transcript* TOT::getTranscriptCopy(string studentID)
{
  Transcript* new_transcript = new Transcript;// create a new transcript
  
  Transcript* specifiedTranscript = lookUp(studentID);
  //find the designated transcript and assign it to a new pointer variable
  
  new_transcript->transcriptIdentity(specifiedTranscript->getStudentID());
  //copy the studentID of the specified transcript into the studentID of the new transcript
  
  copyContents(specifiedTranscript, new_transcript);
  // copy the data pointed to by 
  //specifiedTransript into the memory pointed to by new_transcript
  
  return new_transcript;
}


//return a pointer to the transcript with sID as it's studentID
Transcript* TOT::lookUp(string sID)
{
  int count;//loop control variable
  
  for(count = 0; count < currentCount; count++)//look for the transcript whose studentID is equal to sID
  {
    if(transcripts[count]->getStudentID() == sID)//when you find this return and exit the loop
    {
      return transcripts[count];
    }
  }
  
  cerr<<" Transcript not found"<<endl;// if no match is found return error message
  exit(1);// terminate programme
}

void TOT::copyContents(Transcript* S_t, Transcript* N_t)
{
 int count1;//create loop variable
  
  int count2;//create loop variable
  
  Course* current;
  
  for(count1 = 0; count1 < S_t->getSemesterCount(); count1++)//outer loop co
  {
    N_t->addSemester(S_t->semesterList[count1].getSemesterName(),
				S_t->semesterList[count1].getSemesterYear());
				
    for(count2 = 0; count2 < S_t->semesterList[count1].getnumCourses(); count2++)
    {
      current = S_t->semesterList[count1].getHead();
      
      N_t->semesterList[count1].addCourse(current->courseNumber);
      
      N_t->semesterList[count1].addGrade(current->courseNumber, 
						    current->courseGrade);
      
      current = current->next;
    }
  } 
}