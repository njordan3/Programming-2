/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */
#pragma once
#include "cmpslib.h"
#include "Line.h"

class Rectangle : public Line
{
    protected:
        double width;
    public:
        Rectangle(double val = 0, double val2 = 0);
        void SetWidth(double);
        string ToString();
        double Area();
};
Rectangle::Rectangle(double val, double val2)
{
    LogStart(val,val2);
    SetWidth(val2);
    Line::SetLength(val);
    LogEnd(val,val2);
}
void Rectangle::SetWidth(double w)
{
    LogStart(w);
    if(w < 0)
    {
        w = 0;
    }
    width = w;
    LogEnd(w);
}
string Rectangle::ToString()
{
    LogStart();
    ostringstream temp;
    temp << "Rectangle: \n"
         << "Length: " << length << endl
         << "Width: " << width << endl
         << "Area: " << Area() << endl
         << "Volume: 0" << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
double Rectangle::Area()
{
    LogStart();
    double result = length * width;
    LogEndReturning(result);
    return result;
}


