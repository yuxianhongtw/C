#include<iostream>
#include<ctime>
#include<string>
#include<cctype>
#include<algorithm>
#include<iomanip>

using namespace std;

void Change(string name) {
	string n, c;
	cout << "�п�J�Q�n���N���r�A�ÿ�J���N�����r :";
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
	cout << "�п�ܼҦ� 1.��� 2.��j�g 3.��p�g 4.���}" << endl;
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
		cout << "�п�ܼҦ� 1.��� 2.��j�g 3.��p�g 4.���}" << endl;
		cin >> sw;
	}
}

void main() {

	String();
}