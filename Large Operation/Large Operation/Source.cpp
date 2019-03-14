#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string Opera, Value1, Value2, Ans, Real_Ans, Value_1, Value_2;
int Value1_len, Value2_len, k;

void change(string &num, int num_len) {
	int a;
	for (int i = 0; i < num_len / 2; i++) {
		a = num[i];
		num[i] = num[num_len - i - 1];
		num[num_len - i - 1] = a;
	}
}

void add(string num1, string num2, string &ans, int num1_len, int num2_len) {
	change(num1, num1_len);
	change(num2, num2_len);
	stringstream x, y, z;
	int a, b, s, c = 0;

	for (int i = 0; i < num1_len; i++) {
		x << num1[i];
		x >> a;
		y << num2[i];
		y >> b;
		s = a + b + c;
		c = 0;
		if (s > 9) {
			c = 1;
			s = s % 10;
		}
		z << s;
		z >> ans[i];
		ans = ans + ans[i];
		if (c == 1 && i == num1_len - 1) {
			ans = ans + "1";
		}
		x.clear();
		y.clear();
		z.clear();
	}
	c = 0;
}

void sub(string num1, string num2, string &ans, int num1_len, int num2_len) {
	change(num1, num1_len);
	change(num2, num2_len);
	stringstream x, y, z;
	string anss;
	int a, b, s, c = 0, n;

	for (int i = 0; i < num1_len; i++) {
		x << num1[i];
		x >> a;
		y << num2[i];
		y >> b;
		s = a - b - c;
		c = 0;
		if (s < 0) {
			c = 1;
			s = s + 10;
		}
		z << s;
		z >> anss[i];
		anss = anss + anss[i];
		x.clear();
		y.clear();
		z.clear();
	}
	change(anss, anss.length());
	for (int i = 0; i < anss.length(); i++) {
		if (anss[i] != '0') {
			n = 1;
		}
		if (n == 1) {
			ans = ans + anss[i];
		}
	}
	change(ans, ans.length());
	c = 0;
	anss = "";
	n = 0;
}

int main() {

	while (cin >> Opera) {
		if (Opera == "!") {
			break;
		}
		else {
			if (Opera == "+") {
				cin >> Value1;
				cin >> Value2;
				Value1_len = Value1.length();
				Value2_len = Value2.length();
				while (Value1_len < Value2_len) {
					Value1 = "0" + Value1;
					Value1_len = Value1.length();
				}
				while (Value2_len < Value1_len) {
					Value2 = "0" + Value2;
					Value2_len = Value2.length();
				}
				if (Value1_len == Value2_len) {
					add(Value1, Value2, Ans, Value1_len, Value2_len);
				}
			}
			else if (Opera == "-") {
				cin >> Value1;
				cin >> Value2;
				Value1_len = Value1.length();
				Value2_len = Value2.length();
				while (Value1_len < Value2_len) {
					Value1 = "0" + Value1;
					Value1_len = Value1.length();
				}
				while (Value2_len < Value1_len) {
					Value2 = "0" + Value2;
					Value2_len = Value2.length();
				}
				if (Value1_len == Value2_len) {
					int m = 0;
					while (Value1[m] == Value2[m]) {
						if (Value1 == Value2) {
							Ans = "0";
							break;
						}
						m++;
					}
					if (Value1[m] > Value2[m]) {
						sub(Value1, Value2, Ans, Value1_len, Value2_len);
					}
					if (Value2[m] > Value1[m]) {
						Value_1 = Value2;
						Value_2 = Value1;
						sub(Value_1, Value_2, Ans, Value1_len, Value2_len);
						k = 1;
					}
				}
			}
		}
		for (int i = 0; i < Ans.length(); i++) {
			Real_Ans = Real_Ans + Ans[i];
			if (i % 3 == 2 && i != Ans.length() - 1) {
				Real_Ans = Real_Ans + ",";
			}
		}
		change(Real_Ans, Real_Ans.length());
		if (k == 1) {
			Real_Ans = "-" + Real_Ans;
			k = 0;
		}
		cout << Real_Ans << endl;
		Real_Ans = Ans = "";
	}
	system("pause");
	return 0;
}
