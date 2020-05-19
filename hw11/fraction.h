 #include <iostream>
#include <string.h>

 using namespace std;

 class CFraction
 {
 public:
 // Constructors
 CFraction(void);
 CFraction(int whole_number);
 CFraction(int numerator, int denominator);
 CFraction(const CFraction & );
 // Destructor
 ~CFraction(void);

 // Public functions to access private data members
 int GetNumerator();
 int GetDenominator();
 void SetNumerator(int numerator);
 void SetDenominator(int denominator);
 long double AsLongDouble();

 // Public functions to manipulate fraction
 void Normalize();
 void Invert();

 // Operator Overloading
 friend ostream & operator << (ostream& os, CFraction fraction);
 friend istream & operator >> (istream& is, CFraction& fraction);

 CFraction& operator= (const CFraction &rhs);
 CFraction& operator+= (const CFraction &rhs);
 const CFraction operator+ (const CFraction &rhs) const;
 CFraction& operator-= (const CFraction &rhs);
 const CFraction operator- (const CFraction &rhs) const;
 CFraction& operator*= (const CFraction &rhs);
 const CFraction operator* (const CFraction &rhs) const;
 CFraction& operator/= (const CFraction &rhs);
 const CFraction operator/ (const CFraction &rhs) const;
 bool operator== (const CFraction &rhs) const;
 bool operator!= (const CFraction &rhs) const;



 bool operator < (CFraction &rhs);
 bool operator > (CFraction &rhs);
 
 private:
 // Variables to hold fraction
 int _numerator;
 int _denominator;
 };






