#include<iostream>  
#include<string> 
#include <queue> 
using namespace std;
void add(deque<int> &input, deque<string> &name, int count)
{
	input[count + 1] += input[count];
	name[count + 1] += name[count];
}
void printnumber(deque<string> &zeroone)
{
	int size;
	for (int i = 0; i < zeroone.size(); i++)
	{
		size = zeroone[i].size();
		cout << zeroone[i][0] << " : ";
		for (int j = size - 1; j > 0; j--)
		{
			cout << zeroone[i][j];
		}
		cout << endl;
	}
}
void getzeroone(string name, deque<string> &zeroone, char get)
{
	for (int i = 0; i < name.size(); i++)
	{
		for (int j = 0; j < zeroone.size(); j++)
		{
			if (name[i] == zeroone[j][0])
			{
				zeroone[j] += get;
				break;
			}
		}
	}
}

void order(deque<int> &number, deque<string> &name, deque<string> &get)
{
	int n = 6;
	int tempnumber;
	string tempname;
	char getname;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (number[j] > number[j + 1])
			{
				tempnumber = number[j];
				tempname = name[j];

				number[j] = number[j + 1];
				name[j] = name[j + 1];

				number[j + 1] = tempnumber;
				name[j + 1] = tempname;
			}
			if (get[j] > get[j + 1])
			{
				getname = get[j][0];
				get[j][0] = get[j + 1][0];
				get[j + 1][0] = getname;
			}
		}
	}
}
int main()
{
	int count = 0;
	deque<int> number;
	deque<string> name, zeroone;
	while (count < 6)
	{
		int input;
		string inname;
		cin >> inname >> input;
		name.push_back(inname);
		zeroone.push_back(inname);
		number.push_back(input);
		count++;
	}
	count = 0;
	while (count < 5)
	{
		order(number, name, zeroone);
		getzeroone(name[count], zeroone, '1');
		getzeroone(name[count + 1], zeroone, '0');
		add(number, name, count);
		count++;
	}
	printnumber(zeroone);
	system("pause");
	return 0;
}
