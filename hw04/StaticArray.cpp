#include "StaticArray.h"


StaticArray::StaticArray()
  {
  LogStart();
  // nothing to do

  LogEnd();
  }

StaticArray::~StaticArray()
  {
  LogStart();
  // nothing to do

  LogEnd();

  }

string StaticArray::ToString()
  {
  // completed for you

  LogStart();
  ostringstream temp;
  for (int loop =0; loop<5; loop++)
    {
    temp << "data[" << loop << "] value: " << data[loop] << endl;
    }

  LogEndReturning(temp.str());
  return temp.str();
  }

bool StaticArray::SetValue(string input ,int pos)
  {
      LogStart(input,pos);
     
      bool result = true;
      if(pos < 0 || pos > 4)
      {
          result = false;
      }
      else
      {
        data[pos] = input;
      }

      LogEndReturning(result);
      return result;
  }




