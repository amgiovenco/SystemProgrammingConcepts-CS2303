#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::istream;

int gcd(int a, int b);

class Rational {
	public:
		Rational();
		Rational(const int num, const int denom);
		Rational(const int wholeNum);
		Rational(const Rational &a);

		void simplify(int& num, int& denom);
		
		int getNumerator();
		int getDenominator();
		Rational operator+(const Rational &a) const;
		Rational operator-(const Rational &a);
		Rational operator*(const Rational &a);
		Rational operator/(const Rational &a);
		
		bool operator==(const Rational &a);
		bool operator!=(const Rational &a);

		bool operator<(const Rational &a);
		bool operator>(const Rational &a);
		bool operator>=(const Rational &a);
		bool operator<=(const Rational &a);

		friend ostream& operator<<(ostream& out, const Rational &a);
		friend istream& operator>>(istream& in, Rational &a);
		
	private:
		int num;
		int denom;
};