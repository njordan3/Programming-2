/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */
#pragma once
#include "cmpslib.h"
#include "Line.h"

class Square : public Line
{
    public:
        Square(int val = 0);
        string ToString();
        double Area();

};
Square::Square(int val)
{
    LogStart(val);
    SetLength(val);
    LogEnd(val);
}
string Square::ToString()
{
    LogStart();
    ostringstream temp;
    temp << "Square: \n"
         << "Length: " << length << endl
         << "Area: " << Area() << endl
         << "Volume: " << Volume() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
double Square::Area()
{
    LogStart();
    double result = length * length;
    LogEndReturning(result);
    return result;
}
