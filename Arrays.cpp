#include<iostream>
using namespace std;


int main()
{
	int example[5];
	//arrays are basically similar to pointers.
	int* ptr = example;
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}
	example[2] = 5;
	//This code can be written in many ways as follows
	*(ptr + 2) = 6;
	//Here since type is int, +2 implies 2*4(int) bytes.
	*(int*)((char*)ptr + 8) = 7;
	//Here the pointer is made char then converted back to int and then dereferenced.Hence 8*1(char) will be 
	//added.

	int* another = new int[5];
	//This is array allocation in heap, the bove one being in stack.
	for (int i = 0; i < 5; i++)
	{
		another[i] = 3;
	}
	delete[] another;

	cin.get();  
}