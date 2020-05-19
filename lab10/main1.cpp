#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library



#include "DynamicArray.h"


int main()
  {
  LoggerSetUpLog("main1.log");
  /*
  test all of the functions of your Dymamic array
  */


  DynamicArray  arr, arr2, arr3,arr4;
  cout << "create DynamicArray objects  arr, arr2, arr3,arr4 " << endl;


  cout << "set arr to contain some values \n";

  arr.SetValue("Homer",0);
  arr.SetValue("Marge",1);
  arr.SetValue("Bart",2);
  arr.SetValue("Lisa",3);
  arr.SetValue("Maggie",4);
  arr.SetValue("Apu",5);
  arr.SetValue("Manjula",0);

  cout << "\n\nPrint them all:\n";
  cout << "arr.ToString() returns " << endl << arr.ToString() << endl ;
  cout << "arr2.ToString() returns " << endl << arr2.ToString() << endl ;
  cout << "arr3.ToString() returns " << endl << arr3.ToString() << endl ;
  cout << "arr4.ToString() returns " << endl << arr4.ToString() << endl ;

  cout << "\n\n";
  cout << "arr2 = arr; // test assignment operator " << endl;

  cout << "arr3 = arr; // test assignment operator " << endl;


  arr2 = arr;
  arr3 = arr;

  cout << "\n\nPrint them all:\n";
  cout << "arr.ToString() returns " << endl << arr.ToString() << endl ;
  cout << "arr2.ToString() returns " << endl << arr2.ToString() << endl ;
  cout << "arr3.ToString() returns " << endl << arr3.ToString() << endl ;
  cout << "arr4.ToString() returns " << endl << arr4.ToString() << endl ;


  cout << "change some of the values in arr" << endl;

  arr.SetValue("Otto",0);
  arr.SetValue("Krusty",1);
  arr.SetValue("SuperNintendo Chalmers",2);
  arr.SetValue("Groundskeeper Willy",3);


  cout << "\n\nPrint them all:\n";
  cout << "arr.ToString() returns " << endl << arr.ToString() << endl ;
  cout << "arr2.ToString() returns " << endl << arr2.ToString() << endl ;
  cout << "arr3.ToString() returns " << endl << arr3.ToString() << endl ;
  cout << "arr4.ToString() returns " << endl << arr4.ToString() << endl ;


  cout << "arr4 = arr + arr2; // test addition  operator " << endl;


  arr4 = arr + arr2;

  cout << "\n\nPrint them all:\n";
  cout << "arr.ToString() returns " << endl << arr.ToString() << endl ;
  cout << "arr2.ToString() returns " << endl << arr2.ToString() << endl ;
  cout << "arr3.ToString() returns " << endl << arr3.ToString() << endl ;
  cout << "arr4.ToString() returns " << endl << arr4.ToString() << endl ;

  cout << "test the == operator\n";


  cout << "(arr == arr) evalutates to " << boolalpha << (arr == arr) << endl;
  cout << "(arr == arr2) evalutates to " << boolalpha << (arr == arr2) << endl;
  cout << "(arr == arr3) evalutates to " << boolalpha << (arr == arr3) << endl;
  cout << "(arr == arr4) evalutates to " << boolalpha << (arr == arr4) << endl;
  cout << "(arr2 == arr3) evalutates to " << boolalpha << (arr2 == arr3) << endl;
  cout << endl;

  cout << "(arr == arr) evalutates to " << boolalpha << (arr == arr) << endl;
  cout << "(arr2 == arr) evalutates to " << boolalpha << (arr2 == arr) << endl;
  cout << "(arr3 == arr) evalutates to " << boolalpha << (arr3 == arr) << endl;
  cout << "(arr4 == arr) evalutates to " << boolalpha << (arr4 == arr) << endl;
  cout << "(arr3 == arr2) evalutates to " << boolalpha << (arr3 == arr2) << endl;
  return 0;
  }

