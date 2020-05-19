#include <algorithm>
#include "cmpslib.h"

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Rectangular_Prism.h"
#include "Cube.h"


int main()
  {
  LoggerSetUpLog("main1.log");

  Shape* shapearray[6];
  shapearray[0] = new Shape;
  shapearray[1] = new Line(5);
  shapearray[2] = new Square(5);
  shapearray[3] = new Cube(5);
  shapearray[4] = new Rectangle(5,10);
  shapearray[5] = new Rectangular_Prism(5,10,15);
  srand ( unsigned ( std::time(0) ) );
  random_shuffle(shapearray, shapearray+6);

  for (int loop=0;loop < 6;loop++)
    {
	cout << shapearray[loop]->ToString() << endl;
	}

  delete shapearray[0];
  delete shapearray[1];
  delete shapearray[2];
  delete shapearray[3];
  delete shapearray[4];
  delete shapearray[5];

  
  return  0;
  }

