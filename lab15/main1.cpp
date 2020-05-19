#include <iostream>
using namespace std;
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#define ELEMTYPE int
#define QUEUESIZE 4
#include "Queue.h"

int main()
{
	LoggerSetUpLog("main1.log");
	Queue Queue1;

	try
	{
		// test that peekFront will throw an exception
		Queue1.peekFront();
		cout << "Fail:"<<endl;


	}
	catch (const char * val)
	{
		cout <<"Pass:"<<endl;
        cout <<"Exception:" << val << endl;
	}
	return 0;
}


