#include<iostream>
#include<string>

using namespace std;

struct Node{
	double weight;
	string ch;
	string code;
	 int lchild, rchild, parent;
};

void Select(Node huffTree[], int *a, int *b, int n) {//找權值最小的兩個a和b  
	int i;
	double weight = 0; //找最小的數
	for (i = 0; i < n; i++){
		if (huffTree[i].parent != -1)     //判斷節點是否已經選過
			continue;
		else {
			if (weight == 0) {
				weight = huffTree[i].weight;
				* a = i;
			}
			else {
				if (huffTree[i].weight < weight) {
					weight = huffTree[i].weight;
					* a = i;
				}
			}
		}
	}
	weight = 0; //找第二小的數
	for (i = 0; i < n; i++) {
		if (huffTree[i].parent != -1 || (i == *a))//排除已選過的數
			continue;
		else {
			if (weight == 0) {
				weight = huffTree[i].weight;
				* b = i;
			}
			else {
				if (huffTree[i].weight < weight) {
					weight = huffTree[i].weight;
					* b = i;
				}
			}
		}
	}
	int temp;
	if (huffTree[*a].lchild < huffTree[*b].lchild) {//小的數放左邊
		temp = *a;
		* a = *b;
		* b = temp;
	}
}

void Huff_Tree(Node huffTree[], int w[], string ch[], int n) {
	for (int i = 0; i < 2 * n - 1; i++) {//初始過程	
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
		huffTree[i].code = "";
	}
	for (int i = 0; i < n; i++) {
		huffTree[i].weight = w[i];
		huffTree[i].ch = ch[i];
	}
	for (int k = n; k < 2 * n - 1; k++) {
		int i1 = 0;
		int i2 = 0;
		Select(huffTree, &i1, &i2, k); //將i1，i2節點合成節點k
		huffTree[i1].parent = k;
		huffTree[i2].parent = k;
		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
		huffTree[k].lchild = i1;
		huffTree[k].rchild = i2;
	}
}

void Huff_Code(Node huffTree[], int n) {
	int i, j, k;
	string s = "";
	for (i = 0; i < n; i++) {
		s = "";
		j = i;
		while (huffTree[j].parent != -1) {//從葉子往上找到根節點
			k = huffTree[j].parent;
			if (j == huffTree[k].lchild) {//如果是根的左孩子，則記為0
				s = s + "0";
			}
			else {
				s = s + "1";
			}
			j = huffTree[j].parent;
		}
		cout << "字符 " << huffTree[i].ch << " 的編碼：";
		for (int l = s.size() - 1; l >= 0; l--) {
			cout << s[l];
			huffTree[i].code += s[l]; //保存編碼
		}
		cout << endl;
	}
}

//string Huff_Decode(Node huffTree[], int n, string s) {
//	cout << "解碼後為：";
//	string temp = "", str = "";//保存解碼後的字符串
//	for (int i = 0; i < s.size(); i++) {
//		temp = temp + s[i];
//		for (int j = 0; j < n; j++) {
//			if (temp == huffTree[j].code) {
//				str = str + huffTree[j].ch;
//				temp = "";
//				break;
//				}
//			else if (i == s.size() - 1 && j == n - 1 && temp != "") {//全部遍歷後沒有
//				str = "解碼錯誤！";
//				}
//			}
//		}
//	return str;
//}

int main()
{
	//編碼過程
	const int n = 6;
	Node huffTree[2 * n];
	string word;
	int num;
	string str[n] = {};
	int w[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> word >> num;
		str[i] = word;
		w[i] = num;
	}
	
	Huff_Tree(huffTree, w, str, n);
	Huff_Code(huffTree, n);
	////解碼過程
	//string s;
	//cout << "輸入編碼：";
	//cin >> s;
	//cout << Huff_Decode(huffTree, n, s) << endl;;
	system("pause");
	return 0;
}