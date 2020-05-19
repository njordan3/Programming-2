// Author:  Melissa Danforth

// Purpose: Test out the quicksort routines

//          This code assumes you have the file quicksort.cpp and vt100ansi.h

//          provided in the lab in the same directory as this file when you

//          are compiling the program.


#include <iostream>
#include <fstream>
#include "quicksort.h"
using namespace std;

#define MAX_CAPACITY   1000

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        int count = 0;
        //  1. create an int array of size MAX_CAPACITY
        int myArray[MAX_CAPACITY];
        //  2. Open the file specified on the command line
        ifstream file;
        file.open(argv[1]);
        //  3. Verify that the file open succeeded
        if(file.is_open())
        {
            //  4. Read data in from the file until either the end of file is reached
            //     or you have read MAX_CAPACITY elements (use 'count' to track the
            //     number of elements read in to the array)
            int read;
            while(!file.eof() || count-1 == MAX_CAPACITY)
            {
                file >> read;
                if(file.good())
                {
                    myArray[count] = read;
                    count++;
                }
            }
            file.close();
            // 5. Call the quicksort algorithm to sort the data
            quicksort(myArray,0,count-1);   
        }
        else
        {
            cout << "Error: Could not open " << argv[1] << " for reading.\n";
        }
    }
    else
    {
        cout << "Usage: ./example <filename>\n";
    }
    return 0;
}
