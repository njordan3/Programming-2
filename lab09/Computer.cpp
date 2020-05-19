#include "cmpslib.h"
#include "Computer.h"


int Computer::count = 0;
Computer::Computer()
{
    LogStart();
    
    cores = 0;
    processor_speed = 0;
    drive_size = 0;
    ram = 0;
    processor_type = "none";
    count++;

    LogEnd();
}
Computer::Computer(int c, double ps, int ds, int r, string pt)
{
    LogStart(c,ps,ds,r,pt);

    cores = c;
    processor_speed = ps;
    drive_size = ds;
    ram = r;
    processor_type = pt;   
    count++;

    LogEnd(c,ps,ds,r,pt);
}
Computer::Computer(Computer & val)
{
    LogStart(val);

    cores = val.cores;
    processor_speed = val.processor_speed;
    drive_size = val.drive_size;
    ram = val.ram;
    processor_type = val.processor_type;
    count++;

    LogEnd(val);
}
Computer::~Computer()
{
    LogStart();
    
    count--;

    LogEnd();
}
string Computer::ToString()
{
    LogStart();

    ostringstream temp;
    temp << processor_speed << " Ghz " << processor_type << " " << cores << " Cores\n";
    temp << drive_size << " Gb disk\n";
    temp << ram << " Gb ram\n";

    LogEndReturning(temp.str());
    return temp.str();
}
int Computer::GetCount()
{
    LogStart();
    LogEndReturning(count);
    return count;
}
bool Greater(const Computer & a, const Computer & b)
{
    LogStart(a,b);

    bool result = false;
    if((a.cores*a.processor_speed)>(b.cores*b.processor_speed))
    {
        result = true;
    }

    LogEndReturning(result);
    return result;
}
bool Less(const Computer & a, const Computer & b)
{
    LogStart(a,b);

    bool result = false;
    if((a.cores*a.processor_speed)<(b.cores*b.processor_speed))
    {
        result = true;
    }

    LogEndReturning(result);
    return result;
}
bool Equal(const Computer & a, const Computer & b)
{
    LogStart(a,b);

    bool result = false;
    if((a.cores*a.processor_speed)==(b.cores*b.processor_speed))
    {
        result = true;
    }

    LogEndReturning(result);
    return result;
}
