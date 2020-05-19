
#pragma once
#include "cmpslib.h"

#ifndef MAX_SIZE
#define MAX_SIZE 10
#endif

template <class T>
class Queue
{
    private:
        int frontIndex;
        int backIndex;
        T data[MAX_SIZE];
    public:
        Queue()
        {
            LogStart();
            frontIndex = 0;
            backIndex = 0;
            LogEnd();
        }
        Queue(Queue & val)
        {   
            LogStart(val);
            frontIndex = val.frontIndex;
            backIndex = val.backIndex;
            for(int loop = frontIndex; loop < backIndex; loop =((loop+1) % MAX_SIZE))
            {
                data[loop] = val.data[loop];
            }    
            LogEnd();
        }
        bool Empty()
        {
            LogStart();
            LogEndReturning(backIndex == frontIndex);
            return (backIndex == frontIndex);
        }
        bool Full()
        {
            LogStart();
            LogEndReturning((backIndex+1) % MAX_SIZE == frontIndex);
            return ((backIndex+1) % MAX_SIZE == frontIndex);
        }
        bool enQueue(T val)
        {
            LogStart(val);
            bool result = false;
            if(!Full())
            {
                data[backIndex] = val;
                backIndex = ((backIndex+1) % MAX_SIZE);
                result = true;       
            }
            LogEndReturning(result);
            return result;
        }
        bool deQueue()
        {
            LogStart();
            bool result = false;
            if(!Empty())
            {
                frontIndex = ((frontIndex+1) % MAX_SIZE);
                result = true;   
            }
            LogEndReturning(result);
            return result;
        } 
        T Front()
        {
            LogStart();
            if(Empty())
            {
                throw "cannot get front value on an empty queue";
            }
            LogEndReturning(data[frontIndex]);
            return data[frontIndex];
        }
        int Size()
        {
            LogStart();
            int result;
            if(frontIndex < backIndex)
            {
                result = backIndex - frontIndex;
            }
            else if(backIndex < frontIndex)
            {
                result = (MAX_SIZE - frontIndex) + backIndex;
            }
            LogEndReturning(result);
            return (result);   
            
            
        }
        string ToString()
        {
            LogStart();
            int loop = 0;
            ostringstream temp;
            temp << "ToString():\n" << "Queue:\n" 
                << "FrontIndex: " << frontIndex << endl
                << "BackIndex: " << backIndex << endl
                << "Size: " << Size() << endl
                << "Empty: " << boolalpha << Empty() << endl
                << "Full: " << boolalpha << Full() << endl
                << "elements\n";
            for(int loop2 = frontIndex; loop < Size(); loop2 = (loop2+1)%MAX_SIZE)
            {
                temp << "array[" << loop2 << "]: " << data[loop2] << endl;          
                loop++;
            }
            LogEndReturning(temp.str());
            return temp.str();
        }
};
// create your templated Queue class

// Constructor, set the Front and back index to 0

// copy constructor

// public function to indicate if the container is empty ,if the Front and back index are the same it is empty

// public function to indicate if the container is full , if you were to move forward one space from the backIndex would it equal the FrontIndex?

// function to add a value or "Enqueue"
// if the Queue is Full return false
// if the insert is sucessfull return true

// Function Remove
// if the Queue is Empty return false
// otherwise remove the element at the Front of the Queue
// return true

// Function Front
// return the value at the Front of the Queue
// if the Queue is Empty throw an excpetion

// Function Size
// how many item are in the queue

// Function ToString




