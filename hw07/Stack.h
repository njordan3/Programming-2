#pragma once
#include "cmpslib.h"



// create your stack class, it will store integers
class Stack
{
    private:
        int * data;
        int capacity;
        static int elements_amount;
        int top;
    public:
        Stack(int size = 4);
        ~Stack() { delete[] data; }
        string ToString();
        // you will need a constructor it will allow the user to pass in the size/capacity of the container as the only parameter
        // have this default to the value of 4

        // a public function that returns true or false if the container is empty
        bool isEmpty();
        // a public function that returns true or false if the container is full
        bool isFull();
        // a public function that returns the capacity of the stack
        int Capacity();
        // a function that returns the number of elements currently in the stack
        int Size();
        // a public function that allows a value to be added or  "pushed" into the stack, returns 
        // true or false if push operation was successful
        bool Push(int);
        // a public function that will remove or "pop' a value from the stack
        // true or false if pop operation was successful
        bool Pop();
        // a public function that returns a reference to the top value on the stack
        // if the stack is empty return the value at postition 0

        //			if (Empty())
        //				throw "Stack::Top could not return top  value from empty stack.";
        int Top();
};
int Stack::elements_amount = 0;
Stack::Stack(int size)
{
    LogStart(size);
    
    capacity = size;
    data = new int[capacity];   
    top = 0;

    LogEnd(size);
}
bool Stack::isEmpty()
{
    LogStart();
    LogEndReturning(top <= 0);
    return (top <= 0);
}
bool Stack::isFull()
{
    LogStart();
    LogEndReturning(top >= capacity);
    return (top >= capacity);   
}
int Stack::Size()
{
    LogStart();
    LogEndReturning(elements_amount);
    return elements_amount;
}
int Stack::Capacity()
{
    LogStart();
    LogEndReturning(capacity);
    return capacity;
}
bool Stack::Push(int val)
{
    LogStart(val);
    bool isSuccessful = false;
    if(!isFull())
    {
        data[top] = val;
        isSuccessful = true;
        elements_amount++;
        top++;
    }
    LogEndReturning(isSuccessful);
    return isSuccessful;
}
bool Stack::Pop()
{
    LogStart();
    
    bool isSuccessful = false;
    if(!isEmpty())
    {
        if(top > 0)
        {
            top--;
        }
        elements_amount--;
        isSuccessful = true;
    }

    LogEndReturning(isSuccessful);
    return isSuccessful;
}
int Stack::Top()
{
    LogStart();
    int result;
    if(isEmpty())
    {
        result = 0;
    }
    else
    {
        result = data[top-1];
    }
    LogEndReturning(result);
    return result;
}
string Stack::ToString()
{
    LogStart();

    ostringstream temp;
    temp << "ToString():\n"
         << "TopIndex: " << top << endl
         << "Capacity(): " << Capacity() << endl
         << "Size(): " << Size() << endl
         << "Empty(): " << boolalpha << isEmpty() << endl
         << "Full(): " << boolalpha << isFull() << endl;
    if(!isEmpty())
    {
         for(int loop = 0; loop < top; loop++)
         {
            temp << "data[" << loop << "]: address: " << &data[loop] << "value: " << data[loop] << endl;
         }
    }  
    LogEndReturning(temp.str());
    return temp.str();
}



