/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */
#pragma once
#include "cmpslib.h"
#include "Square.h"

class Cube : public Square
{
    public:
        Cube(int val = 0);
        string ToString();
        double Area();
        double Volume();
};
Cube::Cube(int val)
{
    LogStart(val);
    SetLength(val);
    shape_type = 3;
    LogEnd(val);
}
string Cube::ToString()
{
    LogStart();
    ostringstream temp;
    temp << "Cube: \n"
         << "Length: " << length << endl
         << "Area: " << Area() << endl
         << "Volume: " << Volume() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
double Cube::Area()
{   
    LogStart();
    double result = 6 * Square::Area();
    LogEndReturning(result);
    return result;
}
double Cube::Volume()
{
    LogStart();
    double result = length * Square::Area();
    LogEndReturning(result);
    return result;
}

