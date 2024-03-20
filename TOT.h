#ifndef TOT_H
#define TOT_H

#include <iostream>
#include <cstdlib>
#include "Transcript.h"

using namespace std;

//initial size of dynamic array
const int INIT_SIZE = 5;

//factor to increaase the size of the array
const int RESIZE_FACTER = 2;

class TOT
{
  public:

     TOT();
     //constructor creates dynamice array of size INIT_SIZE and sets pointers to NULL

     TOT(Transcript* transcriptList, int listSize);
     //constructor takes in a dynamic array of transcripts and initializes the transcript pointers

     Transcript* getTranscriptCopy(string studentID);
     // Returns a pointer to a copy of the student's transcript 

     bool addTranscript(Transcript* t);
     // Function adds a single transcript to the system and returns a bool if it worked

  private:

     Transcript** transcripts;
     // dynamic array of pointers to transcripts
     
     Transcript* lookUp(string sID);
     //Takes in a student ID and returns a pointer to it
     
     Transcript* newTranscript1;
     // helps create a copy of the dynamic array input of the second constructor

     void expand();
     // expands the dynamic array when the list is full

     int currentCount;
     // keeps track of the number of transcripts

     int currentCapacity;
     // keeps track of the size of the array of transcripts

     void copyContents(Transcript* S_t, Transcript* N_t);
     //takes in the pointer to two transcripts and copies the content of one into the other
};

#endif
    
   
      