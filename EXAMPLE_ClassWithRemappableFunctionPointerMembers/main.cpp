//
//  main.cpp
//  EXAMPLE_ClassWithRemappableFunctionPointerMembers
//
//  Created by Forrest Miller on 6/9/18.
//  Copyright © 2018 Forrest Miller. All rights reserved.
//

#include <iostream>
#include "ShiftingClassMemberFunctionWithPointers.h"

int main(int argc, const char * argv[]) {
   
    
    
    std::cout << "\nRunning test for the ShiftingClassMemberFunctionsWithPointers test object...\n";
    
    std::unique_ptr<ShiftingClassMemberFunctionWithPointers> test = std::make_unique<ShiftingClassMemberFunctionWithPointers>();
    
    test->runTest();
    std::cout << "        Turning off safety checking...\n";
    test->disableSafetyChecking();
    test->runTest();
    std::cout << "        Re-enabling safety checking...\n";
    test->enableSafetyChecking();
    test->runTest();
    
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\n\n\n\nNow to test 2 instances of the class at once!\n";
    std::unique_ptr<ShiftingClassMemberFunctionWithPointers> test2 = std::make_unique<ShiftingClassMemberFunctionWithPointers>();
    
    std::cout << "\n\nTest 1 -> runTest()";
    test->runTest();
    std::cout << "\n\nTest 2 -> runTest()";
    test2->runTest();
    
    std::cout << "\n\n        Turning off safety check for test1...";
    test->disableSafetyChecking();
std::cout << "\n\nTest 2 -> runTest()";
    test2->runTest();
    
    return EXIT_SUCCESS;
}
