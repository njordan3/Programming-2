#include "cmpslib.h" // all the special functions provided for this class
struct LOGGER_DATA LGDATA;
// create a global instance of this struct .. needed by logging library



// returns value passed in multiplied by 3

int TimesThree(int val)
  {
  LogStart(val);
  int temp = val*3;
  LogEndReturning(temp);
  return temp;
  }

// returns "Odd" or "Even"

string OddOrEven(int val)
  {
  LogStart(val);
  string temp("Odd");
  if (val %2 ==0)
    {
    temp ="Even";
    }
  LogEndReturning(temp);
  return temp;
  }


int main()
  {
  LoggerSetUpLog("main3.log");
  LogLow("at start of main\n");
  LogLow("Starting a loop of 10 iterations\n");
  int tripple;
  string valueIsEven;
  string valueTrippledIsEven;

  for (int loop=0; loop < 10; loop++)
    {        
    tripple = TimesThree(loop);
    valueIsEven = OddOrEven(loop);
    valueTrippledIsEven = OddOrEven(tripple);
    }
  LogLow("at end of main\n");
  return 0;
  }





