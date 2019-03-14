#include <iostream>
#include <stack>

using namespace std;

void Stack(int num) {
	stack<int> st;
	stack<int> st2;

	while (num > 0) {
		st.push(num);
		cin >> num;
	}
	while (!st.empty()) {
		int &tmp = st.top();
		//cout << tmp << " ";
		st.pop();
		st2.push(tmp);
	}
	while (!st2.empty()) {
		int &tmp2 = st2.top();
		cout << tmp2 << " ";
		st2.pop();
	}
}

int main() {
	
	int num;
	cin >> num;
	Stack(num);

	system("pause");
	return 0;
}