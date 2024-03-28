/*
In C++, the keyword this refers to a pointer that points to the current object instance. It is a 
reserved keyword and is a built-in pointer that is automatically created for each object instance of a class.
When a member function of a class is called for a specific object, the this pointer is automatically set to 
point to the object that the function is called on. This allows the member function to access the object's 
member variables and member functions.
*/


#include<iostream>
using namespace std;

void PrintEntity(Entity* e);
class Entity 
{
public:
	int x, y;
	Entity(int x, int y)
	//	:x(x), y(y)    This is fine,but if we initialise inside the body, we face a problem since they 
	//have same name.Here comes the use of this.

	{
		//Entity* const e = this;   This is how 'this' works
		//We can write const e also.But it is anyway implied without specifying.
		//By using const we mean that we can't reassign this
		//this = nullptr;     this cannot be done.
		this->x = x;       //instead of x=x;
		this->y = y; 
		PrintEntity(this);
		//I want to pass in the current instance of this entity class into this function.
		//That is where 'this' comes in.
	}
	void printAddress() 
	{
        std::cout << "The address of this object is: " << this << std::endl;
    }
	//In this class, the member function printAddress() is defined to print the address of the current object 
	//instance. The this pointer is used to access the address of the object:
	int Getx() const
	{
		const Entity* e = this;
		//This is the format of 'this' in a const function.
		//e->x = 5; //or else this would have been possible.But since the function is const, this should not happen.
		return x;
	}

};
void PrintEntity(Entity* e)
{
	//print
}
int main()
{ 
	int a,b;
	Entity obj1(a,b);
	Entity obj2(a,b);
    
   obj1.printAddress(); // Prints the address of obj1
   obj2.printAddress(); // Prints the address of obj2
   /*
   When printAddress() is called for obj1, the this pointer points to the memory location of obj1, and when it is 
   called for obj2, the this pointer points to the memory location of obj2.In summary, the this pointer is a built-in
   pointer in C++ that allows member functions to access the current object instance's member variables and member functions.
   */
} 