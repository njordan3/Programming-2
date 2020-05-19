/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */

#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Shape.h"



// do not modify this file in any way

int main()
  {
  LoggerSetUpLog("main1.log");


  Shape a;
  cout << a.ToString() << endl;
  return  0;
  }

