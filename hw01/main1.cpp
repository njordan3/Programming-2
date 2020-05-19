#include "cmpslib.h" // all the special functions provided for use in this class

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library



#include "functions.h"

int main()
{
	LoggerSetUpLog("main1.log");
	int iResult;
	char cResult;
	double dResult;

// Test MiddleValue_PBV
	cout << "\nTesting Function MiddleValue_PBV\nIs 0 the middle value of -10,0,10 ? :";
 
	iResult = Function1(-10,0,10);
    if (iResult ==0) 
		cout << "Pass" << endl;
	else 
		cout << "Fail" << endl;

    // the library ( in cmpslib.h ) function PF has a bool parmmeter and returns the c string "Pass" or "Fail" 

    // so this is the same but shorter

	cout << "\nTesting Function MiddleValue_PBV\nIs the -10 the  middle value of -10,-50,10 ? :";
	iResult = Function1(-10,-50,10);
	cout << PF( iResult == -10) << endl;

	cout << "\nTesting Function MiddleValue_PBV\nIs the -50 the  middle value of -10,-50,-110 ? :";
	iResult = Function1(-10,-50,-110);
	cout << PF(iResult == -50) << endl;

	cout << "\nTesting Function MiddleValue_PBV\nIs the 160 the  middle value of 175,150,160 ? :";
	iResult = Function1(175,150,160);
	cout << PF( iResult == 160) << endl;
    
//Test MiddleChar_PBV
    cout << "\nTesting Function MiddleChar_PBV\n";
    
    cResult = MiddleChar_PBV('s','g','j');
    cout << PassFail('j' == cResult) << endl;
    
    cResult = MiddleChar_PBV('c','a','z');
    cout << PassFail('c' == cResult) << endl;
    
    cResult = MiddleChar_PBV('q','k','s');
    cout << PassFail('q' == cResult) << endl;
    
//Test MiddleValue_PBR
    cout << "\nTesting Function MiddleValue_PBR\n";
    
    MiddleValue_PBR(iResult, 22, 45, -1);
    cout << PassFail(22 == iResult) << endl;
    
    MiddleValue_PBR(iResult, -100, 0, 24);
    cout << PassFail(0 == iResult) << endl;
    
    MiddleValue_PBR(iResult, 1000, 224, 542);
    cout << PassFail(542 == iResult) << endl;
    
//Test MiddleChar_PBR
    cout << "\nTesting Function MiddleChar_PBR\n";
    
    MiddleChar_PBR(cResult,'k','p','v');
    cout << PassFail('p' == cResult) << endl;    
    
    MiddleChar_PBR(cResult,'d','a','e');
    cout << PassFail('d' == cResult) << endl;    
    
    MiddleChar_PBR(cResult,'x','z','t');
    cout << PassFail('x' == cResult) << endl;    
    
//Test GetSum_PBV
    cout << "\nTesting Function GetSum_PBV\n";
    
    dResult = GetSum_PBV(2.3,43.1,32.5,100.5,1.1);
    cout << PassFail(VeryClose(dResult,179.5)) << endl;
    
    dResult = GetSum_PBV(47.9,43.1,123.5,101.7,1.5);
    cout << PassFail(VeryClose(dResult,317.7)) << endl;
    
    dResult = GetSum_PBV(3.4,42.1,343.4,125.7,2.7);
    cout << PassFail(VeryClose(dResult,517.3)) << endl;
    
//Test GetSum_PBR
    cout << "\nTesting Function GetSum_PBR\n";
    
    GetSum_PBR(dResult,12.1,51.1,62.1,34.6,643.2);
    cout << PassFail(VeryClose(dResult,803.1)) << endl;
    
    GetSum_PBR(dResult,1.3,54.6,63.7,39.9,6.2);
    cout << PassFail(VeryClose(dResult,165.7)) << endl;
    
    GetSum_PBR(dResult,2.1,5.1,69.7,45.6,69.8);
    cout << PassFail(VeryClose(dResult,192.3)) << endl;
    
//Test SortInAscending
    cout << "\nTesting Function SortInAscending\n";
    
    double a = 123.1, b = 32.4, c = 51.7;
    SortInAscending(a,b,c);
    cout << PassFail(c > b && b > a) << endl;
    
    a = 3, b = 2, c = 1;
    SortInAscending(a,b,c);
    cout << PassFail(c > b && b > a) << endl;
    
    a = 54.2, b = 65.1, c = 55.7;
    SortInAscending(a,b,c);
    cout << PassFail(c > b && b > a) << endl;
    
//Test SortInDescending
    cout << "\nTesting Function SortInDescending\n";
    
    a = 54.2, b = 57.3, c = 86.1;
    SortInDescending(a,b,c);
    cout << PassFail(a > b && b > c) << endl;
    
    a = 87.3, b = 74.2, c = 17.3;
    SortInDescending(a,b,c);
    cout << PassFail(a > b && b > c) << endl;
    
    a = 62.1, b = 15.7, c = 53.2;
    SortInDescending(a,b,c);
    cout << PassFail(a > b && b > c) << endl;

// comparing doubles can be tricky
// instead of   if (dResult ==500.5)
// use the library function VeryClose( double, double)  like so
// if ( VeryClose(dResult,500.5) ) 
 

	return 0;
}

