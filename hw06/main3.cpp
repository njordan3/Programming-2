/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */

#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Square.h"



// do not modify this file in any way


int main()
  {
  LoggerSetUpLog("main3.log");

  Square a;
  cout << a.ToString() << endl;
 
  a.SetLength(5); 
  cout << a.ToString() << endl;
 
  Square b(10);
  cout << b.ToString() << endl;
  


  return  0;
  }

