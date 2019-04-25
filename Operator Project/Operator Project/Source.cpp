#include "Rational.h"

using namespace std;

int main() {

	Rational a, b, c;

	cin >> a >> b;

	c = a + b;
	c.ffloat(c);
	
	cout << c << endl;

	system("pause");
	return 0;

}