#include<iostream>
using namespace std;
class Player        //Classes are by default private, but stuctures are by defaut public, that's the only 
	                //difference between them.Everything else is same. Change class keyword to struct and 
	                //everything works perfectly. To make struct private, explicitly declare it private.
	                //The only reason struct exist in C++ is to maintain compatibility with C,since it does 
	                //not have Class.
                    //It was possible to solve this issue by using #define struct class
	                //use struct just as a user defined datatype like complex in maths.
{               
public:
	int x, y;
	int speed;
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};

#if 0
void Move(Player& player, int xa, int ya)       //Function outside class
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}
#endif

class Log
{
public:
	const int LoglevelWarning = 1;
	const int LoglevelError = 0;
	const int LoglevelInfo = 2;
private:
	int m_Loglevel = LoglevelInfo;
	//m_xyz is for us to know which are class variables and which are local variables.
public:
	void setlevel(int level)
	{
		m_Loglevel = level;
	}
	void warn(const char* message)
	{
		if (m_Loglevel >= LoglevelWarning)
			cout << "[WARNING]" << message << endl;
	}
	void info(const char* message)
	{
		if (m_Loglevel >= LoglevelInfo)
			cout << "[INFO]" << message << endl;
	}
	void error(const char* message)
	{
		if (m_Loglevel >= LoglevelError)
			cout << "[ERROR]" << message << endl;
	}
};

class Entity
{
public:
	// Entity() = delete;          //Deleting a constructor.
	int x, y;
	static int a, b; 
	//if static is used with a variable,it means that there is only going to be one instance of that variable
	//accross all instances of the class.There will be only one version of a static varable over all instances.
	//so if one of the instances change a static variable, it is going to reflect that change accross all 
	//instances.This is because there is only one variable eventhough we make many class instances.Hence there 
	//is no point in refering to a variable through a class instance.In static method, we don't have access
	//to class instances.A static method can be called without a class instance, and inside a static method we 
	//cannot write a code which refers to a class instance.
	void print()
	{
		cout << x << "," << y << endl;
	}
	static void log()
	{
		cout << a << "," << b << endl; //static methods can access only static parameters.This is beacause
		                               //a static method does not have a class instance.
      //cout << x << "," << y << endl;     This line gives error
	}
	float X, Y;
	void Print()
	{
		cout << X << "," << Y << endl;
	}
	void Init()
	{
		X = 1.0f;
		Y = 1.0f;
	}//Instead of this function, we can use a constructor.

#if 0
	Entity()
	{
        //By default a constructor like this is always created in C++.It is using this constructor further
		//instances are created.If we make this constructor private or delete this constructor, we won't
		//be able to create instances like //Entity e;//
		//If any custom constructor is defines,an automatic default constructor is not defined.	
	}
	
#endif
	Entity()   //This is a constructor.Now we don't need the Init function, already X and Y are set to 0
	{
		X = 0.0f;
		Y = 0.0f;
		cout << "Created Entity" << endl;
	}
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}
	~Entity()    
	{
		cout << "Destroyed Entity" << endl;
	}
	//This is a Destructor. Does the opposite of what constructor does, Desrtoys an instance.This is done at 
	//the end of the function in which the instance is created. The output message function is seen when 
	//the control gets out of the function.In case of heap memory, destructor is called when delete is used.
	
};

void Function()
{
	Entity e2;
	e2.Print();                                    //Outputs some random garbage value without constructor
	//initialising X and Y.
	//cout << e.X << "," << e.Y << endl;           //This line does not compile without constructor 
												   //initialising X and Y.
	e2.Init();
	cout << e2.X << "," << e2.Y << endl;           //But this line compiles without constructor initialising
												   //X and Y.
	Entity e3(10.0f, 12.0f);
	cout << e3.X << "," << e3.Y << endl;
	Entity e;
	e.Print();
	e.~Entity(); //A destructor can be called like this also
}

#if 0

static void log()
{
	cout << x << "," << y << endl;
}//Here we don't know what x and y are.Same thing happens if we use this function inside class and try to 
// access non static variables.(we do not know what those variables are)

void print(Entity e)
{
	cout << e.x << "," << e.y << endl;
}//This is exactly what a non static method of a class looks like when compiled.

#endif 

int Entity::a;  //Defining a and b; else linking error occurs for static variables
int Entity::b;  //Here 'a' and 'b' don't really belong to the class.They do of-course in the sense that they 
//can be private and public.
//It's like we have made two variables inside a namespace called entity.


enum example//: char  //:unsigned char         //These can be used to modify size.
{
	A=4,B,C          
	//By default, A will be 0,B will be 1 and so on.But if we declare A say 4, B will be 5 and so on.
};

class cube
{
private:
	int m_Length;
public:
	cube()
	{
		//Default constructor
	}
	cube(const cube& c)
	{
		//default copy constructor
		m_Length = c.m_Length;
	}
};

int main()
{
	Player player1;

	//Move(player1, 1, -1);     for function outside class.
	player1.Move(1, -1); 


	Log log;
	log.setlevel(log.LoglevelInfo); 
	log.warn("Hello!");
	log.info("Hello!");
	log.error("Hello!");
	cout << "==================" << endl;

	Entity e;
	e.x = 2;
	e.y = 3;
	
	Entity e1 = { 5,8 };
	e.print();
	e1.print();
	
	
	e.a = 12;
	e.b = 13;
	e.log();

	
	e1.a = 16;  //After being made static, there is no point in refering to a and b like this.Instead,
	e1.b = 17;
	Entity::log();  //same as 'e.log();'     
	Entity::log();  //same as 'e1.log();'

	Entity::a = 16;     //a and b can be refered like this.
	Entity::b = 17;     //After being made static, 'a' has only one version of it, just 'a'.And no different
	                    //versions for different objects.
	//This is really useful when you want to have variables accross classes.Instead we could have created
	//a global variable or static global variable.However doing that would have the same effect as this.
	//If we have a piece of information that we want to be shared accross all entity instances,for organisational 
	// purposes it is better to store it in static variables.


	example value = A;


	cout << "===============" << endl;
#if 0
	Entity e2;
	e2.Print();                                    //Outputs some random garbage value without constructor
    //initialising X and Y.
	//cout << e.X << "," << e.Y << endl;           //This line does not compile without constructor 
	                                               //initialising X and Y.
	e2.Init();
	cout << e2.X << "," << e2.Y << endl;           //But this line compiles without constructor initialising
	                                               //X and Y.
	Entity e3(10.0f, 12.0f);
	cout << e3.X << "," << e3.Y << endl;
#endif
	Function();
	cin.get();
}