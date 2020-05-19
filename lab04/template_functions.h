#include <iostream>
#include "cmpslib.h"
using namespace std;


#define LOGLEVEL 3

// here are copies of GetLarger and GetSmaller for datatype char*

const char * GetLarger (const char* a, const char* b)
{
	LogStart(a,b);
	if (strcmp(a,b) <0 )
	{
		LogEndReturning(b);
		return b;
	}
	LogEndReturning(a);
	return a;
}

const char * GetSmaller (const char* a, const char* b)
{
	LogStart(a,b);
	if (strcmp(a,b) >0 )
	{
		LogEndReturning(b);
		return b;
	}
	LogEndReturning(a);
	return a;
}

template <class T>
T GetLarger (T a, T b)
{
    LogStart(a,b);
    if(a > b)
    {
        LogEndReturning(a);
        return a;
    }
    LogEndReturning(b);
    return b;
}
//  return the larger value a or b

template <class T>
T GetSmaller (T a, T b)
{
    LogStart(a,b);
    if(a > b)
    {
        LogEndReturning(b);
        return b;
    }
    LogEndReturning(a);
    return a;

}
//  return the smaller value a or b



template <class T>
T GetLarger (T a, T b, T c)
{
    LogStart(a,b,c);
    LogEndReturning(GetLarger(GetLarger(a,b),c));
    return GetLarger(GetLarger(a,b),c);
}
// return the larger value a,b or c
// you only need to call the GetLarger for 2 parameters twice , first with a & b then use that result to compare with c
// DO NOT USE < or > in this function
// we want to use this function to work for ( char * ) or constant c strings too you cant use < or > on them


template <class T>
T GetSmaller (T a, T b, T c)
{
    LogStart(a,b,c);
    LogEndReturning(GetSmaller(GetSmaller(a,b),c));
    return GetSmaller(GetSmaller(a,b),c);
}
//  return the smaller value a,b or c
// you only need to call the GetSmaller for 2 parameters twice , first with a & b then use that result to compare with c
// DO NOT USE < or > in this function


template <class T>
void SwapValues( T & a, T & b)
{
    LogStart(a,b);
    T temp = a;
    a = b;
    b = temp;
    LogEnd(a,b);
}
// swap the values in the two parameters passed in
// DO NOT use the "swap" function





