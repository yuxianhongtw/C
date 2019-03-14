#include<iostream>
#include<string>

using namespace std;

struct Node{
	double weight;
	string ch;
	string code;
	 int lchild, rchild, parent;
};

void Select(Node huffTree[], int *a, int *b, int n) {//���v�ȳ̤p�����a�Mb  
	int i;
	double weight = 0; //��̤p����
	for (i = 0; i < n; i++){
		if (huffTree[i].parent != -1)     //�P�_�`�I�O�_�w�g��L
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
	weight = 0; //��ĤG�p����
	for (i = 0; i < n; i++) {
		if (huffTree[i].parent != -1 || (i == *a))//�ư��w��L����
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
	if (huffTree[*a].lchild < huffTree[*b].lchild) {//�p���Ʃ���
		temp = *a;
		* a = *b;
		* b = temp;
	}
}

void Huff_Tree(Node huffTree[], int w[], string ch[], int n) {
	for (int i = 0; i < 2 * n - 1; i++) {//��l�L�{	
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
		Select(huffTree, &i1, &i2, k); //�Ni1�Ai2�`�I�X���`�Ik
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
		while (huffTree[j].parent != -1) {//�q���l���W���ڸ`�I
			k = huffTree[j].parent;
			if (j == huffTree[k].lchild) {//�p�G�O�ڪ����Ĥl�A�h�O��0
				s = s + "0";
			}
			else {
				s = s + "1";
			}
			j = huffTree[j].parent;
		}
		cout << "�r�� " << huffTree[i].ch << " ���s�X�G";
		for (int l = s.size() - 1; l >= 0; l--) {
			cout << s[l];
			huffTree[i].code += s[l]; //�O�s�s�X
		}
		cout << endl;
	}
}

//string Huff_Decode(Node huffTree[], int n, string s) {
//	cout << "�ѽX�ᬰ�G";
//	string temp = "", str = "";//�O�s�ѽX�᪺�r�Ŧ�
//	for (int i = 0; i < s.size(); i++) {
//		temp = temp + s[i];
//		for (int j = 0; j < n; j++) {
//			if (temp == huffTree[j].code) {
//				str = str + huffTree[j].ch;
//				temp = "";
//				break;
//				}
//			else if (i == s.size() - 1 && j == n - 1 && temp != "") {//�����M����S��
//				str = "�ѽX���~�I";
//				}
//			}
//		}
//	return str;
//}

int main()
{
	//�s�X�L�{
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
	////�ѽX�L�{
	//string s;
	//cout << "��J�s�X�G";
	//cin >> s;
	//cout << Huff_Decode(huffTree, n, s) << endl;;
	system("pause");
	return 0;
}