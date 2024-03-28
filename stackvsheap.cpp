#include<iostream>
#include<string>

using namespace std;

int main()
{
	int value = 5;

	int array[5];
	//Stack allocation

	int* hvalue = new int;
	*hvalue = 5;

	int* harray = new int[5];

	//Heap allocation

	delete hvalue;
	delete[] harray; 

	cin.get();
}