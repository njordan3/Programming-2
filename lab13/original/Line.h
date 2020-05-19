/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib.h"
#include "Shape.h"

class Line : public Shape
{
    protected:
        double length;
    public:
        Line(int val = 0);
        ~Line(){LogStart() LogEnd()}
        string ToString();
        void SetLength(double);
};
Line::Line(int val)
{
    LogStart(val);
    SetLength(val);
    shape_type = 1;
    LogEnd(val);
}
string Line::ToString()
{
    LogStart();
    ostringstream temp;
        temp << "Line: \n"
            << "Length: " << length << endl
            << "Area: " << Area() << endl
            <<"Volume: " << Shape::Volume() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
void Line::SetLength(double len)
{
    LogStart(len);
    if(len < 0)
    {
        len = 0;
    }
    length = len;
    LogEnd(len);
}
