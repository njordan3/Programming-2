#pragma once
#include "cmpslib.h"



#ifndef QUEUESIZE
#define QUEUESIZE 10
#endif

#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

class Queue
{
    private:
        ELEMTYPE data[QUEUESIZE];
        int backIndex;

    public:

        Queue();
        ~Queue();
        bool empty();
        bool full();
        int size();
        bool enQueue(ELEMTYPE elem);
        bool deQueue();
        ELEMTYPE peekFront();
        string ToString();// return a string representation of the data in the container..

};

// the size is the difference between the back and front

// for this queue the fornt is always index 0

int Queue::size()
{
    LogStart();
    {
        LogEndReturning(backIndex);
        return backIndex;
    };
    return backIndex;
}



// Initialize the Queue

Queue::Queue()
{
    // the back to 0
    LogStart();
    backIndex = 0;
    LogEnd();
}


Queue::~Queue()
{
    LogStart();
    LogEnd();
}


bool Queue::empty()
{
    // return a bool value indicating if the Queue is empty
    LogStart();
    bool result = false;
    if(backIndex == 0)
    {
        result = true;
    }
    LogEndReturning(result);
    return result;
}


// Check if the Queue is currently full

bool Queue::full()
{
    // return a bool value indicating if the Queue is full
    LogStart();
    bool result = (backIndex == QUEUESIZE);
    
    LogEndReturning(result);
    return result;
}

// Add an element to the top of the Queue

bool Queue::enQueue(ELEMTYPE elem)
{
    // insert the value elem to the Queue
    // increment the topIndex and
    // return true
    LogStart();
    bool result = false;
    if(!full())
    {
        data[backIndex] = elem;
        backIndex++;
        result = true;   
    }
    LogEndReturning(result);
    return result;
}


// Remove the element at the top of the Queue

bool Queue::deQueue()
{
    // if the Queue is empty return false
    // shift all the elements in the array over one positon
    // replace  element 0 ( front ) with the one at index 1
    //  1 with 2 , 2 with 3, 3 with 4 and so on
    // decrement the back
    // return true
    LogStart();
    bool result = false;
    if(!empty())
    {
        for(int loop = 0; loop < backIndex-1; loop++)
        {
            data[loop] = data[loop+1];
        }
        backIndex--;
        result = true;
    }
    LogEndReturning(result);
    return result;
}




// Retrieve the value at the top of the Queue but do not delete it

ELEMTYPE Queue::peekFront()
{
    // if the queue is empty throw a descriptive exception
    // return the value at the top of the Queue
    LogStart();
    if(empty())
    {
        throw "cannot peekFront() on an empty queue";
    }
    LogEndReturning(data[0]);
    return data[0];
}


string Queue::ToString()
{
    // create a string reresentation of the Queue
    // show the backIndex, the values returnted by the functions size, empty, full
    // list the value of all the postitions of the array  ie
    // data[0]:addres 0x000048 value:duck
    // data[1]:addres 0x000052 value:chicken
    LogStart();
    ostringstream temp;
    temp << "backIndex: " << backIndex << endl
        << "size(): " << size() << endl
        << "empty(): " << boolalpha << empty() << endl
        << "full(): " << boolalpha << full() << endl; 
    for(int loop = 0; loop < backIndex; loop++)
    {
        temp << "data[" << loop << "]: address: "
            << &data[loop] << "value: " << data[loop] << endl;
    }
    LogEndReturning(temp.str());
    return temp.str();
}



