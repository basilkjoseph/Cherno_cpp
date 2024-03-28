#pragma once
#include<iostream>
static void logr(const char* message)   //logr is made to avoid linking error.Alredy a definition of logr esist
                                        //in log.cpp; so while including log.h; we will get 2 definitions for the  
	                                    //for the same function.Hence a linking error will occur.If it is made 
	                                    //static.This code will be copied to main.cpp; but it will be visible 
	                                    //only in main.cpp; main will have its own version of logr; provided there
	                                    //is no definition of logr in main.cpp; else ther will occur a compiler 
	                                    //error(multiple definition in same file)//
{
	std::cout << message << std::endl;
}