
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;

#ifndef ELEMTYPE  // only do the following define if its not already defined
#define ELEMTYPE  int
#endif

#include "Stack.h"


int main()
{
    LoggerSetUpLog("main2.log");
	Stack stack;
  for(int loop=0;loop<6;loop++)
		{ 
    cout << boolalpha << "adding "<< loop  << stack.Push(loop) << endl;
		}

}



