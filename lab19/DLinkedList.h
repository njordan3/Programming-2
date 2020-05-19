#pragma once
#include "cmpslib.h"



// Define the list node structure.

// It contains an element of the template type

// and a pointer to the next node in the list.


template <class T>
class DLinkedList
{
    /*
       We need a node that is templated to store the same type as our
       Linked List. The easiest way to do this is make it an "Inner" class
       */
    class DListNode
    {
        public:
            T data;
            DListNode *next;
            DListNode * prev;
            DListNode(T val)
            {
                LogStart();
                data = val;
                prev = nullptr;
                next = nullptr;
                LogEnd();
            }
    };

    DListNode * head;
    DListNode * tail;

    public:
    DLinkedList()
    {
        LogStart();
        // make sure head to the nullptr
        head = nullptr;
        tail = nullptr;
        LogEnd();
    }
    ~DLinkedList()
    {
        LogStart();
        DListNode * temp = head;
        DListNode * temp2 = head;
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
        DListNode * prevNode;
        DListNode * nodePtr = tail;
        DListNode * newNode = new DListNode(val);
        while(nodePtr != nullptr)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->prev;
        }
        newNode->prev = nullptr;
        newNode->next = head;
        //prevNode->prev = newNode;
        if(Empty())
        {
            tail = newNode;
        }
        else
        {
            prevNode->prev = newNode;
        }
        head = newNode;
        return true;
    }
    bool InsertAfter(T val, T val2)
    {
        LogStart(val, val2);
        DListNode * nodePtr = head;
        bool result = false;
        while(nodePtr != nullptr && nodePtr->data != val2)
        {
            nodePtr = nodePtr->next;    
        }
        if(nodePtr != nullptr)
        {
            DListNode * temp = new DListNode(val);
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
        DListNode * prev;
        DListNode * nodePtr = head;
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
        DListNode * nodePtr;
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
        DListNode * nodePtr;
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
        DListNode * nodePtr;
        nodePtr = head;
        LogEndReturning(nodePtr->data);
        return nodePtr->data;
    }
    T & Back()
    {
        if(Empty())
            throw "List Empty";
        LogStart();
        DListNode * nodePtr;
        DListNode * nodeResult;
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
        DListNode * nodePtr;
        nodePtr = head;
        ostringstream temp;
        temp << "head: " << nodePtr << endl;
        nodePtr = tail;
        temp << "tail: " << nodePtr << endl;
        nodePtr = head;
        while(nodePtr != nullptr)
        {
            temp << "node: " << &nodePtr->data << " data: " << nodePtr->data << " prev: " << nodePtr->prev <<  " next: " << nodePtr->next << endl; 
            nodePtr = nodePtr->next;
        }
        LogEndReturning(temp.str());
        return temp.str();
    }
}; // end DLinkedList





