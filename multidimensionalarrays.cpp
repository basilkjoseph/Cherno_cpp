//A 2D array is an array of arrays; ans so on for multidimensional.if we think about one of our kind of 
//strategies for dealing with arrays, it is essentially by using a pointer.So we have a pointer to the 
//beginning of the array as it appears in our memory. That's how we kind dealwith an array.if you picture that,
//and then you picture an array of those pointers what you kind of end up with, is we have a buffer in my
//memory which contains consecutive kind of pointers, and each one of those pointers points to an array 
//some way in my memory.


#include<iostream>

using namespace std;

int main()
{
#if 0
	int* array = new int[5];
	int** a2d = new int* [5];
	//This is basically allocating memory.  

	//If I want to have a two dimensional array what I'm going to do is have a pointer of pointers because
	//what I'm actually storing here is going to be a buffer of pointer objects, so this is a pointer to 
	//a collection of int pointers.


	a2d[0] = nullptr;
	//this is valid cause a2d is an array of pointers
	array[0] = nullptr;
	//this is nmot valid since array is a collection of intergers
#endif

	int** a2d = new int* [5];
	for (int i = 0; i < 5; i++)
		a2d[i] = new int[5];

	a2d[0][0] = 0;

	//Deleting array; we have to go all the way in reverse.

	for (int i = 0; i < 5; i++)
		delete[] a2d[i];

	delete[] a2d;

	//When we deal with multidimensional arrays, we reult in memory fragmentaion.What we've actually done here is we've 
	//created five separate buffers of five integers and they're gonna be allocated at completely random places
	//in memory, they might be close together, they might not be, nothing guarantees they're gonna be close
	//together and that's an issue, because if we have to iterate through and access those 25 integers, every time 
	//we iterate through five integers we have to go to the next row of our array or our next dimension; and so
	//we have to jump to another location in memory to read and access that data.That results probably in a cache
	//miss which means that we're wasting time fetching that from next location.So it's actually going to be slower,
	//a lot slower, to iterate through these 25 integers.If I had just allocated a single dimensional
	//array of 25 integers in a row, because that memory is going to be all in a row, it would be way faster.

	int* array = new int[5 * 5];
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			array[y + ((x-1) * 5)] = 2;
		}
    } 
	//This code is a lot fatser compared to the previous one.So a single dimensional arra is preffered over 
	//multidimensional.


#if 0 //3D allocation 
	int*** a3d = new int** [5];
	for (int i = 0; i < 5; i++)
	{
		a3d[i] = new int* [5];
		for (int j = 0; j < 0; j++)
		{
			int** ptr = a3d[i];
			ptr[j] = new int[5];
			//a3d[i][j]=new imt[5];    	//same as above	
		}
	}
	a3d[0][0][0] = 0;
	//Accessing thr elements
#endif



	cin.get();
}