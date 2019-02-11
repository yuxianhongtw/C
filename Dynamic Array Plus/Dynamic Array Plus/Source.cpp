#include<iostream>
#include<ctime>
#include<string>
#include<cctype>
#include<algorithm>
#include<iomanip>

using namespace std;

void Add(int **data, int height, int width) {
	int *arr = new int[width / 2];
	int temp;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j = j + 2) {
			temp = data[i][j] + data[i][j + 1];
			for (int k = 0; k < width / 2; k++) {
				arr[k] = temp;
				data[i][j + 1] = arr[k];
			}
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << setw(3) << data[i][j];
		}
		cout << endl;
	}
}
void Array() {
	srand(time(NULL));
	int data_height, data_width;
	int **data;

	cout << "¿é¤J¤Gºû°}¦Cºû«×¡G";
	cin >> data_height >> data_width;

	data = new int*[data_height];
	for (int i = 0; i < data_height; i++)
		data[i] = new int[data_width];

	for (int i = 0; i < data_height; i++) {
		for (int j = 0; j < data_width; j++) {
			int a = (rand() % 50) + 1;
			data[i][j] = a;
		}
	}

	for (int i = 0; i < data_height; i++) {
		for (int j = 0; j < data_width; j++) {
			cout << setw(3) << data[i][j];
		}
		cout << endl;
	}
	cout << "----------------------------------" << endl;
	Add(data, data_height, data_width);
}

void main() {

	Array();

}