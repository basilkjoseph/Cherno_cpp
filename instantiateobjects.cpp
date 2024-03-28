#include<iostream>
#include<string>
using namespace std;


class Entity
{
private:
	string m_Name;
public:
	Entity()
		:m_Name("Unknown") {}
	Entity(const string& name)
		:m_Name(name){}
	const string& GetName() const
	{
		return m_Name;
	}
};
  

int main()
{
	Entity* e;
	{
		//Entity entity("Cherno");
		Entity entity = Entity("Cherno");   //same as above.If you can create an object like this, do create an 
		                                    //object like this,beacause this is the fastest way in c++ to instantiate.
		e = &entity;
		cout << entity.GetName() << endl;
	}   //The problem here is that these objects only have lifetime inside a stack frame(scope--curly bracket).
		//That is inside the smallest curly bracket(In this case here).And gets destroyed as soon as the control 
		// comes out of the scope (any set of{}) just like local variables in a function.To avoid this and extend 
		//the lifetime we define objects in heap. 
		//Without heap, entitiy gets destroyed over here.
	Entity* e1;
	{
		Entity* entity1 = new Entity("Cherno");
		//In heap allocation, type is no longer entity, but entity pointer.
		//new Entity returns the location on the heap where this entity is actually allocated.
		e1 = entity1;
		cout << entity1->GetName() << endl;
		//cout << (*entity1).GetName() << endl;   same as above
	}
	delete e1;
	Entity* entity2 = new Entity("Basil");
	cout << entity2->GetName() << endl;
	delete entity2;
	//We have to manually free memory in heap allocation.So unlike stack, we have the memory retained upto our 
	//desired line.
	cin.get();
}