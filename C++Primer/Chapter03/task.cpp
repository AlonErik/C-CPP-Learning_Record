/*
3.17
�����ַ���, ���ַ����е�ÿ�����ʶ���Ϊ��д��ʽ
{
	string word;
	vector<string>str;

	while(cin >> word)
	{
		str.push_back(word);
	}
	for(auto &s : str)
	{
		for(auto &c : s)
		{
			c = toupper(c);
		}
		cout << s << endl;
	}
}

3.20
����һ������, ��ÿ������/��β��Ե����������
{
	void get_nextTow()
{
	int num;
	vector<int>arr;

	while (cin >> num)
	{
		arr.push_back(num);
	}
	if (arr.size() == 0)
	{
		cout << "No data!" << endl;
		return;
	}
	else
	{
		for (decltype(arr.size())i = 0; i < arr.size() - 1; i += 2)
		{
			//�����������
			cout << arr[i] + arr[i + 1] << " ";
			//ÿ�����5����
			if ((i + 2) % 10 == 0)
			{
				cout << endl;
			}
		}
	}
	//������������
	if (arr.size() % 2 != 0)
	{
		cout << arr[arr.size() - 1];
	}
}

void get_opposeTwo()
{
	int num;
	vector<int>arr;

	while (cin >> num)
	{
		arr.push_back(num);
	}
	if (arr.size() == 0)
	{
		cout << "No data!" << endl;
		return;
	}
	else
	{
		for (decltype(arr.size())i = 0; i < arr.size() - 1; i += 2)
		{
			//�����������
			cout << arr[i] + arr[arr.size() - 1 - i] << " ";
			//ÿ�����5����
			if ((i + 2) % 10 == 0)
			{
				cout << endl;
			}
		}
	}
	//������������
	if (arr.size() % 2 != 0)
	{
		cout << arr[arr.size() / 2];
	}
}
}

3.25
�õ�������д���±�ʵ�ֵķ����λ��ֳ���
{
	vector<unsigned>scores(11, 0);
	unsigned grade;
	while(cin >> grade)
	{
		if (grade <= 100)
			++scores[grade / 10];
	}

	vector<unsigned>scores(11, 0);
	auto it = scores.begin();
	unsigned grade;
	while (cin >> grade)
	{
		if (grade <= 100)
		{
			++* (it + grade / 10);
		}
	}
}

3.41
�����������ʼ��vector����: ָ�������������β��ַ
{
	int arr[10] = { 0 };
	for (auto &val : arr)
	{
		val = rand() % 100;
		cout << val << " ";
	}
	cout << endl;
	vector<int>vInt(begin(arr), end(arr));
	for (auto val : vInt)
		cout << val << " ";
}
3.42
��vector���󿽱�����������: ��vector�����ÿ��Ԫ����һ��ֵ������
{
	vector<int>vInt;
	for (int i = 0; i != 10; i++)
	{
		vInt.push_back(i);
		cout << vInt[i] << " ";
	}
	cout << endl;
	int arr[10] = {0};
	auto it = vInt.begin();
	for (auto &val : arr)
	{
		val = *it;
		cout << val << " ";
		it++;
	}
}

3.43
�ò�ͬ��ʽ�����ά�����ֵ, �������ͱ���, auto, decltype
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
}

3.44
�������ͱ���������ѭ�����Ʊ���������
{
	using int_array = int[colCnt];
	typedef int int_array[colCnt];
	for (int_array* i = ia; i != ia + rowCnt; i++)
	{
		for (int* j = *i; j != *i + colCnt; j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}

3.45
ʹ��auto
{
	//ʹ�÷�Χfor
	for (auto& row : ia)
	{
		for (auto& col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;
	//ʹ����ͨfor, ���±������
	for (auto i = 0; i != rowCnt; i++)
	{
		for (auto j = 0; j != colCnt; j++)
		{
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	//ʹ����ͨfor, ��ָ��
	for (auto i = ia; i != ia + rowCnt; i++)
	{
		for (auto j = *i; j != *i + colCnt; j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}
*/