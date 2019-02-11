#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Num {
	int value;
	Num *rlink, *llink;
};
Num *head = new Num();

int Create() {
	int n;
	cout << "請輸入想要新增的數字 : ";
	cin >> n;

	Num *current = head;
	for (; current->rlink; current = current->rlink);

	current->rlink = new Num;
	Num *next = current->rlink;
	next->llink = current;
	next->value = n;
	next->rlink = NULL;
	return 0;
}

int Delete() {
	Num *current = head;

	int n;
	cout << "請輸入想要刪除的數字 : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (current->rlink)
			current = current->rlink;
	}

	if (current == head) {
		Num *d = head;
		head = head->rlink;
		if (head != NULL)
			head->llink = NULL;
		delete d;
	}
	else if (current->rlink == NULL) {
		Num *before = current->llink;
		Num *d = current;
		before->rlink = NULL;
		delete d;
	}
	else {
		Num *before = current->llink;
		Num *next = current->rlink;
		before->rlink = next;
		next->llink = before;
		Num *d = current;
		delete d;
	}
	return 0;
}

int Search() {

	Num *current = head;

	int n;
	cout << "請輸入想要搜尋的數字 : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (current->rlink)
			current = current->rlink;
	}

	cout << current->value << endl;
	return 0;
}

int Sort() {
	int n;
	Num *current = head;
	for (; current; current = current->rlink) {
		for (Num *next = current->rlink; next; next = next->rlink) {
			if (next->value < current->value) {
				n = next->value;
				next->value = current->value;
				current->value = n;
			}
		}
	}


	current = head;
	while (true) {
		cout << current->value << " ";
		current = current->rlink;
		//current->rlink = current->llink;
		if (current == NULL) break;
	}
	cout << endl;
	return 0;
}

void LinkList() {
	int n;
	cout << "請輸入數字 : ";
	cin >> n;

	//Num *current = head->rlink;
	head->value = n;
	head->rlink = NULL;
	head->llink = NULL;
	int sw;
	cout << "請選擇模式: 1.新增 2.刪除 3.搜尋 4.排序" << endl;
	cin >> sw;
	while (sw > 0) {
		switch (sw) {
		case 1:
			Create();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Search();
			break;
		case 4:
			Sort();
			break;
		default:
			break;
		}
		cout << "請選擇模式: 1.新增 2.刪除 3.搜尋 4.排序" << endl;
		cin >> sw;
	}
	system("pause");
}

void main() {
	
	LinkList();
	
}