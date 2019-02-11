#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void DArray(int n) {
	srand(time(NULL));
	int temp;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		int a = (rand() % 50) + 1;
		arr[i] = a;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	system("pause");

}

void main() {
	int n;
	cin >> n;
	DArray(n);

}