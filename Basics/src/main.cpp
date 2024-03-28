#include<iostream>
using namespace std;
#include "log.h"
void logr(const char* message);
int main()
{
    logr("Hello World");
    cin.get();                      //The control pauses when it encounters a cin.get();//
                                    //It waits for the user to press enter to proceed further//
    return 0;
} 

//Build is the complete process of converting source code into an executable, for C++ compilation is the 
//conversion of source code into object code. In a build the C++ code will be compiled and then you will 
//need other stages including a link phase to construct an executable.//