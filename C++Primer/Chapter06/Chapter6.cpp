#include "Chapter6.h"

//�����β�, �ֲ�����, �ֲ���̬������ʹ��
int test01(int val)		//val���β�, Ҳ�Ǿֲ�����
{
	static int cnt = 0;	//cnt�Ǿֲ���̬����
	return ++cnt + val;
}

int factorial(int val)
{
	int ret = 1;
	while (val > 1)
	{
		ret *= val--;
	}
	return ret;
}

void swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
void swap2(int& val1, int& val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

bool find_upper(const string s)
{
	for (auto c : s)
	{
		if (isupper(c))
			return true;
	}
	return false;
}

void to_lower(string& s)
{
	for (auto& c : s)
	{
		c = tolower(c);
	}
}

int find_bigger(const int val1, const int* val2)
{
	if (val1 > *val2)
		return val1;
	else
		return *val2;
}

void swap_ptr(int *&val1, int *&val2)
{
	int* temp = 0;
	temp = val1;
	val1 = val2;
	val2 = temp;
}

int add_init(initializer_list<int>lint)
{
	int sum = 0;
	for (auto i : lint)
	{
		sum += i;
	}
	return sum;
}

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size)i = 0; i != size; ++i)
		if (str1[i] != str2[i])
			return false;
	return true;
}

void print_rec(const vector<int>v, unsigned index)
{
	unsigned sz = v.size();
	#ifdef DEBUG
	cout << "vector����Ĵ�С��: " << sz << endl;
	#endif // DEBUG

	if (!v.empty() && index < sz)
	{
		cout << v[index] << endl;
		print_rec(v, index + 1);
	}
}

int addf(int a, int b)
{
	return a + b;
}
int subf(int a, int b)
{
	return a - b;
}
int mulf(int a, int b)
{
	return a * b;
}
int divf(int a, int b)
{
	return a / b;
}