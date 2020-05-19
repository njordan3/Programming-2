
#include "cmpslib.h" // all the special functions provided for this class

struct LOGGER_DATA LGDATA; // create a global instance of this struct .. needed by logging library


#include "functions.h"


int main()
{
      LoggerSetUpLog("main1.log");
// continue testing the rest of your functions
      int a = 1, *pointer_a = &a;
      cout << "Testing TripleInt_PBV\n";
      cout << PF(TripleInt_PBV(3) == 9) << endl;
      cout << PF(TripleInt_PBV(5) == 15) << endl;
      cout << PF(TripleInt_PBV(8) == 24) << endl;
      cout << PF(TripleInt_PBV(9) == 27) << endl;
      cout << PF(TripleInt_PBV(1) == 3) << endl;
      cout << "Testing TripleInt_PBR\n";
      TripleInt_PBR(a);
      cout << PF(a == 3) << endl;
      TripleInt_PBR(a);
      cout << PF(a == 9) << endl;
      TripleInt_PBR(a);
      cout << PF(a == 27) << endl;
      TripleInt_PBR(a);
      cout << PF(a == 81) << endl;
      TripleInt_PBR(a);
      cout << PF(a == 243) << endl;
      cout << "Testing TripleInt_PBP\n";
      TripleInt_PBP(pointer_a);
      cout << PF(a == 729) << endl;
      TripleInt_PBP(pointer_a);
      cout << PF(a == 2187) << endl;
      TripleInt_PBP(pointer_a);
      cout << PF(a == 6561) << endl;
      TripleInt_PBP(pointer_a);
      cout << PF(a == 19683) << endl;
      TripleInt_PBP(pointer_a);
      cout << PF(a == 59049) << endl;
  
      int b = 44, c = 65, d = 31, e = 75,f = 5, g = 76, h = 12, i = 51, j = 8, k = 90;
      int * pointer_d = &d, *pointer_e = &e;
      int * pointer_f = &f, *pointer_g = &g;
      int * pointer_h = &h, *pointer_i = &i;
      int * pointer_j = &j, *pointer_k = &k;
      int * pointer_b = &b, *pointer_c = &c;
      cout << "Testing SwapInts_PBR\n";
      SwapInts_PBR(b,c);
      cout << PF(b == 65 && c == 44) << endl;
      SwapInts_PBR(d,e);
      cout << PF(d == 75 && e == 31) << endl;
      SwapInts_PBR(f,g);
      cout << PF(f == 76 && g == 5) << endl;
      SwapInts_PBR(h,i);
      cout << PF(h == 51 && i == 12) << endl;
      SwapInts_PBR(j,k);
      cout << PF(j == 90 && k == 8) << endl;
      cout << "Testing SwapInts_PBP\n";
      SwapInts_PBP(pointer_d, pointer_e);
      cout << PF(*pointer_d == 31 && *pointer_e == 75) << endl;
      SwapInts_PBP(pointer_b, pointer_c);
      cout << PF(*pointer_b == 44 && *pointer_c == 65) << endl;
      SwapInts_PBP(pointer_f, pointer_g);
      cout << PF(*pointer_f == 5 && *pointer_g == 76) << endl;
      SwapInts_PBP(pointer_h, pointer_i);
      cout << PF(*pointer_h == 12 && *pointer_i == 51) << endl;
      SwapInts_PBP(pointer_j, pointer_k);
      cout << PF(*pointer_j == 8 && *pointer_k == 90) << endl;
        
      int one = 41, two = 92, three = 63, four = 24, five = 1, six = 8, seven = 6, eight = 16, nine = 75, ten = 67;
      int result, * pointer_result = &result;
      cout << "Testing IsLarger_PBV\n";
      cout << PF(IsLarger_PBV(one,two) == 92) << endl;
      cout << PF(IsLarger_PBV(three, four) == 63) << endl;
      cout << PF(IsLarger_PBV(five, six) == 8) << endl;
      cout << PF(IsLarger_PBV(seven, eight) == 16) << endl;
      cout << PF(IsLarger_PBV(nine, ten) == 75) << endl;
      cout << "Testing IsLarger_PBR\n";
      IsLarger_PBR(three,four,result);
      cout << PF(result == 63) << endl;
      IsLarger_PBR(one,two,result);
      cout << PF(result == 92) << endl;
      IsLarger_PBR(five,six,result);
      cout << PF(result == 8) << endl;
      IsLarger_PBR(seven,eight,result);
      cout << PF(result == 16) << endl;
      IsLarger_PBR(nine,ten,result);
      cout << PF(result == 75) << endl;
      cout << "Testing IsLarger_PBP\n";
      IsLarger_PBP(five,six,pointer_result);
      cout << PF(*pointer_result == 8) << endl;
      IsLarger_PBP(three,four,pointer_result);
      cout << PF(*pointer_result == 63) << endl;
      IsLarger_PBP(one,two,pointer_result);
      cout << PF(*pointer_result == 92) << endl;
      IsLarger_PBP(seven,eight,pointer_result);
      cout << PF(*pointer_result == 16) << endl;
      IsLarger_PBP(nine,ten,pointer_result);
      cout << PF(*pointer_result == 75) << endl;



  return 0;
}
