#include<iostream>  
#include<string> 
#include <vector> 
using namespace std;
void add(vector<int> &innum, vector<string> &name, int count){
	innum[count + 1] += innum[count];
	name[count + 1] += name[count];
}

void getcode(string name, vector<string> &code, char get){
	for (int i = 0; i < name.size(); i++){
		for (int j = 0; j < code.size(); j++){
			if (name[i] == code[j][0]){
				code[j] += get;
				break;
			}
		}
	}
}

void sort(vector<int> &number, vector<string> &name, vector<string> &get){
	int n = 6;
	int tempnum;
	string tempname;
	char getname;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (number[j] > number[j + 1]){
				tempnum = number[j];
				tempname = name[j];

				number[j] = number[j + 1];
				name[j] = name[j + 1];

				number[j + 1] = tempnum;
				name[j + 1] = tempname;
			}
			if (get[j] > get[j + 1]){
				getname = get[j][0];
				get[j][0] = get[j + 1][0];
				get[j + 1][0] = getname;
			}
		}
	}
}
int main()
{
	int count = 0, n = 6;
	vector<int> number;
	vector<string> name, code;
	while (count < n){
		int innum;
		string inname;
		cin >> inname >> innum;
		name.push_back(inname);
		code.push_back(inname);
		number.push_back(innum);
		count++;
	}
	count = 0;
	while (count < n - 1){
		sort(number, name, code);
		getcode(name[count], code, '1');
		getcode(name[count + 1], code, '0');
		add(number, name, count);
		count++;
	}

	int size;
	for (int i = 0; i < code.size(); i++){
		size = code[i].size();
		cout << code[i][0] << " : ";
		for (int j = size - 1; j > 0; j--){
			cout << code[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
