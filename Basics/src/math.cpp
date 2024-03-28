#define INTEGER int 
void log(const char* message);
#if 1              //#if preprocessor is used to select which code is to be executed and which is to be not 
                   //according to the test condition(Here just 1,true)//
static INTEGER Multiply(int a, int b)     
                   //Here Multiply is made static.Hence it exists only in math.cpp
	               //Also Multiply is never called anywhere.Hence there won't be any linking error, since 
	               //log function is not used anywhere.If we create a main function in this file and call
	               //Multiply, it will inturn call log function, which the linker won't be able to find
	               //since it does not exist//
	               //Without the static keyword, there will occur a linking error whether the Multiply function
				   // is called or not, since the linker tries to link the definition(which it will never find) 
				   // of log funtion in hope that somewhere in the project Multiply will be used.
{
	log("Multiply");
	INTEGER result = a * b;
	return result;
}
#endif
#if 0              //This block of codes will not be executed since condition is always false(0)//
INTEGER Multiply(int a, int b)
{
	INTEGER result = a * b;
	return result;
}
#endif
