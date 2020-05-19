#include "cmpslib.h" // all the special functions provided for use in this class

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library



#include "functions.h"

int main()
{
	LoggerSetUpLog("main1.log");
	int iResult;
	char cResult;
	double dResult;
    
    cout << "\nTesting Function1\n";
    int b[9] = { 32, 0, 17, -1, 61, 86, -14, 53, 64};
    int * resultb = &iResult;
    Function1(resultb, b[0], b[1], b[2]); 
    cout << PF(*resultb == b[2]) << endl;
    Function1(resultb, b[3], b[4], b[5]); 
    cout << PF(*resultb == b[4]) << endl;
    Function1(resultb, b[6], b[7], b[8]); 
    cout << PF(*resultb == b[7]) << endl;

    cout << "\nTesting Function2\n";
    char c[9] = { ' ', 'a', 'b', 'A', 'B', 'E', 'k', 'h', 'Z'};
    char * resultc = &cResult;
    Function2(resultc, c[0], c[1], c[2]); 
    cout << PF(*resultc == c[1]) << endl;
    Function2(resultc, c[3], c[4], c[5]); 
    cout << PF(*resultc == c[4]) << endl;
    Function2(resultc, c[6], c[7], c[8]); 
    cout << PF(*resultc == c[7]) << endl;
    
    cout << "\nTesting Function3\n";
    double d[15] = {0.1, -0.5, 13.2, 0.0, 6.1, 64.7, -16.2, 1.8, 16.2, -19.2, 26.2, 75.3, 24.6,-98.1,35.9 };
    double * resultd = &dResult;
    Function3(resultd, d[0], d[1], d[2], d[3], d[4]);
    cout << PF(VeryClose(*resultd, (d[0] + d[1] + d[2] + d[3] + d[4]))) << endl;
    Function3(resultd, d[5], d[6], d[7], d[8], d[9]);
    cout << PF(VeryClose(*resultd, (d[5] + d[6] + d[7] + d[8] + d[9]))) << endl;
    Function3(resultd, d[10], d[11], d[12], d[13], d[14]);
    cout << PF(VeryClose(*resultd, (d[10] + d[11] + d[12] + d[13] + d[14]))) << endl;

    cout << "\nTesting Function4\n";
    double a[9] = { 32.1, 0, 17.4, -1.5, 61.6, -86.1, 14.1, 53.3, 64.8};
    double * aptr = a;
    for(int i = 0; i < 9; i += 3)
    {
        Function4((aptr + i),(aptr + i + 1), (aptr + i + 2)); 
        cout << PF(VeryClose(*(aptr + i), a[i]) && VeryClose(*(aptr + i + 1), a[i + 1]) && VeryClose(*(aptr + i + 2), a[i + 2])) << endl;
    }

    cout << "\nTesting Function5\n";
    double e[9] = { 32.1, 0, 17.4, -1.5, 61.6, -86.1, 14.1, 53.3, 64.8};
    double * eptr = e;
    for(int i = 0; i < 9; i += 3)
    {
        Function5((eptr + i),(eptr + i + 1), (eptr + i + 2)); 
        cout << PF(VeryClose(*(eptr + i), e[i]) && VeryClose(*(eptr + i + 1), e[i + 1]) && VeryClose(*(eptr + i + 2), e[i + 2])) << endl;
    }

    cout << "\nTesting Function6\n";
    char f[3] = { 'a', 'B', 't'};
    cout << PF(Function6(f[0]) == 'A') << endl;
    cout << PF(Function6(f[1]) == 'B') << endl;
    cout << PF(Function6(f[2]) == 'T') << endl;
    
    cout << "\nTesting Function7\n";
    char g[3] = { 'P', 'B', 'n'};
    cout << PF(Function7(g[0]) == 'p') << endl;
    cout << PF(Function7(g[1]) == 'b') << endl;
    cout << PF(Function7(g[2]) == 'n') << endl;
    
    cout << "\nTesting Function8\n";
    char h[3] = { 'a', 'B', 't'};
    char * hptr = h;
    Function8(hptr);
    cout << PF(*hptr == 'A') << endl;
    Function8((hptr + 1));
    cout << PF(*(hptr + 1) == 'B') << endl;
    Function8((hptr + 2));
    cout << PF(*(hptr + 2) == 'T') << endl;
	
    cout << "\nTesting Function9\n";
    char i[3] = { 'P', 'B', 'n'};
    char * iptr = i;
    Function9(iptr);
    cout << PF(*iptr == 'p') << endl;
    Function9((iptr + 1));
    cout << PF(*(iptr + 1) == 'b') << endl;
    Function9((iptr + 2));
    cout << PF(*(iptr + 2) == 'n') << endl;
    
    
    // comparing doubles can be tricky
// instead of   if (dResult ==500.5)
// use the library function VeryClose( double, double)  like so
// if ( VeryClose(dResult,500.5) ) 
 

	return 0;
}

