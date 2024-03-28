//When you create a smart pointer it will call new and allocate memory and then based on which smart pointer 
//you use that memory will at some point be automatically be freed. Unique pointers are scopped pointers, ie.
//when they go out of scope, they call delete and get destroyed.



#include<iostream>
#include<string>
#include<memory>
//Include memory in order to use smart pointers.

using namespace std;

class Entity
{
public:
	Entity()
	{
		cout << "Created Entity" << endl;
	}
	~Entity()
	{
		cout << "Destroyed Entity" << endl;
	}
	void Print()
	{

	}
};


int main()
{
	{
		unique_ptr<Entity>entity(new Entity());
		//unique_ptr<Entity>entity = make_unique<Entity>();       //safer way to declare a unique ptr.(Exception safety)
		//As the name suggests it is unique,ie.it cannot be copied.
		//unique_ptr<Entity>e0 = entity;  //Eror, no copying allowed
		entity->Print();
	}

//If we want sharing, that's where shared ptr comes in.It uses reference counting.Reference counting is where you keep 
//track of how many references you have to your ptr.Ans as soon as that reference count reaches zero, thats where it gets deleted.

	{
		shared_ptr<Entity>e0;
		{
			shared_ptr<Entity>sharedentity = make_shared<Entity>();
			//shared_ptr<Entity>sharedentity(new Entity());   //Also possible, but don't use it.
			e0 = sharedentity;
		}//Shared entity does not get expired here, due to ref of e0.
		//When the first scope dies,shared entity dies, however(usually).But it does not happen because e0 is still alive and 
		//holding a reference to that entity.When all the references are gone that when the underlying entity gets destructed. 

	}//sharedentity expires here.

	{
		weak_ptr<Entity>e1;
		{
			shared_ptr<Entity>sharedentity1 = make_shared<Entity>();
			e1 = sharedentity1;
		}//sharedentity1 gets expired here.
		//When you assign a shared ptr to another shared ptr that is copying it,it will increase the ref count,but when you 
		//assign a shared ptr to a weak ptr,it won't increase the ref count.This is great if you dont want to take the ownership 
		//of the enitiy.With a weak ptr we can ask is this still alive and if it is you can do whatever you want to do, but it 
		//won't keep it alive.
	}



	cin.get();
}

