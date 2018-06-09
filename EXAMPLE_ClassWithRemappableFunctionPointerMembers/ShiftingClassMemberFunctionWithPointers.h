//
//  Created by Forrest Miller on 6/9/18.
//

///SEE: https://stackoverflow.com/questions/47904088/called-object-type-void-bint-is-not-a-function-or-function-pointer?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
///This explanation helped it all make sense

#ifndef ShiftingClassMemberFunctionWithPointers_h
#define ShiftingClassMemberFunctionWithPointers_h

#include <iostream>

class ShiftingClassMemberFunctionWithPointers {
private: //Fields
    bool useSafetyChecking;
    
    void testFunction1() {
        std::cout << "\nThis is test function 1 that was called! useSafetyChecking = " << useSafetyChecking << std::endl;
    }
    
    void testFunction2() {
        std::cout << "\nThis is test function 2 that was called! useSafetyChecking = " << useSafetyChecking << std::endl;
    }
    
    void testFunction3() {
        std::cout << "\nThis is test function 3 that was called! useSafetyChecking = " << useSafetyChecking << std::endl;
    }
    
    void testFunction4() {
        std::cout << "\nThis is test function 4 that was called! useSafetyChecking = " << useSafetyChecking << std::endl;
    }
    
public:
    void (ShiftingClassMemberFunctionWithPointers::*remappableFunction1)();
    void (ShiftingClassMemberFunctionWithPointers::*remappableFunction2)();
    
    ShiftingClassMemberFunctionWithPointers() {
        useSafetyChecking = true;
        remappableFunction1 = &ShiftingClassMemberFunctionWithPointers::testFunction1;
        remappableFunction2 = &ShiftingClassMemberFunctionWithPointers::testFunction2;
    }
    
    
    void runTest() {
        std::cout << "\nRunning test!\nuseSafetyCheckings is set to " << useSafetyChecking << "\n";
        std::cout << "Calling remappableFunction1()...";
        (this->*remappableFunction1)();
        std::cout << "Calling remappableFunction2()...";
        (this->*remappableFunction2)();
    }
    
    void disableSafetyChecking() {
        if (useSafetyChecking) {
            useSafetyChecking = false;
            //Swap function pointers
            remappableFunction1 = &ShiftingClassMemberFunctionWithPointers::testFunction3;
            remappableFunction2 = &ShiftingClassMemberFunctionWithPointers::testFunction4;
        }
    }
    
    void enableSafetyChecking() {
        if (!useSafetyChecking) {
            useSafetyChecking = true;
            //Swap function pointers
            remappableFunction1 = &ShiftingClassMemberFunctionWithPointers::testFunction1;
            remappableFunction2 = &ShiftingClassMemberFunctionWithPointers::testFunction2;
        }
    }
    
};

#endif // ShiftingClassMemberFunctionWithPointers_h
