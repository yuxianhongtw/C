#include<iostream>
#include<ctime>
#include<string>
#include<cctype>
#include<algorithm>
#include<iomanip>

using namespace std;

void Change(string name) {
	string n, c;
	cout << "請輸入想要取代的字，並輸入取代它的字 :";
	cin >> n >> c;
	name = name.replace(name.find(n), n.length(), c);
	cout << name << endl;
}
void TurnBig(string name) {
	transform(name.begin(), name.end(), name.begin(), toupper);
	cout << name << endl;
}
void TurnSmall(string name) {
	transform(name.begin(), name.end(), name.begin(), tolower);
	cout << name << endl;
}
void String() {
	string name;
	int sw;
	cout << "請選擇模式 1.更改 2.轉大寫 3.轉小寫 4.離開" << endl;
	cin >> sw;
	while (sw > 0) {
		switch (sw) {
		case 1:
			cin >> name;
			Change(name);
			break;
		case 2:
			cin >> name;
			TurnBig(name);
			break;
		case 3:
			cin >> name;
			TurnSmall(name);
			break;
		case 4:
			exit(0);
			break;
		default:
			break;
		}
		cout << "請選擇模式 1.更改 2.轉大寫 3.轉小寫 4.離開" << endl;
		cin >> sw;
	}
}

void main() {

	String();
}