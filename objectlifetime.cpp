#include<iostream>
#include<string>

using namespace std;

int* CreateArray()
{
	int array[50];
	//int* array=new int[50];
	//Using this we can avoid the below mentioned failure.
	return array;
}

class Entity
{
private:
	string m_Name;
public:
	Entity()
	{
		cout << "Entity Created" << endl;
	}
	~Entity()
	{
		cout << "Entity Destroyed" << endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		:m_Ptr(ptr)
	{}
	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	int* a = CreateArray();
	//This code would fail as the stack memory gets cleared as soon as it gats out of the scope of the function.


	{
		Entity e = Entity();
	}

	{
		ScopedPtr e = ScopedPtr(new Entity());
		//scopedPtr e = new Entity();    same as above
		//Here the Entity ptr automatically gets deleted without the delete operator on encountering destructor.
		//e is stack allocated, so its lifetime ends in this scope.So e calls the destructor which inturn calls
		//the delete keyword.ie.Memory got freed eventhough it was heap allocated al the end of a scope
		Entity* e = new Entity();
	}


	cin.get();

}