#include "cmpslib.h"

class Computer
{
    int cores;
    double processor_speed;
    int drive_size;
    int ram;
    string processor_type;
    static int count;
    public:
        Computer();
        Computer(int cores, double processor_speed, int drive_size, int ram, string processor_type);
        Computer(Computer & val);
        ~Computer();
        string ToString();
        static int GetCount();
        friend bool Greater(const Computer &, const Computer &);
        friend bool Less(const Computer &, const Computer &);
        friend bool Equal(const Computer &, const Computer &);
};



