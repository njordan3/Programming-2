/*   static arrays versus dynamic arrays      */


#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library




void PrintArray(int*array,int size)
  {
  LogStart(array,size);
  cout << "Array Address" << array << endl;
  for(int loop =0; loop<size; loop++)
    {
    if(loop)
      {
      cout << ",";
      }
    cout << array[loop];
    }
  cout << endl;
  LogEnd(array,size);
  }

int main()
  {
  LoggerSetUpLog("main1.log");

// create a static int array of size 20 named SIntArray
int SIntArray[20];
// create a dynamic int array of size 20 named DIntArray
int * DIntArray = new int[20];
// use a for loop to populate both arrays with the values 0-19 , use the [] operator
for(int i = 0; i < 20; i++)
{
    SIntArray[i] = i;
    DIntArray[i] = i;
}
// use the PrintArray functions to print them both out
cout << "SIntArray: \n";
PrintArray(SIntArray, 20);
cout << "DIntArray: \n";
PrintArray(DIntArray, 20);

// use a for loop to populate both arrays with the values 0-20, do not use the [] operator
for(int i = 0; i < 20; i++)
{
    *(SIntArray + i) = i;
    *(DIntArray + i) = i;
}
// use the PrintArray functions to print both arrays
cout << "SIntArray: \n";
PrintArray(SIntArray, 20);
cout << "DIntArray: \n";
PrintArray(DIntArray, 20);
// print out the address of the first  , second and fifth element of both arrays, use the & and [] operators
cout << "SIntArray: \n";
cout << "First: " << &SIntArray[0] << endl;
cout << "Second: " << &SIntArray[1] << endl;
cout << "Fifth: " << &SIntArray[4] << endl;
cout << "DIntArray: \n";
cout << "First: " << &DIntArray[0] << endl;
cout << "Second: " << &DIntArray[1] << endl;
cout << "Fifth: " << &DIntArray[4] << endl;
// print out the address of the first  , second and fifth element of both arrays, do NOT  use the & and [] operators
cout << "SIntArray: \n";
cout << "First: " << (SIntArray + 0) << endl;
cout << "Second: " << (SIntArray + 1) << endl;
cout << "Fifth: " << (SIntArray + 4) << endl;
cout << "DIntArray: \n";
cout << "First: " << (DIntArray + 0) << endl;
cout << "Second: " << (DIntArray + 1) << endl;
cout << "Fifth: " << (DIntArray + 4) << endl;

// create an int * temp
int * temp;
// set temp to the begining of SIntArray
temp = &SIntArray[0];
// increment the pointer by 4
*temp += 4;
//  print out the value at that position via temp
cout << "temp contains the address " << temp << " and points to the value " << *temp <<  endl;
// set temp to the begining of DIntArray
temp = &DIntArray[0];
// increment the pointer by 4
*temp += 4;
//  print out the value at that position via temp
cout << "temp contains the address " << temp << " and points to the value " << *temp <<  endl;
// clean up the Dynamic array
delete[] DIntArray;

  return 0;
  }






