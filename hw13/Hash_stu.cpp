#include "Hash.h"


HashTable::HashTable(int cap)
{
    LogStart(cap);
    capacity = cap;
    hashtable = new int[capacity];
    count = 0;
    for(int loop = 0; loop < capacity; loop++)
    {
        hashtable[loop] = EMPTY_VALUE;
    }
    LogEnd(cap);
}
HashTable::~HashTable()
{
    LogStart();
    delete[] hashtable;
    LogEnd();
}

// Calculates the primary key using modulo arithmetic

// Primary key will be in the range 0 to MAX_CAPACITY - 1

int HashTable::hash1(int value)
{
    LogStart(value);
    int result = value % capacity;
    LogEndReturning(result);
    return result;
}

// for the 2nd hash we want to have an alternate method of calculating a hash

// MAX_CAPACITY - ( value % MAX_CAPACITY)

int HashTable::hash2(int value)
{
    LogStart(value);
    int result = capacity - hash1(value);
    LogEndReturning(result);
    return result;
}


// create a string representation of the HashTable class

// make sure your output from the ToString function matches the example

// before AND AFTER you delete some items 

string HashTable::ToString()
{
    LogStart();
    ostringstream temp;
    temp << "HashTable: \nhash size: " << capacity << endl;
    temp << "count: " << count << endl;
    for(int loop = 0; loop < capacity; loop++)
    {   
        if(hashtable[loop] != EMPTY_VALUE)
        {
            if(hashtable[loop] == DELETED_VALUE)
            {
                temp << "hashtable[   " << loop << "] contains: DELETED_VALUE\n";
            }
            else
            {
                temp << "hashtable[   " << loop << "] contains:" << hashtable[loop] << " hash1=    " << hash1(hashtable[loop]) << " hash2=    " << hash2(hashtable[loop]) << endl;
            }
        }
    }
    LogEndReturning(temp.str());
    return temp.str();
}
bool HashTable::empty()
{
    LogStart();   
    LogEndReturning(count == 0);
    return count == 0;
}
bool HashTable::full()
{
    LogStart();
    LogEndReturning(count == capacity);
    return count == capacity;
}
bool HashTable::search(int value)
{
    LogStart(value);
    bool result = false;
    if(hashtable[hash1(value)] == value)
    {
        result = true;
    }
    else
    {
        int loop = 1;
        int index2 = hash2(value);
        if(hashtable[index2] == value)
        {
            result = true;
            LogEndReturning(result);
            return result;
        }
        else
        {
            while(hashtable[index2+loop] != value || hashtable[index2+loop] != EMPTY_VALUE)
            {
                index2 = (index2+loop) % capacity;
                if(hashtable[index2] == value)
                {
                    result = true;
                    LogEndReturning(result);
                    return result;
                }
                loop++;
            }
        }
    }
    LogEndReturning(result);
    return result;
}
bool HashTable::insert(int value)
{
    LogStart(value);
    bool result = false;
    if(!full())
    {
        int index = hash1(value);  
        if(hashtable[index] < 0)
        {
            result = true;
            count++;
            hashtable[index] = value;
        }
        else
        {
            collisions++;
            int loop = 1;
            int index2 = hash2(value);
            int newIndex = hash2(value);
            if(hashtable[index2] < 0)
            {
                result = true;
                count++;
                hashtable[index2] = value;
            }
            else
            {
                while(hashtable[newIndex] != EMPTY_VALUE || hashtable[newIndex] != DELETED_VALUE)
                {
                    newIndex = (index2 + loop)% capacity;
                    if(hashtable[newIndex] < 0)
                    {
                        result = true;
                        count++;
                        hashtable[newIndex] = value;
                        LogEndReturning(result);
                        return result;
                    }
                    collisions++;
                    loop++;
                }
            }
        }
    }
    LogEndReturning(result);
    return result;
}
bool HashTable::remove(int value)
{
    LogStart(value);
    bool result = false;
    if(search(value))
    {       
        if(hashtable[hash1(value)] == value)
        {
            result = true;
            count--;
            hashtable[hash1(value)] = DELETED_VALUE;
        }
        else
        {
            int loop = 1;
            int index2 = hash2(value);
            int newIndex = hash2(value);
            if(hashtable[index2] == value)
            {
                result = true;
                count--;
                hashtable[index2] = DELETED_VALUE;
            }
            else
            {
                while(hashtable[newIndex+loop] != value || hashtable[newIndex+loop] != EMPTY_VALUE)
                {
                    newIndex = (index2+loop) % capacity;
                    if(hashtable[index2] == value)
                    {
                        result = true;
                        hashtable[newIndex] = DELETED_VALUE;
                        LogEndReturning(result);
                        return result;
                    }
                    loop++;
                }
            }

        }
    }
    LogEndReturning(result);
    return result;
}



