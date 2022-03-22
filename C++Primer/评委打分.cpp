#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	
	string m_Name;
	int m_Score;
};

void CreatePerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for(int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void SetScore(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin(); it < v.end(); it++)
	{
		deque<int>d;
		for(int i = 0; i < 10; i++)
		{
			int score = rand()%40+1 + 60;		//60~100
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		//ƽ����
		int sum = 0;
		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		
		int avg = sum/d.size();
		//����������ѡ��
		it->m_Score = avg;
	}
}

void ShowScore(vector<Person>&v)
{
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����: " << it->m_Name << endl;
		cout << "����: " << it->m_Score << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	
	//1. ����5��ѡ��
	vector<Person>v;
	CreatePerson(v);
	
	//2. ��5��ѡ�ִ��
	SetScore(v);
	
	//3. ��ʾ������
	ShowScore(v);
}
