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
        LogEndReturning(true);
        return true;
    }
    bool InsertAfter(T val, T val2)
    {
        LogStart(val, val2);
        DListNode * nextNode;
        DListNode * nodePtr = tail;
        bool result = false;
        if(nodePtr->data == val2 && (nodePtr->next == nullptr && nodePtr->prev == nullptr))
        {
            DListNode * temp = new DListNode(val);
            temp->next = nullptr;
            temp->prev = nodePtr;
            nodePtr->next = temp;
            tail = temp;
            result = true;
        }
        if((nodePtr->data == val2 && nodePtr->prev != nullptr) && !result)
        {
            DListNode * temp = new DListNode(val);
            temp->next = nullptr;
            temp->prev = nodePtr;
            nodePtr->next = temp;
            tail = temp;
            result = true;
        }
        nodePtr = head;
        if((nodePtr->data == val2 && nodePtr->next != nullptr) && !result)
        {
            DListNode * temp = new DListNode(val);
            nextNode = nodePtr->next;
            temp->next = nextNode;
            temp->prev = nodePtr;
            nextNode->prev = temp;
            nodePtr->next = temp;
            result = true;
        }
        if(!result)
        {
            while(nodePtr != nullptr && nodePtr->data != val2)
            {
                nodePtr = nodePtr->next;  
                nextNode = nodePtr->next;  
            }
            if(nodePtr != nullptr)
            {
                DListNode * temp = new DListNode(val);
                temp->next = nodePtr->next;
                temp->prev = nodePtr;
                nodePtr->next = temp;
                nextNode->prev = temp;
                result = true;
            }
        }
        LogEndReturning(result);
        return result;
    }
    bool Delete(T val)
    {
        LogStart(val);
        bool result = false;
        DListNode * prevNode;
        DListNode * nextNode;
        DListNode * nodePtr = tail;
        if(Contains(val))
        {
            if(nodePtr->next == nullptr && nodePtr->prev == nullptr)
            {
                head = nodePtr->next;
                tail = nodePtr->next;
                delete nodePtr;
                result = true;
            }
            if(!result && nodePtr->data == val)
            {
                tail = nodePtr->prev;
                tail->next = nodePtr->next;
                delete nodePtr;
                result = true;
            }
            nodePtr = head;
            if(!result && nodePtr->data == val)
            {
                head = nodePtr->next;
                head->prev = nodePtr->prev;
                delete nodePtr;
                result = true;
            }
            if(!result)
            {
                while(nodePtr != nullptr && nodePtr->data != val)
                {
                    prevNode = nodePtr;
                    nodePtr = nodePtr->next;
                    nextNode = nodePtr->next;
                }
                if(nodePtr != nullptr)
                {
                    prevNode->next = nodePtr->next;
                    nextNode->prev = nodePtr->prev;
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
        DListNode * nodePtr = head;
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
        DListNode * nodePtr = head;
        LogEndReturning(nodePtr->data);
        return nodePtr->data;
    }
    T & Back()
    {
        if(Empty())
            throw "List Empty";
        LogStart();
        DListNode * nodePtr = tail;
        LogEndReturning(nodePtr->data);
        return nodePtr->data;
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





