#include "DynamicArray.h"


// put all the function bodies for the DynamicArray class here
DynamicArray::DynamicArray(int val)   //constructor
{
    LogStart(val);
    LogLow("at the beginning of the constructor the pointer data is %p\n", data);
    capacity = val;
    data = new string[capacity];
    LogLow("setting the pointer data to a new array of size %s\n", capacity);
    LogLow("at the end of the constructor the pointer data is %p, it should be different than what it was\n", data);
    LogEnd(capacity);
}
DynamicArray::~DynamicArray() //destructor
{
    LogStart();
    delete[] data;
    LogEnd(); 
}

string DynamicArray::ToString()   //ToString
{
    LogStart();

    ostringstream temp;
    temp << "capacity: " <<  capacity << endl;
    for(int loop = 0; loop < capacity; loop++)
    {
        temp << "data[" << loop << "] value: " << *(data + loop) << endl;
    }   
    LogEndReturning(temp.str());
    return temp.str();
}
bool DynamicArray::SetValue(string input, int pos)
{
    LogStart(input, pos);
    
    bool result = true;
    if(pos < 0 || pos > capacity - 1)
    {
        result = false;
    }
    else
    {
        *(data + pos) = input;
    }

    LogEndReturning(result);
    return result;
}

