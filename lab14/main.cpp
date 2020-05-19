#include "cmpslib.h"
struct LOGGER_DATA LGDATA;



#include "template_class.h"


int main()
{
    LoggerSetUpLog("main.log");
    cout << "Testing with type int\n";
    Templated_Class<int> a;
    cout << "a.setData(99)\n";
    a.setData(99);
    cout << "a.getData() returns: " << a.getData() << endl;
    cout << "cout << a\n";
    cout << a;

    cout << "Testing with type double\n";
    Templated_Class<double> b;
    cout << "b.setData(99.99)\n";
    b.setData(99.99);
    cout << "b.getData() returns: " << b.getData() << endl;
    cout << "cout << b\n";
    cout << b;
    
    cout << "Testing with type string\n";
    Templated_Class<string> c;
    cout << "c.setData(monkey)\n";
    c.setData("monkey");
    cout << "c.getData() returns: " << c.getData() << endl;
    cout << "cout << c\n";
    cout << c;


////LoggerClose();

return 0;
}
