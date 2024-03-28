#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int a = 5;
	auto b = a;
	//compiler automatically understands it is int b.
	auto c = 5;


	vector<string>Strings;
	Strings.push_back("Apple");
	Strings.push_back("Orange");

	for (vector<string>::iterator it = Strings.begin(); it != Strings.end(); it++)
	{
		cout << *it << endl;
	}

	for (auto it = Strings.begin(); it != Strings.end(); it++)
	{
		cout << *it << endl;
	}
	//Here auto simplifies the huge type.
	//Auto is useful in simplifying long type
	
	//.end() points to /0 location.
	//.begin() and .end() returns iterator, .size() returns integer
	cin.get();

}