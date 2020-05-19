
#include "cmpslib.h" // all the special functions provided for this class

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library




// put your funtions here

void TripleInt(int & val)
{
	LogStart(val);
	val *=3;
	LogEnd(val);
}
void SmallerInt(int a, int b, int & c)
{
    LogStart(a,b,c);
    
    if(a > b)
    {
        c = b;
    }
    else
    {
        c = a;
    }

    LogEnd(a,b,c);
}
void LargerInt(int a, int b, int & c)
{
    LogStart(a,b,c);

    if(a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }   

    LogEnd(a,b,c);
}
void SwapInt(int & a,int & b)
{
    LogStart(a,b);
    
    int temp1 = a, temp2 = b;
    b = temp1;
    a = temp2;

    LogEnd(a,b);
}

int main()
{
	LoggerSetUpLog("main1.log");
	cout << endl << endl;
	cout <<"Testing TripleInt" << endl;
	int temp=1,c;
	TripleInt(temp);
	cout << PassFail(3 == temp) << endl;

	TripleInt(temp);
	cout << PassFail(9 == temp) << endl;

	TripleInt(temp);
	cout << PassFail(27 == temp) << endl;

	TripleInt(temp);
	cout << PassFail(81 == temp) << endl;

	// continue testing the rest of your functions
    
    cout << "Testing SmallerInt\n";
    SmallerInt(42,54, c);
    cout << PassFail(42 == c) << endl;    
    SmallerInt(1000,999, c);	
    cout << PassFail(999 == c) << endl;    
    SmallerInt(198273,1 , c);	
    cout << PassFail(1 == c) << endl;    
    SmallerInt(47123,47122 , c);	
    cout << PassFail(47122 == c) << endl << endl; 

    cout << "Testing LargerInt\n";
    LargerInt(1, 10, c);
    cout << PassFail(10 == c) << endl;    
    LargerInt(2342, 675, c);
    cout << PassFail(2342 == c) << endl;    
    LargerInt(654, 27, c);
    cout << PassFail(654 == c) << endl;    
    LargerInt(22, 21, c);
    cout << PassFail(22 == c) << endl << endl;  

    cout << "Testing SwapInt\n";
    int a = 14, b = 41;
    SwapInt(a, b);
    cout << PassFail(a == 41 && b == 14) << endl;
    a = 4145;
    b = 1;    
    SwapInt(a, b);
    cout << PassFail(a == 1 && b == 4145) << endl;
    a = 1341231;
    b = 523;    
    SwapInt(a, b);
    cout << PassFail(a == 523 && b == 1341231) << endl;
    a = 1234;
    b = 13;    
    SwapInt(a, b);
    cout << PassFail(a == 13 && b == 1234) << endl;    

	return 0;
}
