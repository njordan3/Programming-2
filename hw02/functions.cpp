#include "functions.h"


// put your function bodies here
void Function1(int * result, int a, int b, int c)
{
    LogStart(result,a,b,c);

    *result = a;
    if(a > b && b > c)
    {
        *result = b;
    }
    if(c > b && b > a)
    {
        *result = b;
    }
    if(a > c && c > b)
    {
        *result = c;
    }
    if(b > c && c > a)
    {
        *result = c;
    }

    LogEnd(result,a,b,c);
}
void Function2(char * result, char a, char b, char c)
{
    LogStart(result,a,b,c);

    *result = a; 
    if(a > b && b > c)
    {
        *result = b;
    }
    if(c > b && b > a)
    {
        *result = b;
    }
    if(a > c && c > b)
    {
        *result = c;
    }
    if(b > c && c > a)
    {
        *result = c;
    }

    LogEnd(result,a,b,c);
}
void Function3(double * result, double a, double b, double c, double d, double e)
{
    LogStart(result,a,b,c,d,e);

    *result = a + b + c + d + e;;

    LogEnd(result,a,b,c,d,e);
}
void Function4(double * a, double * b, double * c)
{
    LogStart(a,b,c);

    //double one = *a, double two = *b, double three = *c;
    if(*a > *b)
    {
        swap(*b,*a);
    }
    if(*b > *c)
    {
        swap(*c,*b);
    }
    if(*a > *c)
    {
        swap(*b,*a);
    }

    LogEnd(a,b,c);
}
void Function5(double * a, double * b, double * c)
{
    LogStart(a,b,c);

    //double one = *a, double two = *b, double three = *c;
    if(*b > *a)
    {
        swap(*b,*a);
    }
    if(*c > *b)
    {
        swap(*c,*b);
    }
    if(*b > *a)
    {
        swap(*b,*a);
    }

    LogEnd(a,b,c);
}
char Function6(char a)
{
    LogStart(a);
    char temp;
    if(a > 96 && a < 123)
    {
        temp = a - 32;
        a = temp;
    }
    LogEndReturning(a);
    return a;    
}
char Function7(char a)
{
    LogStart(a);
    char temp;
    if(a > 64 && a < 91)
    {
        temp = a + 32;
        a = temp;
    }
    LogEndReturning(a);
    return a;
}
void Function8(char * a)
{
    LogStart(a);
    if(*a > 96 && *a < 123)
    {
        *a = *a - 32;
    }
    LogEnd(a);
}
void Function9(char * a)
{
    LogStart(a);
    if(*a > 64 && *a < 91)
    {
        *a = *a + 32;
    }
    LogEnd(a);
}



