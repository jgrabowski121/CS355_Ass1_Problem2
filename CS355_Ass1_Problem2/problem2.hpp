//
//  problem2.hpp
//  CS355_Ass1_Problem2
//
//  Created by Justin Grabowski on 11/16/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//

#ifndef problem2_hpp
#define problem2_hpp
#include <stdio.h>
#include <iostream>
#include "timeTest.h"



class Problem2 {
    //Function declarations
    
    /*
     * Declares two static two-dimetional arrays
     *  of size (100 X 100)
     */
    void function1();
    
    /*
     * Create two two-dimetional arrays
     *  of size (100 X 100) on the stack
     */
    void function2();
    
    /*
     * Create two two-dimetional arrays
     *  of size (100 X 100) on the heap and
     *  deallocates them before exiting
     */
    void function3();
    
    /*
     * Creates two two-dimentional arrays of
     *  size (100 X 100) on the heap and does not
     *  deallocate them
     */
    void function4();
    
public:
    
    /*
     * This function calls function1(), function2(),
     *  and function3() to test the times for array allocation
     *
     */
    void runTest();
};

#endif /* problem2_hpp */
