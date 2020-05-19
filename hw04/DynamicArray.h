#pragma once
#include "cmpslib.h"



class DynamicArray
{
    private:// private data members
        string * data;
        int capacity;

    public: //publc functions
        DynamicArray(int val = 5);
        ~DynamicArray();
        string ToString();
        bool SetValue(string, int);

};
