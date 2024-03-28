//Memory inside a computer is one big line; a linear one dimensional line.It is just like a long straight 
//road with houses along one(only one) of its sides.Each house represents a Byte
//A pointer is an integer, a number which stores a memory address. Types are completely meaningless. A pointer
//for all types is just that integer that holds the memory address. Types are used to mention that the data at 
//that adress is presumed to be the type that we give it.Type does not change what a pointer is; a pointer is 
//just a memory address, an integer


#include<iostream>
using namespace std;
#define LOG(x) cout << x << endl;
void increment(int value)
{
	value++;
	cout << value << endl;
}

void increment(int* value)
{
	(*value)++;   //dereference first and then increment.
	               //*value ++  will incrememnt and then dereference.
	cout << *value << endl;
	cout << value << endl;
}

void increments(int &value)
{
	value++;
	LOG(value)
}

int main()
{
	void* ptr1 = 0; 
	/*instead of 0(0x0 address, which is reserved and never used by the system.This address will generate 
	segmentation fault when accessed), we can also use "NULL" or "nullptr".	
    By void we mean that we do not care what type the actual data is, because we just need to really 
    hold an address.
	0 is not a valid memory address.This means that this pointer is not valid, and this state is perfectly
	acceptable for a pointer
	
	So nullptr is defined to be pointing to nowhere. It's never going to be used by the system, and it will 
	always generate a very specific kind of error called a segmentation fault, if we ever access the nullptrs.
	And you can never delete zero. So it's an address that can't be deleted. It's an address that points to 
	nowhere. And it's an address that's going to generate an error every time we use it.
	*/

	int var1 = 8;
	void* ptr2 = &var1;   //0x000000358272f444
	int* ptr3 = &var1;    //0x000000358272f444
	                      //Both the pointers store the same integer irrespective of the type
	double* ptr4 = (double*) & var1;    //0x000000358272f444
	                                    //Again the same memory address
	//The need to mention type comes when dereferancing the pointer
	//* operator is used to dereferance a pointer

	// *ptr1 = 10;  //Compiler gives an error since type of ptr1 is not known.
	*ptr3 = 10;

	char* buffer = new char[8];   //0x000002e62c001d60
	memset(buffer, 0, 8);   //memory set to 0(all bits will be zero)
	char** ptr = &buffer;   //double pointer, pointer refering to a pointer
	                        //one pointer stores the memory address of the next pointer
	const char* test ="Hello World";
	
	int x = 12, y = 13;
	int* refr = &x;
	*refr = 15;
	refr = &y;
	*refr = 16;
	
	cout << "Pointers" << endl;
	LOG(x)
	LOG(y)
	cout << "===========" << endl;


	int a = 5;
	int b = 8;
	int& ref = a;   //once a reference is created, it cannot be changed.
	ref = b;        //This will not change the reference from a to b, but will change the value at a to that at b.
	                //ie. a will become 8 (ref is actually a, so same as writing a=b;)
	                //also unlike other data types we can't just initialise a reference and assign it a value at 
	                //some other point. Initialisation and assigning must be done at the same point.
	//int& ref;     //This is not possible
	cout << "Reference" << endl;
	LOG(ref)
	cout << "===========" << endl;

	cout << "call by value" << endl;
	LOG(var1)
	increment(var1);    //value=var1; This is what happens in call by value.Data in var1 gets copied to value.
	                    //int value = 10; (call by value does the exact same thing)
	LOG(var1)
	cout << "===========" << endl;

	cout << "Using Pointers" << endl;
	LOG(var1)
	increment(&var1);
	LOG(var1)
	cout << "===========" << endl;

	cout << "Call by Reference" << endl;
	LOG(var1)
	increments(var1);
	LOG(var1)
	cout << "===========" << endl;



    cin.get();
}