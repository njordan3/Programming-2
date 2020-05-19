#include <iostream>
using namespace std;
#include "cmpslib.h"
struct LOGGER_DATA LGDATA;


#define ELEMTYPE int
#define QUEUESIZE 4
#include "Queue.h"

int main()
{
	LoggerSetUpLog("main2.log");
	Queue Queue1;
	cout << Queue1.ToString() << endl;
	int temp=5;


	temp=5;
	cout << "enQueue("<<temp<<")   :"    <<  PF(true == Queue1.enQueue(temp))  << endl;
	temp=10;
	cout << "enQueue("<<temp<<")   :"    <<  PF(true == Queue1.enQueue(temp))  << endl;
	temp=15;
	cout << "enQueue("<<temp<<")   :"    <<  PF(true == Queue1.enQueue(temp))  << endl;
	temp=20;
	cout << "enQueue("<<temp<<")   :"    <<  PF(true == Queue1.enQueue(temp))  << endl;
	cout << Queue1.ToString() << endl;
	cout << endl << "Should not allow any more inserts" << endl;

	temp=25;
	cout << "enQueue("<<temp<<")   :"    <<  PF(false == Queue1.enQueue(temp))  << endl;
	temp=30;
	cout << "enQueue("<<temp<<")   :"    <<  PF(false == Queue1.enQueue(temp))  << endl;
	temp=35;
	cout << "enQueue("<<temp<<")   :"    <<  PF(false == Queue1.enQueue(temp))  << endl;
	temp=40;
	cout << "enQueue("<<temp<<")   :"    <<  PF(false == Queue1.enQueue(temp))  << endl;
	cout << Queue1.ToString() << endl;


	return 0;
}


