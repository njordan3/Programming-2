/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any       means, including                     photocopying,             recording, or other electronic or mechanical methods, without the prior         written permission of the author, Michael Sarr
   */

#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library




void PrintArray(int*array,int size)
{
    LogStart(array,size);
    cout << "Array Address" << array << endl;
    for(int loop =0; loop<size; loop++)
    {
        if(loop)
            cout << ",";
        cout << array[loop];
    }
    cout << endl;
    LogEnd(array,size);
}

int main()
{
    LoggerSetUpLog("main2.log");
    char filename[50];
    int choice;
    Prompt("Enter a value 1-3 to chose the file to open: ",choice,1,3);

    if (choice ==1 )
        strncpy(filename,"test_input9.txt",50);

    if (choice ==2 )
        strncpy(filename,"test_input50.txt",50);

    if (choice ==3 )
        strncpy(filename,"test_input100.txt",50);

    if (choice < 1 || choice > 3)
        return 9; // exit gracefuly

    int size = 5;
    cout << "Creating dynamic array of size 5\n";
    int * array = new int[size];
    cout << "opening file %s \n" << filename << endl;

    // now all your regular stuff can go here

    ifstream in;// Create an input file stream.

    in.open(filename);

    if (in.fail())
    {
        cout << "Could not open file \n"<< filename <<endl;
        return 9;// exit gracefully

    }
    cout << "Creating int count=0 and int size = 5\n";
    int count = 0;
    int temp;
    cout << "Adding records and incrementing count each time\n";
    cout << "Reading the values into my dynamic array\n";
    while ( in >> temp ) // reads in a single value into temp
    {
            // Continue if the line was sucessfully read.

            cout << "Storing " << temp << " into array[" << count << "]"<< endl;
            *(array + count) = temp;
            count++;
            if(count == size)
            {
                cout << "\tThe array is full, must resize\n";
                cout << "\tCurrent address of array is " << array << endl;
                cout << "\tSize = " << size << endl;
                cout << "\tCreating new array of size " << size*2 << endl;
                int * temp2 = new int[size*2];
                cout << "\tCopy elements from old array to new array\n";
                for(int loop = 0; loop < size; loop++)
                {
                    cout << "\t\tCopying array[" << loop << "]   (" << *(array + loop) << ")  to the new array\n";
                    *(temp2 + loop) = *(array + loop);

                }
                cout << "\tDeleting the old array\n";
                delete[] array;
                cout << "\tSet our array pointer to point to the new array\n";
                array = temp2;
                cout << "\tSet size to be double what it was\n";
                size *= 2;
                cout << "\tCurrent address of array is " << array << endl;
                cout << "\tSize = " << size << endl;
            }
    }
    in.close();
    PrintArray(array, count );
    cout << "deleting dynamic array\n";
    delete[] array;

    return 0;
}






