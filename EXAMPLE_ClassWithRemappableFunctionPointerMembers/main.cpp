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
   
    std::cout << "\nRunning the ShiftingClassFunctionDefinitionWithMemberPointerFunctionsPointers...\n";
    
    std::unique_ptr<ShiftingClassMemberFunctionWithPointers> test = std::make_unique<ShiftingClassMemberFunctionWithPointers>();
    
    test->runTest();
    test->disableSafetyChecking();
    test->runTest();
    test->enableSafetyChecking();
    test->runTest();
    
    
    
    return EXIT_SUCCESS;
}
