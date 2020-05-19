#include <algorithm>
#include "cmpslib.h"

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library

#include "Rectangular_Prism.h"
#include "Cube.h"


int main()
{
    LoggerSetUpLog("main5.log");

    Shape* shapearray[6];
    shapearray[0] = new Shape;
    shapearray[1] = new Line(5);
    shapearray[2] = new Square(5);
    shapearray[3] = new Cube(5);
    shapearray[4] = new Rectangle(5,10);
    shapearray[5] = new Rectangular_Prism(5,10,15);

    random_shuffle(shapearray, shapearray+6);

    for (int loop=0;loop < 6;loop++)
    {
        /* 
           what type is  shapearray[loop] 
           it could be any of the 6 disparate types 
           */
        if(shapearray[loop]->shape_type == 0)
            cout << ((Shape*)shapearray[loop])->ToString() << endl;
        if(shapearray[loop]->shape_type == 1)
            cout << ((Line*)shapearray[loop])->ToString() << endl;
        if(shapearray[loop]->shape_type == 2)
            cout << ((Square*)shapearray[loop])->ToString() << endl;
        if(shapearray[loop]->shape_type == 3)
            cout << ((Cube*)shapearray[loop])->ToString() << endl;
        if(shapearray[loop]->shape_type == 4)
            cout << ((Rectangle*)shapearray[loop])->ToString() << endl;
        if(shapearray[loop]->shape_type == 5)
            cout << ((Rectangular_Prism*)shapearray[loop])->ToString() << endl;
    }

    for(int loop = 0; loop < 6; loop++)
    {
        if(shapearray[loop]->shape_type == 0)
            delete shapearray[loop];
        if(shapearray[loop]->shape_type == 1)
            delete ((Line*)shapearray[loop]);
        if(shapearray[loop]->shape_type == 2)
            delete ((Square*)shapearray[loop]);
        if(shapearray[loop]->shape_type == 3)
            delete ((Cube*)shapearray[loop]);
        if(shapearray[loop]->shape_type == 4)
            delete ((Rectangle*)shapearray[loop]);
        if(shapearray[loop]->shape_type == 5)
            delete ((Rectangular_Prism*)shapearray[loop]);
    }
    //delete shapearray[0];
    //delete shapearray[1];
    //delete shapearray[2];
    //delete shapearray[3];
    //delete shapearray[4];
    //delete shapearray[5];


    return  0;
}

