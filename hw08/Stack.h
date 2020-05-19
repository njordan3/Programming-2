#pragma once
#include "cmpslib.h"


// create your stack class , it will be a template container
// you will need a constructor it will allow the user to pass in the size/capacity of the container as the only parameter
// have this default to the value of 4

// a public function that returns true or false if the container is empty

// a public function that returns true or false if the container is full

// a public function that returns the capacity of the stack

// a public function that allows a value to be added or  "pushed" into the stack, returns 
// true or false if push operation was successful

// a public function that will remove or "popped' a value from the stack
// true or false if pop operation was successful

// a public function that returns a reference to the top value on the stack
// throws a descriptive message if stack is empty

// a private function that will double the capacity of the container
// returns true if successful, false if the new operation throws and exception
template <class T>
class Stack
{
    private:
        T * data;  
        int capacity; 
        int TopIndex;
        bool DoubleCapacity()
        {
            LogStart();
            bool result = false;
            if(Full())
            {
                capacity = capacity * 2;
                T * temp = new T[capacity];
                for(int loop = 0; loop < capacity/2; loop++)
                {
                    temp[loop] = data[loop];
                }
                delete[] data;
                data = temp;
                result = true;
            }
            LogEndReturning(result);
            return result;
        }   
    public:
        Stack(int size = 4)
        {
            LogStart();
            capacity = size;
            TopIndex = -1;
            data = new T[capacity];
            LogEnd();
        }
        ~Stack()
        {
            LogStart();
            delete[] data;
            LogEnd();
        }
        bool Empty()
        {
            LogStart();
            bool result = false;
            if(TopIndex <= -1)
            {
                result = true;
            }
            LogEndReturning(result);
            return result;       
        }
        bool Full()
        {
            LogStart();
            bool result = false;
            if(TopIndex >= capacity - 1)
            {
                result = true;
            }
            LogEndReturning(result);
            return result;
        }
        int Capacity()
        {
            LogStart();
            LogEndReturning(capacity);
            return capacity;
        }
        bool Push(T val)
        {
            LogStart();
            bool result = false;
            if(Full())
            {
                DoubleCapacity();
            }
            if(!Full())
            {
                TopIndex++;
                data[TopIndex] = val;
                result = true;
            }
            LogEndReturning(result);
            return result;
        }
        bool Pop()
        {
            LogStart();
            bool result = false;
            if(!Empty())
            {
                if(TopIndex > -1)
                {
                    TopIndex--;
                }
                result = true;
            }
            LogEndReturning(result);
            return result;
        }
        ELEMTYPE Top()
        {
            LogStart();
            LogEndReturning(data[TopIndex]);
            return data[TopIndex];
        }
        string ToString()
        {
            LogStart();
            ostringstream temp;
            temp << "ToString(): \n"
                << "TopIndex: " << TopIndex << endl
                << "Capacity(): " << Capacity() << endl
                << "Empty(): " << boolalpha << Empty() << endl
                << "Full(): " << boolalpha << Full() << endl;
                for(int loop = 0; loop <= TopIndex; loop++)
                {
                    temp << "data[" << loop << "]: address "
                        << &data[loop] << " value: " << data[loop] << endl;
                }
            LogEndReturning(temp.str());
            return temp.str();
        }
       
};







