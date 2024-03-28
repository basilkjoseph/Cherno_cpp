#pragma once   //Header guard; only include this file once.Prevents us from including a single header file 
               //multiple times into a single translation unit.

//In this example, if we remove pragma once and compile log.cpp; we get compile error due to multiplicity of 
//struct

void initlog();
void log(const char* message);

struct player{};  //Withour pragma once, if we include log.h mutiple times in a translation unit, we get 
                  //error since two struct cannot have same name.