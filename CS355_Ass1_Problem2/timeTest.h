// CS355
// Fall 2018
// November 10th 2018
// Instructor Ganchev G.
// main.cpp
// CS355Ass1_Problem2
// Language C++
//
// Purpose: This file creates declarations for the time class
// used for testing time
#include <ctime>

#ifndef timeTest_h
#define timeTest_h

class executionTimeTester {
   clock_t startClock;
   clock_t endClock;
   
public:
   
   executionTimeTester();
   
   //Set the startTime field to the current time
   void setStartClock();
   
   //Set the endTime field to the current time
   void setEndClock();
   
   /*
   * Return the differnece between startTime and endTime
   * Must call StartTime before endTime to get a valid result
   */
   double getTimeDiferenceSeconds();
};



#endif /* timeTest_h */
