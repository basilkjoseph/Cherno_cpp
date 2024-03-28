#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	bool condition = true;
	for (; condition; )
	{
		cout << "Hello World" << endl;
		i++;
		if (!(i < 5))
			condition = false;
	}   //same as: for(i=0; i<5; i++)

	cout << "=====================" << endl;
	i = 0;
	while (i < 5)
	{
		cout << "Hello World" << endl;
		i++;
	}

	cout << "=====================" << endl;
	i = 0;
	do
	{
		cout << "Hello World" << endl;
		i++;
	} while (i < 5);

	cout << "=====================" << endl;
	for (i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue;    //continue and break are control flow statements usind in loops; eventhough break is also used in switch
		                 //continue when encountered, skips the following set of code and starts new iteration.
		                 //break completely ends the loop
		cout << i << " Hello World" << endl;
	}
	
	if (i == 5)
		return 0;
	cout << "Code Terminated" << endl;

	//Return is a control flow statement used to terminate a function. The rest of the code written after the return statement
	//is dead code.If the function has a return type, then we return the corresponding value also.

	cin.get();
	return 0; 
}