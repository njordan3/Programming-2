#pragma once
#include "cmpslib.h"


int Sort1(int *array, int count)
{
    LogStart(array,count);
    int comparisons = 0;
    for(int loop = 0; loop < count; loop++)
    {
        for(int loop2 = 0; loop2 < count - 1; loop2++)
        {
            if( *(array + loop2) > *(array + loop2 + 1))
            {
                swap(*(array + loop2),*(array + loop2 + 1));
            }
            comparisons++;
        } 
    }

    LogEndReturning(comparisons);
    return comparisons;    
}


int Sort2(int *array, int count)
{
    LogStart(array,count);
    int comparisons = 0;
    for(int loop = 0; loop < count; loop++)
    {
        for(int loop2 = 0; loop2 < count - 1 - loop; loop2++)
        {
            if( *(array + loop2) > *(array + loop2 + 1))
            {
                swap(*(array + loop2),*(array + loop2 + 1));
            }
            comparisons++;
        } 
    }
    LogEndReturning(comparisons);
    return comparisons;    
} 


int Sort3(int *array, int count)
{
    LogStart(array,count);
    int comparisons = 0;
    bool swapped = false;
    for(int loop = 0; loop < count; loop++)
    {
        swapped = false;
        for(int loop2 = 0; loop2 < count - 1 - loop; loop2++)
        {
            comparisons++;
            if( *(array + loop2) > *(array + loop2 + 1))
            {
                swapped = true;
                swap(*(array + loop2),*(array + loop2+1 ));
            }

        }
        if(swapped == false)
        {
            LogEndReturning(comparisons);
            return comparisons;
        }
    }

    LogEndReturning(comparisons);
    return comparisons;    
}


int Sort4(int *array, int count)
{
    LogStart(array,count);
    int comparisons = 0;
    bool swapped = false;
    for(int loop = 0; loop < count; loop++)
    {
        swapped = false;
        for(int loop2 = loop; loop2 + 1 < count; loop2++)
        {
            comparisons++;
            if(*(array + loop) > *(array + loop2))
            {
                swapped = true;
                swap(*(array + loop),*(array + loop2));
            }
        }
        if(swapped == false)
        {
            LogEndReturning(comparisons);
            return comparisons;    
        }
    }
    LogEndReturning(comparisons);
    return comparisons;    
}












