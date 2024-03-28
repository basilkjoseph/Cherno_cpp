#include<iostream>
using namespace std;
#include "common.h"
#include "log.h"
void initlog()
{
	log("Initialising log");
}
void log(const char* message)
{
	cout << message << endl;
}