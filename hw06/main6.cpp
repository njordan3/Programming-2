/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */

#include "cmpslib.h"
struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Rectangular_Prism.h"



// do not modify this file in any way


int main()
  {
  LoggerSetUpLog("main6.log");

  Rectangular_Prism a;
  cout << a.ToString() << endl;
	
  a.SetLength(5);
  a.SetWidth(7);  
  a.SetDepth(8);
  cout << a.ToString() << endl;

  Rectangular_Prism b(6,9,5);
  cout << b.ToString() << endl;
  


  return  0;
  }

