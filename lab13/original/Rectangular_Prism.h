/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib.h"
#include "Rectangle.h"

class Rectangular_Prism : public Rectangle
{
    double depth;
    public:
    Rectangular_Prism(double len = 0, double wid = 0, double dep = 0);
    ~Rectangular_Prism() {LogStart() LogEnd()}
    string ToString();
    void SetDepth(double);
    double Area();
    double Volume();
};
Rectangular_Prism::Rectangular_Prism(double len, double wid, double dep)
{
    LogStart(len,wid,dep);
    SetLength(len);
    SetWidth(wid);
    SetDepth(dep);   
    shape_type = 5;
    LogEnd(len,wid,dep);
}
string Rectangular_Prism::ToString()
{
    LogStart();
    ostringstream temp;
        temp << "Rectangular_Prism: \n"
            << "Length: " << length << endl
            << "Width: " << width << endl
            << "Depth: " << depth << endl
            << "Area: " << Area() << endl
            << "Volume: " << Volume() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}
void Rectangular_Prism::SetDepth(double dep)
{
    LogStart(dep);
    if(dep < 0)
    {
        dep = 0;
    }
    depth = dep;
    LogEnd(dep);   
}
double Rectangular_Prism::Area()
{
    LogStart();
    double result = 2*(length*width) + 2*(length*depth) + 2*(width*depth); 
    LogEndReturning(result);
    return result;
}
double Rectangular_Prism::Volume()
{
    LogStart();
    double result = depth * Rectangle::Area(); 
    LogEndReturning(result);
    return result;
}

