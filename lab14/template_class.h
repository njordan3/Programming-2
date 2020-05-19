#include "cmpslib.h"

template <class T>
class Templated_Class
{
    private:
        T data;
    public:
        T getData()
        {
            LogStart();
            LogEndReturning(data);
            return data;
        }
        void setData(T val)
        {
            LogStart(val);
            data = val;
            LogEnd(val);
        }
        friend ostream& operator << (ostream& os, Templated_Class& s)
        {
            LogStart(os,s);
            os << "  sizeof (data) = " << sizeof(s.data) << endl
                << "  data is of type " << GetClassName(s.data) << endl
                << "  data contains: " << s.data << endl;
            LogEndReturning(os);
            return os;
        }

};

