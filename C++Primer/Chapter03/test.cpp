#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

int main()
{
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt] = { 0 };
	size_t cnt = 0;
	for (auto& row : ia)
	{
		for (auto& col : row)
		{
			col = cnt;
			++cnt;
		}
	}
	//ʹ�÷�Χfor
	for (int (&row)[colCnt] : ia)
	{
		for (int &col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;
	//ʹ����ͨfor, ���±������
	for (int i = 0; i != rowCnt; i++)
	{
		for (int j = 0; j != colCnt; j++)
		{
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//ʹ����ͨfor, ��ָ��
	for (int (*i)[colCnt] = ia; i != ia + rowCnt; i++)
	{
		for (int *j = *i; j != *i + colCnt; j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}

	return 0;
}