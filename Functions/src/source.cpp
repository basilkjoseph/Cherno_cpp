#include<iostream>
using namespace std;
#ifndef Logh           //Here #ifndef checks if something named Logh is defined or not; if not, the next block of codes will be executed.
#define Logh
int multiply(int a, int b)
{
    return a * b;
}
#endif

#ifndef Logh           //This time, Logh is already defined. Hence, this time, the following block of codes will not be executed.   
#define Logh         
int multiply(int a, int b)
{
    return a * b;
}
#endif                 //#ifndef is actually used in header files to avoid repetition. But now-a-days we use '#pragma once' for the same  


void multiplyandlog(int a, int b)
{
    int result = multiply(a, b);
    cout << result << endl;
}

#include "log.h"

int main()
{
    multiplyandlog(3, 4);
    multiplyandlog(5, 6);
    multiplyandlog(7, 8);

    initlog();

    const char* ptr = nullptr;
    if (ptr)
    {
        log("Hello World");
    }
    else
        log("ptr is null");

    cin.get();
    //Main function is only function which automatically returns 0 without even specifying//
}