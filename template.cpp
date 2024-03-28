
#include<iostream>
using namespace std;


//Compiler writes code for you based on a set of rules. 

#if 0
void Print(int value)
{
	cout << value << endl;
}
void Print(string value)
{
	cout << value << endl;
}
void Print(float value)
{
	cout << value << endl;
}
#endif
//In order to avoid these three functions,we use a template.

template <typename T>
//template <class T>    Exactly same as before,but typename is much more accurate term.(literally)
void Print(T value)
{
    cout << value << endl;
}
//This print function does not really exist.This print function is just a template which actually get 
//created when we call the print function, with the given template arguement.So if we make a syntax 
//error inside a template and not call it, the code compiles perfectly.
//When we call the print function with an int arguement, the blank space gets filled(T).It would be 
//same as a function that has been created with int int place of T.Now when we call print with a different 
//arguement like float, another version of this tamplate gets created and instead of T float will be used.
//So all this is a template specifying how to create methods and these methods or functions can be created 
//at the time of compile based on your usage of them.

template<typename T,int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const
	{
		return N;
	}
};


int main()
{
	Print<int>(5);
	/*
	Print(5);
	Print("Basil");
	Print(5.5f);
	Here we are implicitly specifying the type.Hence these lines also run perfect
	*/
	
	Array<int,5> array;  //This is how stadard array class behaves. 
	cout << array.GetSize() << endl;

	cin.get();
}