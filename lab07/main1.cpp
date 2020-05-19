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
  LoggerSetUpLog("main1.log");
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


  cout << "opening file %s \n" << filename << endl;

  // now all your regular stuff can go here

  ifstream in;// Create an input file stream.

  in.open(filename);

  if (in.fail())
    {
    cout << "Could not open file \""<< filename <<endl;
    return 9;// exit gracefully

    }
  int count = 0;
  int temp;
  while ( in >> temp  ) // reads in a single value into temp
    {
    // Continue if the line was sucessfully read.
    
    cout << temp << endl;
    count++;
    }
  in.close();

  int * array = new int[count];

  ifstream in2;// Create an input file stream.

  in2.open(filename);

  if (in2.fail())
    {
    cout << "Could not open file \""<< filename <<endl;
    return 9;// exit gracefully

    }
  int count2 = 0;
  int temp2;
  while ( in2 >> temp2  ) // reads in a single value into temp
    {
    // Continue if the line was sucessfully read.
        *(array + count2) = temp2;
        count2++;
    }
  in2.close();

  PrintArray(array, count2);
  cout << "deleting dynamic array\n";
  delete[] array;
  /*
     now make a dynamic array large enought to store the values from the file we just opened
     
     add something to count the number of values when you read them in the first time
     you will then create a dynamic array that is large enought to store values in the specific 
     open the file again and read the values into the file
     (use the code above as an example of how to open and read a file line by line)
     print them out
     delete your dynamic array
   */
  
  return 0;
  }






