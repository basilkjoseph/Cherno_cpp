#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	const char* name = "Cherno";
	//declared const since we don't want the value to be changing.Strings are inextensilble, they can't be made
	//bigger;because this is a fixed allocated block of memory.For a bigger string, brand new allocation has to be 
	//made and old string has to be deleted.
	//name[2] = 'a';   //this is not possible for const
	//And if const is not added, the condition is generally banned. Some compilers give the correct output by 
	//updating the value but it is totally compiler dependent.
	//So if we want to modify values, it has to be defined as an array and not a pointer.
	const void* ptr = "2";
	//A pointer can be assigned value like this only for char and void.
	char name2[6] = { 'C','h','e','r','n','o' };
	//Here there is no null character at the end. So a lot more characters gets printed.To avoid this,
	char name3[7] = { 'C','h','e','r','n','o',0 };//End character can be manually set to zero.
	//But in name, automatically a null character gets added at the end, since it is a char pointer.
	cout << name2 << endl;
	cout << name3 << endl;

	string name4 = "Cherno"; 
	//exactly same as const char* name = "Cherno"; With headerfile string const char* changed to string.

	name4 += "Hello"; //string addition.
	name4 = string("cherno") + "Hello"; //method 2
	//using namespace std::string_literals;
	u32string Name0 = U"cherno"s + U"hello";
	//Here s is instead of constructor string in the previous case.string_literals library 
	//enables us to do so.

	const char* ex = "line1\n";
	"line2\n";
	"line3\n";
	"line4\n";
	//This is how we write paragraphs or quotes generally.
	const char* example = R"(line1
    line2
    line3
    line4)";
	//A more convenient method
	
	
	
	bool contains = name4.find("no") != string::npos; //To find an element  




	"Cherno";  //const char array of size[7]
	//"Cherno\0"  This is how it actually looks like in memory. We can manually define it like this as well.
	const char Name[8] = "Che\0rno";
	cout << strlen(Name) << endl;  //Outputs 3 since it reads upto first null character

	//We have taken a pointer to the memory location of a string literal and string literal are stored in 
	//the read only section of the memory.


	const wchar_t* Name2 = L"Cherno";   //2 bytes
	const char16_t* Name3 = u"Cherno";  //2 bytes
	const char32_t* Name4 = U"Cherno";  //4 bytes
	const char* Name5 = u8"Cherno";     //1 byte  same as without u8.

	cin.get();	return 0;
}