//
//  main.cpp
//  CS355Ass1
//
//  Created by Justin Grabowski on 11/14/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//

#include <iostream>
#include "timeTest.h"
#include <exception>

#include <chrono>

//Function declarations

/*
 * Declares two static two-dimetional arrays
 *  of size (100 X 100)
 * Initializes both arrays with random values
 *  Then multiplys one array by itself and stores
 *  the result in the second array
 * Must seed srand in caller before calling
*/
void function1();

/*
 * Create two two-dimetional arrays
 *  of size (100 X 100) on the stack
 * Initializes both arrays with random values
 *  Then multiplys one array by itself and stores
 *  the result in the second array
 * Must seed srand in caller before calling
*/
void function2();

/*
 * Create two two-dimetional arrays
 *  of size (100 X 100) on the heap and
 *  deallocates them before exiting
 * Initializes both arrays with random values
 *  Then multiplys one array by itself and stores
 *  the result in the second array
 * Must seed srand in caller before calling
*/
void function3();

/*
 * Creates two two-dimentional arrays of
 *  size (100 X 100) on the heap and does not
 *  deallocate them
 * Initializes both arrays with random values
 *  Then multiplys one array by itself and stores
 *  the result in the second array
 * Must seed srand in caller before calling
*/
void function4();

int main(int argc, const char * argv[]) {
    //Create executionTimeTester object
    executionTimeTester timeTest;
    unsigned ITERATION = 1000;
    
    // initialize random seed
    srand(time(NULL)); // implicit conversion is okay
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= ITERATION; i++)
    {
        function1();
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function1 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)
    << " ms\n";
    
    std::cout << "Time to execute function1 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //---------------
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= ITERATION; i++)
    {
        function2();
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function2 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)<< " ms\n";
    
    std::cout << "Time to execute function2 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //----------------
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= ITERATION; i++)
    {
        function3();
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function3 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)
    << " ms\n";
    
    std::cout << "Time to execute function3 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //-----------------
    /*
     static unsigned long long iterations = 0;
     while(true)
     {
     try
     {
     function4();
     iterations++;
     if((iterations % 100000) == 0)
     {
     std::cout << "Iterations : " << iterations << std::endl;
     }
     }
     catch (std::bad_alloc&)
     {
     std::cout << "Crashed after : " << iterations << std::endl;
     break;
     }
     
     }
     */
    return 0;
}


void function1()
{
    static int arrayOne[100][100];
    static int arrayTwo[100][100];
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
            for(size_t k = 0; k < 100; ++k)
            {
                arrayTwo[i][j] = arrayOne[i][k] * arrayOne[k][j];
            }
    
}

void function2()
{
    int arrayOne[100][100];
    int arrayTwo[100][100];
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
            for(size_t k = 0; k < 100; ++k)
            {
                arrayTwo[i][j] = arrayOne[i][k] * arrayOne[k][j];
            }
    
}

void function3()
{
    const char arraySize = 100;
    int** arrayOne = new int*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        arrayOne[i] = new int[arraySize];
    
    int** arrayTwo = new int*[arraySize];
    for(int i = 0; i < arraySize; ++i)
        arrayTwo[i] = new int[arraySize];
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
            for(size_t k = 0; k < 100; ++k)
            {
                arrayTwo[i][j] = arrayOne[i][k] * arrayOne[k][j];
            }
    
    delete [] arrayOne;
    delete [] arrayTwo;
}


// Not relevant for problem 2
/*
void function4()
{
    char arraySize = 100;
    int** arrayOne = new int*[arraySize];
    int** arrayTwo = new int*[arraySize];
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
}
*/
