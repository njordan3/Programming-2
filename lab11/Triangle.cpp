#include "Triangle.h"

Triangle::Triangle()
{
    LogStart();
    SetHeight(0);
    LogEnd();
}
Triangle::Triangle(double l, double h)
{
    LogStart(l,h);

    SetHeight(h);
    SetLength(l);

    LogEnd(l,h);
}
Triangle::~Triangle()
{
    LogStart();
    LogEnd();
}
void Triangle::SetHeight(double h)
{
    LogStart(h);

    if(h < 0)
    {
        h = 0;   
    }
    height = h;

    LogEnd(h);
}
double Triangle::Area()
{
    LogStart();

    double result = ((length * height) * 0.5);   

    LogEndReturning(result);
    return result;
}
string Triangle::ToString()
{
    LogStart();

    ostringstream temp;
    temp << "Triangle: length = " << length << " height = " << height
         << " area = " << Area() << endl;

    LogEndReturning(temp.str());
    return temp.str();
}



