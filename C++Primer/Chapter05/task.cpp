/*
5.14
��������ַ����г��ִ������ĵ��ʼ�����ִ���
{
	string nowstring, prestring, maxstring;
	int cnt = 1, maxCnt = 0;
	while (cin >> nowstring)
	{
		if (nowstring == prestring)
			++cnt;
		if (cnt > maxCnt)
		{
			maxCnt = cnt;
			maxstring = nowstring;
		}
		else
			cnt = 1;
		prestring = nowstring;
	}
	if (maxCnt > 1)
		cout << maxstring << " " << maxCnt << endl;
	else
}

5.17
�������vector<int>����һ���Ƿ�����һ����ǰ׺
{
	vector<int>v1 = { 0,1,1,2 };
	vector<int>v2 = { 0,1,1,2,3,5,8 };
	auto it1 = v1.cbegin();
	auto it2 = v2.cbegin();

	while (it1 != v1.cend() && it2 != v2.cend())
	{
		if (*it1 != *it2)
		{
			cout << "v1��v2������ǰ׺��ϵ." << endl;
			break;
		}
		++it1;
		++it2;
	}
	if (it1 == v1.cend())
		cout << "v1��v2��ǰ׺";
	if (it2 == v2.cend())
		cout << "v2��v1��ǰ׺";
}
5.20
��ȡstringֱ����������������ͬ�ĵ��ʻ����
string nowString, preString;
	bool no_same = true;
	while (cin >> nowString)
	{
		if (nowString == preString)
		{
			no_same = false;
			cout << "the next same is: " << nowString << endl;
			break;
		}
		preString = nowString;
	}
	if (no_same)
		cout << "No next same." << endl;
5.21
��Ӽ������, �����Ƿ��Դ�д��ĸ��ͷ
if(isupper(nowString[0]));

5.25
ʹ��try-catch�ṹʵ�ֶ���������������ж�
{
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("��������Ϊ0");
			cout << "a / b = " << a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			cout << "\nTry Again? Enter y or n" << endl;
			char ch = 0;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
				break;
		}
	}
}
*/