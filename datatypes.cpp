#include<iostream>
using namespace std;
int main()
{
    int variable1 = 8;            // int has a memory of 4 bytes; 1 byte=8 bits; one bit can store either '0' or '1'//
                                  // Also int is signed; so 4 bytes= 32 bits; one byte reserved for sign; rest 2^31 possible combinations//
    unsigned int variable2 = 10;  // here the variable is unsigned; hence we get a total of 2^32 combinations//  

                                //CHARACHTERS//
                                //char=1 byte 

                                //INTEGERS//
                                //short=2 bytes
                                //int=4 bytes
                                //long, usually 4; depending on the compiler         
                                //long int=8 bytes; (modifications to basic datatypes)

                                //DECIMAL//
                                //float=4 bytes
                                //double=8 bytes

                                //BOOL//
                                //bool=1 byte

                                         //All these can be modified using unsigned//
    short variable3 = 12;
    float variable4 = 5.2;      //Although declared float, compiler interprets it as double. Hence to 
                                //distinguish between the two, we add an 'f' or 'F'                  
    float variable5 = 5.2f;
    double variable6 = 7.977358;
    //Size of each datatype can be accessed using sizeof() operator
    cout << "sizeof(bool)= " << sizeof(bool) << "\n";
    cout << "sizeof(int)= " << sizeof(int) << "\n";
    cout << "sizeof(char)= " << sizeof(char) << "\n";
    cout << "sizeof(float)= " << sizeof(float) << "\n";
    cin.get();
    return 0;
}