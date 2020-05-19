#include "functions.h"

// put your function bodies here
int TripleInt_PBV(int val)
{
    LogStart(val);
    LogEndReturning(val * 3);
    return val * 3;

}
void TripleInt_PBR(int & val)
{
    LogStart(val);
    val *= 3;
    LogEnd(val);
}
void TripleInt_PBP(int * val)
{
    LogStart(val);
    *val *= 3;
    LogEnd(val);
}

void SwapInts_PBR(int & a, int & b)
{
    LogStart(a,b);
    swap(a,b);
    LogEnd(a,b);
}
void SwapInts_PBP(int * a, int * b)
{
    LogStart(a,b);
    swap(*a, *b);
    LogEnd(a,b);
}

int IsLarger_PBV(int a, int b)
{
    LogStart(a,b);
    int result = a;
    if(b > a)
    {
        result = b;
    }
    LogEndReturning(result);
    return result;
}
void IsLarger_PBR(int a, int b, int & result)
{
    LogStart(a,b,result);
    result = a;
    if(b > a)
    {
        result = b;
    }
    LogEnd(a,b,result);
}
void IsLarger_PBP(int a, int b, int * result)
{
    LogStart(a,b,result);
    *result = a;
    if(b > a)
    {
        *result = b;
    }
    LogEnd(a,b,result);
}


