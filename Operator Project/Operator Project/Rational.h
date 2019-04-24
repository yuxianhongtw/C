#include <iostream>
using namespace std;

class Rational{
public:
	Rational(int num = 0, int den = 1);

	Rational operator + (const Rational &r);

	friend istream &operator >> (istream &s, Rational &r);
	friend ostream &operator << (ostream &s, Rational r);

	void ffloat(const Rational &r);
private:
	int _num;
	int _den;
	int _gcd;
	int lcm;
	int gcd(int x, int y);

	float ans;

};