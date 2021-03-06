#include "DynamicArray.h"


// put all the function bodies for the DynamicArray class here
int DynamicArray::object_count = 0;
DynamicArray::DynamicArray(int val)   //constructor
{
    LogStart(val);
    LogLow("at the beginning of the constructor the pointer data is %p\n", data);
    capacity = val;
    data = new string[capacity];
    object_count++;
    LogLow("setting the pointer data to a new array of size %s\n", capacity);
    LogLow("at the end of the constructor the pointer data is %p, it should be different than what it was\n", data);
    LogEnd(capacity);
}
DynamicArray::DynamicArray(DynamicArray & val)  //copy constructor
{
    LogStart(val);
    capacity = val.capacity;
    object_count++;
    data = new string[val.capacity];
    for(int loop = 0; loop < val.capacity; loop++)
    {
        LogLow("copying valye at position %s from object passed in to my array\n",loop);
        data[loop] = val.data[loop];
    }

    LogEnd(val);
}
DynamicArray::~DynamicArray() //destructor
{
    LogStart();
    LogLow("in destructor object_count=%s, data=%p\n",object_count,data);
    delete[] data;
    object_count--;
    LogEnd(); 
}

string DynamicArray::ToString()   //ToString
{
    LogStart();

    ostringstream temp;
    temp << "capacity: " <<  capacity << endl;
    temp << "object_count: " << object_count << endl;
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
int DynamicArray::GetObjectCount()
{
    LogStart();
    LogEndReturning(object_count);
    return object_count;
}
string CreateXML(DynamicArray & val)
{
    LogStart(val);

    ostringstream temp;
    temp << "<DynamicArray>\n";
    temp << "<capacity>" << val.capacity << "</capacity>\n"; 
    temp << "<object_count>" << val.object_count << "</object_count>\n";
    temp << "<data>\n";
    for(int loop = 0; loop < val.capacity; loop++)
    {
        temp << "  <value>" << val.data[loop] << "</value>\n";
    }  
    temp << "</data>\n";
    temp << "</DynamicArray>\n";

    LogEndReturning(temp.str());
    return temp.str();
}
bool DynamicArray::operator == (const DynamicArray & rhs)
{
    LogStart(rhs);
    bool result = true;
    if(this->capacity != rhs.capacity)
    {
        result = false;
    }
    else
    {
        for(int loop = 0; loop < rhs.capacity; loop++)
        {
            if((this->data[loop] > rhs.data[loop]) || (this->data[loop] < rhs.data[loop]))
            {
                result = false;   
            }
        }
    }
    LogEndReturning(result);
    return result;
}
DynamicArray DynamicArray:: operator = (const DynamicArray & rhs)
{
    LogStart(rhs);
    //string * temp = new string[this->capacity + rhs.capacity];
    if(rhs.capacity > this->capacity)
    {
        delete[] data;
        this->data = new string[rhs.capacity];
    }
    this->capacity =rhs.capacity;

    for(int loop = 0; loop < rhs.capacity; loop++)
    {
        this->data[loop] = rhs.data[loop]; 
    }

    LogEndReturning(*this);
    return *this;
}
DynamicArray DynamicArray:: operator + (const DynamicArray & rhs)
{   
    LogStart(rhs);
    LogLow("\n\n\n\n\n\n\nStarting + operator");
    LogLow("lhs capacity=%s \n",capacity);
    LogLow("rhs capacity=%s \n",rhs.capacity);
    int size = this->capacity + rhs.capacity;
    DynamicArray temp(size);
    for(int loop = 0; loop < this->capacity; loop++)
    {
        temp.data[loop] = this->data[loop];
        LogLow("added %s at %s \n", this->data[loop], loop);
    }
    LogLow("\n\n\n\n\n\n\n\n%s\n",rhs.capacity);
    for(int loop2 = 0; loop2 < rhs.capacity; loop2++)
    {

        temp.data[loop2 + this->capacity] = rhs.data[loop2];
        LogLow("added %s at %s \n", rhs.data[loop2], loop2+this->capacity);
    }
    LogEndReturning(temp);
    return temp;
}
