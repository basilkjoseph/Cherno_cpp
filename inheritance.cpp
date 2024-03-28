#include<iostream>
using namespace std;
//A pure virtual function basically allows us to define a function in a base class that does not have an 
//implementation  and then force subclasses to actually implement that function. 
//Here we force the subclass to actually provide its own definition for the function.Interface is a class that 
//only consists of unimplemented methods and acting as a template of sort. Since this interface class doesn't
//actually contain any method implementations, its not actually possible for us to instantiate that class.
//


class Printable
{
//This is just a class, but with a pure virtual function.
//Interfaces are just classes in C++
public:
	virtual string GetClassName() = 0;     //When a function with virtual keyword is set to zero, it becomes 
	                                       //pure virtual function.
};
class Entity :public Printable
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
	string GetClassName() override
	{
		return "Entity";
	}
	virtual string GetName()  //Base function is marked vitual.
	{
		return "Entity";
	}

};

class Player :public Entity//,Printable            //If Player is not inherited from entity.
{
private:
	string m_Name;
public:
	const char* Name;
#if 0
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
	//These lines are same as that in Entity class. So in order to avoid this we use inheritance, where data 
	//from Entity class is accessed and used in Player class.
#endif
	Player(const string& name)
		: m_Name(name)
	{}
#if 0//Above code implies this
	Player(const string& name)
	{
		m_Name = name;
	}
#endif
	string GetName() override   //Mark 'override' to know which function is overridden.
	{
		return m_Name;
	}
	void Printname()
	{
		cout << m_Name << endl;
	}
	string GetClassName() override
	{
		return "Player";
	}

	
};


void PrintName(Entity* entity)   //This function takes in an Entity pointer as parameter. So function GetName()
//declared in Entity class will be executed, and not the GetName() declared in Player class.Here comes the need
//of Virtual Functions.
{
	cout << entity->GetName() << endl;
}

void Print(Printable* obj)
{
	cout << obj->GetClassName() << endl;
}

int main()
{
	//To access members of a structure, use the dot(.)operator.To access members of a structure through a pointer, 
    //use the arrow(->)operator.
	Entity* e = new Entity();   
	//cout << e->GetName() << endl;
	PrintName(e);

	Player* p = new Player("Cherno");
	//cout << p->Getname() << endl;
	PrintName(p);

	Entity* entity = p;    
	//Player* player = e;    //Player is an Entity, but Entity is not a Player.Hence this line does not compile.
	cout << entity->GetName() << endl;

	Print(e);
	Print(p);

	cin.get(); 
}
//Visibility has nothing to do with running of the program or performance.It's just for us to decide who can see
//what.In private, only the base class can access data, and no subclass can.But in protected, base class and
//its subclasses can access the data, and no one else(we can't call it from the main function).