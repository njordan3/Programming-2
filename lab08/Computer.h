#include "cmpslib.h"

class Computer
{
    int cores;
    double processor_speed;
    int drive_size;
    int ram;
    string processor_type;
    public:
        Computer();
        Computer(int cores, double processor_speed, int drive_size, int ram, string processor_type);
        Computer(Computer & val);
        ~Computer();
        string ToString();
};



