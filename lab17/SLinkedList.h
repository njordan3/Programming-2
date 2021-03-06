#pragma once
#include "cmpslib.h"



// Define the list node structure.

// It contains an element of the template type

// and a pointer to the next node in the list.


template <class T>
class SLinkedList
{
    /*
       We need a node that is templated to store the same type as our
       Linked List. The easiest way to do this is make it an "Inner" class
       */
    class SListNode
    {
        public:
            T data;
            SListNode *next;
            SListNode(T val)
            {
                data = val;
                next = nullptr;
            }
    };

    SListNode * head;

    public:
    SLinkedList()
    {
        // make sure head to the nullptr
        head = nullptr;
    }


    bool Insert(T val)
    {
        LogStart(val);
        // insert a new node to store val
        // at the head or the list
        SListNode * newNode;
        newNode = new SListNode(val);
        newNode->next=head;
        head = newNode;
        return true;
    }

    string ToString()
    {
        LogStart();
        // return a text representation of the stack
        // IT MUST WORK WITH THE WEBPAGE
        SListNode * nodePtr;
        nodePtr = head;
        ostringstream temp;
        temp << "SList: \nhead: " << nodePtr << endl;
        while(nodePtr != nullptr)
        {
            temp << "node: " << &nodePtr->data << " data: " << nodePtr->data << " next: " << nodePtr->next << endl; 
            nodePtr = nodePtr->next;
        }
        LogEndReturning(temp.str());
        return temp.str();
    }
}; // end SLinkedList





