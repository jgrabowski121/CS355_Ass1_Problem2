//
//  problem2.cpp
//  CS355_Ass1_Problem2
//
//  Created by Justin Grabowski on 11/16/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//

#include "problem2.hpp"
#include "timeTest.h"
#include <stdlib.h>



void Problem2::function1()
{
    static int arrayOne[100][100];
    static int arrayTwo[100][100];
    
    // initialize random seed
    srand(time(NULL));
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; i<100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
}

void Problem2::function2(){
    int arrayOne[100][100];
    int arrayTwo[100][100];
    
}

void Problem2::function3(){
    char arraySize = 100;
    int** arrayOne = new int*[arraySize];
    int** arrayTwo = new int*[arraySize];
    
    delete [] arrayOne;
    delete [] arrayTwo;
    
}

void Problem2::function4(){
    
}

void Problem2::runTest()
{
    //Create executionTimeTester object
    executionTimeTester timeTest;
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= 100000; i++)
    {
        function1();
    }
    timeTest.setEndClock();
    
    std::cout << "Time was " << timeTest.getTimeDiferenceSeconds() << std::endl;
    
    //---------------
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= 100000; i++)
    {
        function2();
    }
    timeTest.setEndClock();
    
    std::cout << "Time was " << timeTest.getTimeDiferenceSeconds() << std::endl;
    
    //----------------
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= 100000; i++)
    {
        function3();
    }
    timeTest.setEndClock();
    
    std::cout << "Time was " << timeTest.getTimeDiferenceSeconds() << std::endl;
    
    //-----------------
}
