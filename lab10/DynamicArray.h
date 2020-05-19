#pragma once
#include "cmpslib.h"



class DynamicArray
{
    private:// private data members
        string * data;
        int capacity;
        static int object_count;
    public: //publc functions
        DynamicArray(int val = 5);
        DynamicArray(DynamicArray & val);
        ~DynamicArray();
        string ToString();
        bool SetValue(string, int);
        static int GetObjectCount();
        friend string CreateXML(DynamicArray & val);
        bool operator == (const DynamicArray &);
        DynamicArray operator = (const DynamicArray &);
        DynamicArray operator + (const DynamicArray &);
};
