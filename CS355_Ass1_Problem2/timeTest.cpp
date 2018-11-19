//
// Justin Grabowski
// CS355
// Fall 2018
// November 10th 2018
// Instructor Ganchev G.
// main.cpp
// CS355Ass1_Problem2
// Language C++
//
// Purpose: This file creates the time class used for testing
// time from startClock to endClock

#include <stdio.h>
#include "timeTest.h"

//Constructor
executionTimeTester::executionTimeTester(){}

// Set the startClock to the current time
void executionTimeTester::setStartClock()
{
   startClock = clock();
}

// Set the endClock to the current time
void executionTimeTester::setEndClock()
{
   endClock = clock();
}

// Get the time deffernce between startClock and endClock
// in seonds
double executionTimeTester::getTimeDiferenceSeconds()
{
   return ((float) endClock - startClock ) / CLOCKS_PER_SEC;
}
