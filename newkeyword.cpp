//The main purpose of new is to allocate memory, on the heap specifically.You write new and then you write your datatype, whether that be a 
//class or a primitive type, or an array.Based on what you have written it determines the necessary size of the allocation in bytes.If i write 
//int, it requests and allocates 4 bytes of memory.Once we find a continuous block of 4 bytes, it returns a pointer to that memory address
//with which we can use the data.



#include<iostream>
#include<string>
using namespace std;


class Entity
{
private:
	string m_Name;
public:
	Entity()
		:m_Name("Unknown")
	{}
	Entity(const string& name)
		:m_Name(name)
	{}
	const string& Getname() const
	{
		return m_Name;
	}
};

int main()
{
	int a = 2;
	int* b = new int; //single 4 byte integer aloocated on the heap and b is storing its memory address
	//int* b = new int[50];    200 bytes
	//For allocating arrays.

	Entity* e = new Entity[50]; 
	//Array of 50 Entities. Memory occupied = 50*sizeof(string).

	Entity* e1 = new Entity();
	//New not only allocates memory but also calls the constructor.New is just an operator like +,-.

	delete b; 
	delete[] e;
	delete e1;
    /*
	delete also calls the destructor.
	We'd like to clarify some common misunderstandings. Remember that after the line "delete b;" the 
	pointer b still stores the address of the deleted variable(memory in heap), which is no longer valid 
	to dereference and is therefore dangerous. The pointer won't be automatically set to nullptr. Then,
	you should manually set b to nullptr if you want to better protect against coding mistakes:

    delete b;

    b = nullptr;

    Also, this is a good practice in general whenever you use "delete" on a pointer, but in this 
	particular example, the function that is about to return is "main". When main returns, the program 
	exits and the operating system will usually release all the allocated memory back to the system. 
	This isn't an excuse to be sloppy, though; as you will soon see, many class objects have their "destructor" 
	functions called silently when the program exits, and mistakes can trigger crashes even during that process.
	*/
}