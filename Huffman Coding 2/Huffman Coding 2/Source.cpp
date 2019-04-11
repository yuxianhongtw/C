#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Huffman?的???
typedef struct Node
{
	char value;               //??的字符值   
	int weight;               //??字符出?的?度
	Node *lchild, *rchild;     //??的左右孩子
}Node;

//自定?排序??，即以vector中node??weight值升序排序
bool ComNode(Node *p, Node *q)
{
	return p->weight < q->weight;
}

//构造Huffman?，返回根??指?
Node* BuildHuffmanTree(vector<Node*> vctNode)
{
	while (vctNode.size() > 1)                            //vctNode森林中???大于1?循??行合并
	{
		sort(vctNode.begin(), vctNode.end(), ComNode);   //依?度高低?森林中的??行升序排序

		Node *first = vctNode[0];    //取排完序后vctNode森林中?度最小的?根
		Node *second = vctNode[1];   //取排完序后vctNode森林中?度第二小的?根
		Node *merge = new Node;      //合并上面???
		merge->weight = first->weight + second->weight;
		merge->lchild = first;
		merge->rchild = second;

		vector<Node*>::iterator iter;
		iter = vctNode.erase(vctNode.begin(), vctNode.begin() + 2);    //?vctNode森林中?除上??度最小的????first和second
		vctNode.push_back(merge);                                 //向vctNode森林中添加合并后的merge?
	}
	return vctNode[0];            //返回构造好的根??
}

//用回溯法?打印??
void PrintHuffman(Node *node, vector<int> vctchar)
{
	if (node->lchild == NULL && node->rchild == NULL)
	{//若走到?子??，?迭代打印vctchar中存的??
		cout << node->value << ": ";
		for (vector<int>::iterator iter = vctchar.begin(); iter != vctchar.end(); iter++)
			cout << *iter;
		cout << endl;
		return;
	}
	else
	{
		vctchar.push_back(1);     //遇到左子???vctchar中加一?1
		PrintHuffman(node->lchild, vctchar);
		vctchar.pop_back();       //回溯，?除??加?去的1
		vctchar.push_back(0);     //遇到左子???vctchar中加一?0
		PrintHuffman(node->rchild, vctchar);
		vctchar.pop_back();       //回溯，?除??加?去的0

	}
}

int main()
{
	cout << "************ Huffman???? ***************" << endl;
	cout << "??入要??的字符,并以空格隔?（??任意）：" << endl;
	vector<Node*> vctNode;        //存放Node??的vector容器vctNode
	char ch;                      //??存放控制台?入的字符
	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ')continue;      //遇到空格?跳?，即??入一?字符空一格空格
		Node *temp = new Node;
		temp->value = ch;
		temp->lchild = temp->rchild = NULL;
		vctNode.push_back(temp);  //?新的??插入到容器vctNode中
	}

	cout << endl << "??入每?字符??的?度，并以空格隔?：" << endl;
	for (int i = 0; i < vctNode.size(); i++)
		cin >> vctNode[i]->weight;

	Node *root = BuildHuffmanTree(vctNode);   //构造Huffman?，?返回的?根??root
	vector<int> vctchar;
	cout << endl << "??的Huffman??如下：" << endl;
	PrintHuffman(root, vctchar);

	system("pause");
}