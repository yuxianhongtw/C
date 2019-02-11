#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> Num;
vector<vector<int>> Ans;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

int ans(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Num.push_back(0);
		}
		Ans.push_back(Num);
	}

	int index = 0, x = 0, y = -1, temp_x, temp_y;

	for (int i = 0; i < m * n; i++)
	{
		temp_x = x + dir_x[index];
		temp_y = y + dir_y[index];
		if (temp_x < 0 || temp_x > m - 1 ||
			temp_y < 0 || temp_y > n - 1 ||
			Ans[temp_x][temp_y] != 0) {
			index = (index + 1) % 4;
		}
		x = x + dir_x[index];
		y = y + dir_y[index];
		Ans[x][y] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << Ans[i][j];
		}
		cout << endl;
	}
	return 0;
}

void main() {
	int m, n;

	cin >> m >> n;

	ans(m, n);

	system("pause");
}