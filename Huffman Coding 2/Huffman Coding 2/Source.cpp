#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Huffman?��???
typedef struct Node
{
	char value;               //??���r�ŭ�   
	int weight;               //??�r�ťX?��?��
	Node *lchild, *rchild;     //??�����k�Ĥl
}Node;

//�۩w?�Ƨ�??�A�Y�Hvector��node??weight�ȤɧǱƧ�
bool ComNode(Node *p, Node *q)
{
	return p->weight < q->weight;
}

//�۳yHuffman?�A��^��??��?
Node* BuildHuffmanTree(vector<Node*> vctNode)
{
	while (vctNode.size() > 1)                            //vctNode�˪L��???�j�_1?�`??��X�}
	{
		sort(vctNode.begin(), vctNode.end(), ComNode);   //��?�װ��C?�˪L����??��ɧǱƧ�

		Node *first = vctNode[0];    //���Ƨ��ǦZvctNode�˪L��?�׳̤p��?��
		Node *second = vctNode[1];   //���Ƨ��ǦZvctNode�˪L��?�ײĤG�p��?��
		Node *merge = new Node;      //�X�}�W��???
		merge->weight = first->weight + second->weight;
		merge->lchild = first;
		merge->rchild = second;

		vector<Node*>::iterator iter;
		iter = vctNode.erase(vctNode.begin(), vctNode.begin() + 2);    //?vctNode�˪L��?���W??�׳̤p��????first�Msecond
		vctNode.push_back(merge);                                 //�VvctNode�˪L���K�[�X�}�Z��merge?
	}
	return vctNode[0];            //��^�۳y�n����??
}

//�Φ^���k?���L??
void PrintHuffman(Node *node, vector<int> vctchar)
{
	if (node->lchild == NULL && node->rchild == NULL)
	{//�Y����?�l??�A?���N���Lvctchar���s��??
		cout << node->value << ": ";
		for (vector<int>::iterator iter = vctchar.begin(); iter != vctchar.end(); iter++)
			cout << *iter;
		cout << endl;
		return;
	}
	else
	{
		vctchar.push_back(1);     //�J�쥪�l???vctchar���[�@?1
		PrintHuffman(node->lchild, vctchar);
		vctchar.pop_back();       //�^���A?��??�[?�h��1
		vctchar.push_back(0);     //�J�쥪�l???vctchar���[�@?0
		PrintHuffman(node->rchild, vctchar);
		vctchar.pop_back();       //�^���A?��??�[?�h��0

	}
}

int main()
{
	cout << "************ Huffman???? ***************" << endl;
	cout << "??�J�n??���r��,�}�H�Ů�j?�]??���N�^�G" << endl;
	vector<Node*> vctNode;        //�s��Node??��vector�e��vctNode
	char ch;                      //??�s�񱱨�x?�J���r��
	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ')continue;      //�J��Ů�?��?�A�Y??�J�@?�r�ŪŤ@��Ů�
		Node *temp = new Node;
		temp->value = ch;
		temp->lchild = temp->rchild = NULL;
		vctNode.push_back(temp);  //?�s��??���J��e��vctNode��
	}

	cout << endl << "??�J�C?�r��??��?�סA�}�H�Ů�j?�G" << endl;
	for (int i = 0; i < vctNode.size(); i++)
		cin >> vctNode[i]->weight;

	Node *root = BuildHuffmanTree(vctNode);   //�۳yHuffman?�A?��^��?��??root
	vector<int> vctchar;
	cout << endl << "??��Huffman??�p�U�G" << endl;
	PrintHuffman(root, vctchar);

	system("pause");
}