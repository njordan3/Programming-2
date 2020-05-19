#include "Square.h"

Square::Square()
{
    LogStart();
    
    length = 0;

    LogEnd();
}
Square::Square(double val)
{
    LogStart(val);

    length = val;

    LogEnd(val);
}
Square::~Square()
{
    LogStart();
    LogEnd();
}
void Square::SetLength(double val)
{
    LogStart(val);

    if(val < 0)
    {
        val = 0;
    }
    length = val;

    LogEnd(val);
}
double Square::Area()
{
    LogStart();
    
    double result = length * length;

    LogEndReturning(result);
    return result;   
}
string Square::ToString()
{
    LogStart();
    ostringstream temp;
    temp << "Square: length = " << length << " area = " << Area() << endl;
    LogEndReturning(temp.str());
    return temp.str();
}


