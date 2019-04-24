#include "Rational.h"
using namespace std;


Rational::Rational(int num, int den) {
	_num = num;
	_den = den;
}



int Rational::gcd(int x, int y) {

	if (x % y != 0)
		return gcd(y, x % y);
	else
		return y;

}

Rational Rational::operator + (const Rational &r) {

	_gcd = gcd(_den, r._den);

	lcm = (_den * r._den) / _gcd;

	Rational z(_num * (r._den / _gcd) + r._num * (_den / _gcd), lcm);

	return z;

}

void Rational::ffloat(const Rational &r) {
	ans = (float)r._num / (float)r._den;
}

istream &operator >> (istream &s, Rational &r) {
	cout << "請輸入分子/分母: ";
	s >> r._num >> r._den;
	return s;
}

ostream &operator << (ostream &s, Rational r) {
	s  << r.ans << endl;	
	return s;
}
