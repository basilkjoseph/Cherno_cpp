#include<iostream>
#include<string>
using namespace std;

class Example
{
public:
	Example()
	{
		cout << "created Entitiy" << endl;
	}
	Example(int x)
	{
		cout << "Entity Created with " << x << endl;
	}
};

class Entity
{
private:
	string m_Name;
	int m_Score;
	Example m_Example;
	//Example() gets executed here, when Entity e0 is seen
public:
	Entity()
		:m_Name("Unknown"), m_Score(0)//,m_Example(Example(8))
		//This is member initializer list.This makes the code much more clean rather than seperately initializing 
		//inside the constructor.
		//Initialize in the order in which they are declared.
	{
		//m_Name = "Unknown";
		m_Example = Example(8);  
		//Also Example(int x) gets executed here when Entity e0 is seen.
		//That is Constructor example will create two objects instead of one
		//Here previously created object m_Example gets overwritten.Delete this and run list.Then only one will be created
	}
	Entity(const string& name)
		:m_Name(name)
	{
		//m_Name = name;
	}
	const string GetName() const
	{
		return m_Name;
	}

};

int main()
{
	Entity e0;
	cout << e0.GetName() << endl;

	Entity e1("Cherno");
	cout << e1.GetName() << endl;

	cin.get();
}