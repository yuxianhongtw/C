#include <iostream>

using namespace std;

int gcd(int m, int n) {
	while (n != 0) {
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

void main() {
	int m, n;

	cin >> m >> n;
	cout << "GCD is " << gcd(m, n) << endl;
	cout << "LCM is " << lcm(m, n) << endl;

	system("pause");
}