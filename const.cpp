//DO NOT COMPILE
#include<iostream>
using namespace std;

class Entity
{
private:
	int m_X, m_Y;
	int* m_x, * m_y;
	mutable int var;
public:
	//Here const comes after a method name.This only works in a class
	int GetX() const
		//This implies that this method is not gonna modify any class member variables.The method becomes read o
		//only
	{
		var = 2; //If marked mutable, value can be modified even inside a const method.
		m_X = 2; //this can't be done since we have a const 
		return m_X; 
	}
	const int* const Getx() const
		//1.Return type is an integer pointer that cant be modified
		//2.Contents of the pointer cannot be modified
		//3.Method is constant type
	{
		return m_x;
	}
	void PrintEntity(const Entity& e)
		//Here with const nothing abt e can be modified
		//unlike pointers where value at or the actual pointer can be modified depending on position of const,
		//Here nothing abt e can be changed since it is a reference.
	{
		cout << e.GetX() << endl;
	}
	//Now if GetX fn is not made const, it does not guarentee that entity is gonna be constant.Indirectly
	//object variables of entity can be modified.We are not modifying the entity directly but we are calling 
	//a method that does modify the entity.This is not allowed as entity is marked as const.Hence we also make
	//GetX const to make sure that nothing is modified.
	//Hence sometimes we see two copies of the same function, one with const and the other with no const, for 
	//different purposes.
};
int main()
{
	Entity e;


	const int MAX_AGE = 90;

	const int* a = new int;  //value at a is made constant
	//int const* a = new int;    same as above
	//Hence pointer a can be dereferenced and modified but not value at a
    *a = 2;
	a = (int*)MAX_AGE;
	cout << *a << endl;
	

	int* const b = new int;  //pointer b is made constant
	//Hence pointer b can't be modified but can be dereferenced and value at b can be modified
	*b = 3;
	b = (int*)&MAX_AGE;
	cout << *b << endl;


	//MUTABLE
	int x = 8;
	auto f = [=]() mutable
	//inside[]----& for call by reference,= for call by value
	{
		x++;
		cout << x << endl;
	};

	f();

	cin.get();
}
//DO NOT COMPILE