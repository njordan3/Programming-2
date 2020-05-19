#include <iostream>
#include <string.h>

using namespace std;

class CFraction
{
		public:
				// Constructors
				CFraction(void) {_numerator = 0;_denominator = 0;}
				CFraction(int whole_number) {_numerator = whole_number;_denominator = 1;}
				CFraction(int numerator, int denominator) {_numerator = numerator;_denominator = denominator;}


				CFraction(const CFraction & val){_numerator = val._numerator;_denominator = val._denominator;}
				// Destructor
				~CFraction(void) {}

				// Function to access fraction numerator protected member variable
				int GetNumerator() {return _numerator;}

				// Function to access fraction demoninator protected member variable
				int GetDenominator() {return _denominator;}

				void SetNumerator(int numerator) {_numerator = numerator;}

				void SetDenominator(int denominator) {_denominator = denominator;}

				void Invert()
				{
						int temp =_numerator;
						_numerator = _denominator;
						_denominator= temp;
				}

				// Normalize the fraction
				void Normalize() {

						// If both the numerator and the denominator are 0 there's nothing to do
						if (_numerator == 0 && _denominator == 0)
								return;

						// If both the numerator and denominator are negative they cancel out so make them both positive
						// If only the denominator is negative, move the negative sign to the numerator
						if ((_numerator < 0 && _denominator < 0) || _denominator < 0) {

								_denominator *= -1;
								_numerator *= -1;

						}

						// We set this flag if the numerator was negative
						bool was_negative = false;

						// If the numerator was negative multiply it by -1 to simplify reducing
						// and set the flag so we can put the negative sign back after we are done
						if (_numerator < 0) {

								was_negative = true;

								_numerator *= -1;

						}

						// The maximum divisor will be the smaller of the numerator and denominator.
						// Set max_divisor to the smaller one
						int max_divisor = (_numerator < _denominator) ? _numerator : _denominator;

						// This variable keeps track of the highest divisor we find
						int divisor = 0;

						// Loop through all possible divisors
						for(int i = 1; i <= max_divisor; i++) {

								// If the divisor will go into both the numerator and denominator evenly save it
								if ((_numerator % i == 0) && (_denominator % i == 0))
										divisor = i;

						}

						// If we found a divisor divisor will be non-zero, so we use it to reduce
						if (divisor) {

								_numerator /= divisor;
								_denominator /= divisor;

						}

						// If the fraction was negative we need to restore the negative sign
						if (was_negative)
								_numerator *= -1;

				}

				// Overloaded iostream << operator
				//
				// When the << operator is called with a CFraction on the right our overloaded function is called. We
				// are passed a reference to the stream and the CFraction to the right. We are free to output to the
				// stream anthing we want as a result.
				//
				// We return the ostream& so that we can put multiple << operations on a single line

friend				ostream & operator << (ostream& os, CFraction fraction) {

						// Output the fraction to the stream in the format n/d
						os << fraction.GetNumerator();
						os << '/';
						os << fraction.GetDenominator();

						return os;

				}

				// Overloaded iostream >> operator
				//
				// I tried to write this so it is easy to understand.
				//
				// This will be called whenever the >> operator is used with a CFraction object to the right of it.
				// What happens is the system passes a reference to the stream to the left of the >>, and also
				// a reference to the CFraction object. At this point you are responsbile for accepting and parsing input for
				// the stream passed to you.
				//
				// We return the istream& so that we can put multiple >> operations on a single line

friend				istream & operator >> (istream& is, CFraction& fraction) {
						cout <<"Enter Numerator: ";
						cin >> fraction._numerator;
						cout <<"Enter Denominator: ";
						cin >> fraction._denominator;

						return is;
				}

				CFraction& operator=(const CFraction &rhs)
				{
						_numerator= rhs._numerator;
						_denominator= rhs._denominator;
						return *this; 
				}

				CFraction& operator+=(const CFraction &rhs)
				{
						CFraction temp = (*this);
						temp. SetDenominator( _denominator * rhs._denominator);
						temp.SetNumerator((_numerator * rhs._denominator) + (rhs._numerator * _denominator ) );
						temp. Normalize();
						*this = temp;
						return * this;
				}

				CFraction& operator-=(const CFraction &rhs)
				{
						CFraction temp = (*this);
						temp. SetDenominator( _denominator * rhs._denominator);
						temp.SetNumerator((_numerator * rhs._denominator) - (rhs._numerator * _denominator ) );
						temp. Normalize();
						*this = temp;
						return * this;
				}

				const CFraction operator+(const CFraction &rhs) const
				{
						CFraction result = *this; // Make a copy of myself.
						result += rhs; // Use += to add other to the copy.
						return result; // All done!
				}

				const CFraction operator-(const CFraction &rhs) const
				{
						CFraction result = *this; // Make a copy of myself.
						result -= rhs; // Use -=
						return result; // All done!
				}

				CFraction& operator*=(const CFraction &rhs)
				{
						CFraction temp;
						temp. SetDenominator( _denominator * rhs._denominator);
						temp.SetNumerator(_numerator * rhs._numerator);
						temp. Normalize();
						*this = temp;
						return * this;
				}

				const CFraction operator*(const CFraction &rhs) const
				{
						CFraction result = *this; // Make a copy of myself.
						result *= rhs; // Use *=
						return result; // All done!
				}

				CFraction& operator/=(const CFraction &rhs)
				{
						// to divide invert and multiply
						CFraction temp = rhs;
						temp.Invert();
						(*this) *= temp;
						return * this;
				}

				const CFraction operator/(const CFraction &rhs) const
				{
						CFraction result = *this; // Make a copy of myself.
						result /= rhs; // Use *=
						return result; // All done!
				}



				bool operator!=(const CFraction &rhs) const
				{
						CFraction temp1 = (*this);
						CFraction temp2 = rhs;
						temp1.Normalize();
						temp2.Normalize();
						return (! (temp1._numerator ==temp2._numerator)
										&& (temp1._denominator == temp2._denominator) );
				}

				bool operator==(const CFraction &rhs) const
				{
						CFraction temp1 = (*this);
						CFraction temp2 = rhs;
						temp1.Normalize();
						temp2.Normalize();
						return ( (temp1._numerator ==temp2._numerator)
										&& (temp1._denominator == temp2._denominator) );
				}


				long double AsLongDouble()
				{
						long double temp = _numerator;
						temp /= _denominator;
						return temp;
				}

				bool operator < (CFraction &rhs)
				{


						return ( (this->GetNumerator() * rhs.GetDenominator())  < (this->GetDenominator() *rhs.GetNumerator()));
				} 

				bool operator > (CFraction &rhs)
				{
						return ((this->GetNumerator() * rhs.GetDenominator())  > (this->GetDenominator() *rhs.GetNumerator()));
				} 


		private:
				// Variables to hold fraction
				int _numerator;
				int _denominator;
};







