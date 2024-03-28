#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;

struct Vertex
{
	float x, y, z;
};

ostream& operator<<(ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

void Function(const vector<Vertex>& parameter)
{
	
}
//When passing these vectors into functions or classes,pass them by reference.If you are not going to modify them,
//then by const reference.
void function(array<int, 5>& parameter)
{
	
}
 
int main()
{
	vector<int>A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	cout << A.size() << endl;


	//A.erase(2);       //Invalid.Instead we use
	A.erase(A.begin() + 1);

	cout << A.size() << endl;

	for (int i = 0; i < A.size(); i++)
		cout << A[i] << endl;

	
	A.clear();    //Sets back array size to zero.
	cout << A.size() << endl;

	//Vertex vertices[5];      
	//Vertex* vertices = new Vertex[5];
	//Static allocation.Here both in stack and heap we are tied to the size.

	vector<Vertex>vertices;
	//vector<Vertex*>vertices;     
	//It is technically more optimal to store Vertex objects than Vertex 
	//pointers.Because objects will be inline, they will be continuous.Its not fragmented,its all just in a 
	//row.The only problem is that when it comes to resize the vector,it need to copy all that data. And if 
	//you happen to have a vector of strings and you are going to be resizing very often, it does need to 
	//reallocate and recopy which could potentially be a slow process.Moving instead of copying largely solves 
	//this particular issue, but there is still some copying which is not ideal.Whereas with pointers the memory 
	//actually stays intact beacause you are just holding pointers to that memory.So the actual memory stays 
	//intact and the data is stored in various locations. 


	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });
	
	Function(vertices);

	for (int i = 0; i < vertices.size(); i++)
		cout << vertices[i] << endl;


	for (Vertex v : vertices)   
		//Here vertices will get copied.To avoid that we use reference (Vertex& v)
		cout << v << endl;



	array<int, 5>data;
	//Syntax; use this instead of the old C style array.

	data[0] = 1;
	data[4] = 5;

	data.size();

	//size() operarion can be performed here since this is an array class.
	//we hace many other operations like begin, end and sort; just because it is a class.


	cin.get();
}