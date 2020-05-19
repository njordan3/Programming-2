#include "cmpslib.h"

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Rectangular_Prism.h"
#include "Cube.h"


int main()
  {
  LoggerSetUpLog("main1.log");

  Rectangular_Prism f(5,10,15);
  
  cout << f.ToString() << endl;
  return  0;
  }

