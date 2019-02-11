#include <iostream>

using namespace std;

struct Num {
	int value;
	Num *next;
};

void LinkList() {

	Num *head = new Num();
	int n;
	cout << "請輸入數字 : ";
	cin >> n;

	head->value = n;
	head->next = NULL;

	Num *current = head;
	while (n != 0) {
		cout << "請輸入數字<0:exit> : ";
		cin >> n;

		current->next = new Num;
		current = current->next;
		current->value = n;
		current->next = NULL;
	}

	current = head;
	while (true) {
		cout << current->value << " ";
		current = current->next;
		if (current->value == 0) break;
	}
	cout << endl;

	system("pause");
}

void main()
{
	LinkList();
}