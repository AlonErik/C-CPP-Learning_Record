#include<iostream>
#include "Sales_item.h"
using namespace std;

/*
������ĿҪ���ǽ�ÿ��ISBN�ļ�¼����һ��
�����޷�ʵ�ָ�Ҫ��, ֻ������󼴴�ӡ
�������Sales_item����洢ISBN��ͬ�ļ�¼
��������ɺ�, ���������ӡ���
*/

int main()
{
	Sales_item total, trans;

	if (cin >> total)
	{
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
	{
		cout << "No data?!" << endl;
		return -1;
	}
	return 0;
}