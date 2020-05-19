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
                LogStart();
                data = val;
                next = nullptr;
                LogEnd();
            }
    };

    SListNode * head;

    public:
    SLinkedList()
    {
        LogStart();
        // make sure head to the nullptr
        head = nullptr;
        LogEnd();
    }
    ~SLinkedList()
    {
        LogStart();
        SListNode * temp = head;
        SListNode * temp2 = head;
        while(temp2 != nullptr)
        {
            temp = temp2;
            temp2 = temp2->next;
            delete temp;
        }
        LogEnd();
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
    bool InsertAfter(T val, T val2)
    {
        LogStart(val, val2);
        SListNode * nodePtr = head;
        bool result = false;
        while(nodePtr != nullptr && nodePtr->data != val2)
        {
            nodePtr = nodePtr->next;    
        }
        if(nodePtr != nullptr)
        {
            SListNode * temp = new SListNode(val);
            temp->next = nodePtr->next;
            nodePtr->next = temp;
            result = true;
        }
        LogEndReturning(result);
        return result;
    }
    bool Delete(T val)
    {
        LogStart(val);
        bool result = false;
        SListNode * prev;
        SListNode * nodePtr = head;
        if(!Contains(val))
        {
            if(nodePtr->data == val)
            {
                head = nodePtr->next;
                result = true;
            }
            else
            {
                while(nodePtr != nullptr && nodePtr->data != val)
                {
                    prev = nodePtr;
                    nodePtr = nodePtr->next;
                }
                if(nodePtr != nullptr)
                {
                    prev->next = nodePtr->next;
                    delete nodePtr;
                    result = true;
                }
            }
        }
        LogEndReturning(result);
        return result;
    }
    bool Contains(T val)
    {
        LogStart();
        bool result = false;
        SListNode * nodePtr;
        nodePtr = head;
        while(nodePtr != nullptr)
        {
            if(nodePtr->data == val)
            {
                result = true;
            }
            nodePtr = nodePtr->next;       
        }
        LogEndReturning(result);
        return result;
    }
    bool Empty()
    {
        LogStart();
        bool result = false;
        SListNode * nodePtr;
        nodePtr = head;
        if(nodePtr == nullptr)
        {
            result = true;
        }
        LogEndReturning(result);
        return result;
    }
    T & Front()
    {
        if(Empty())
            throw "List Empty";
        LogStart();
        SListNode * nodePtr;
        nodePtr = head;
        LogEndReturning(nodePtr->data);
        return nodePtr->data;
    }
    T & Back()
    {
        if(Empty())
            throw "List Empty";
        LogStart();
        SListNode * nodePtr;
        SListNode * nodeResult;
        nodePtr = head;
        while(nodePtr != nullptr)
        {
            nodeResult = nodePtr;
            nodePtr = nodePtr->next;   
        }
        LogEndReturning(nodeResult->data);
        return nodeResult->data;
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





