/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib.h"

class Shape
{
    public:
        Shape();
        ~Shape() {LogStart() LogEnd()}
        double Area();
        double Volume();
        string ToString();
        int shape_type;
};
double Shape::Area()
{
    LogStart();
    LogEndReturning(0);
    return 0;
}
double Shape::Volume()
{
    LogStart();
    LogEndReturning(0);
    return 0;
}
string Shape::ToString()
{
    LogStart();
    ostringstream temp;
        temp << "Shape: \n"
            << "Area: " << Area() << endl
            << "Volume: " << Volume() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
Shape::Shape()
{
    LogStart();

    shape_type = 0;

    LogEnd();
}
