#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Computer.h"

int main()
  {
  LoggerSetUpLog("main1.log");

  Computer one;
  cout << one.ToString() << endl;

  Computer two(4,1.6 ,1000,4,"Pentium N3700");


  cout << two.ToString() << endl;


  Computer three( two );


  cout << three.ToString() << endl;


  return 0;
  }
