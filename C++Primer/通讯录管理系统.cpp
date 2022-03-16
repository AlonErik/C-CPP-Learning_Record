/*
��������
1.�����ϵ��: ��������, �Ա�, ����, �绰, סַ, ����¼1000��
2.��ʾ��ϵ��: ��ʾ��������ϵ����Ϣ
3.ɾ����ϵ��: ������ɾ��ָ����ϵ�˵���Ϣ
4.������ϵ��: �������鿴ָ����ϵ�˵���Ϣ
5.�޸���ϵ��: �����������޸���ϵ�˵���Ϣ
6.�����ϵ��: ���ͨѶ¼��������Ϣ
0.�˳�ͨѶ¼: �˳���ǰʹ�õ�ͨѶ¼
*/
#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//��ϵ�˽ṹ��;
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//ͨѶ¼�ṹ��;
struct Addressbook
{
	struct Person PersonArray[MAX];
	int m_Size;
};

//��ʾ�˵�;
void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

//�����ϵ��;
void AddPerson(Addressbook *abs)
{
	if(abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����, �޷����!" << endl;
		return;
	}
	else
	{
		
		cout << "����������: " << endl;
		string name;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		
		cout << "�������Ա�: " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������, ����������" << endl;
		}
		
		cout << "����������: " << endl;
		int age = 0;
		while(true)
		{
			cin >> age;
			if(age >= 0 && age <= 150)
			{
				abs->PersonArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "��������, ����������" << endl;
		}
		
		cout << "������绰: " << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		
		cout << "������סַ: " << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;
			
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
} 

//��ʾ��ϵ��;
void ShowPerson(Addressbook *abs)
{
	if(abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for(int i = 0; i < abs->m_Size; i++)
		{
			cout << "����: " << abs->PersonArray[i].m_Name << "\t";
			cout << "�Ա�: " << (abs->PersonArray[i].m_Sex==1 ? "��":"Ů") << "\t";
			cout << "����: " << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰: " << abs->PersonArray[i].m_Phone << "\t";
			cout << "סַ: " << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls"); 
}

//�����ϵ���Ƿ����;
int CheckPerson(Addressbook *abs, string name)
{
	for(int i = 0; i < abs->m_Size; i++)
	{
		if(abs->PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��;
void DeletePerson(Addressbook *abs)
{
	cout << "������Ҫɾ������ϵ��: " << endl;
	string name;
	cin >> name;
	int ret = CheckPerson(abs, name);
	if(ret != -1)
	{
		for(int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i+1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

//������ϵ��;
void FindPerson(Addressbook *abs)
{
	cout << "������Ҫ���ҵ���ϵ��: " << endl;
	string name;
	cin >> name;
	int ret = CheckPerson(abs, name);
	if(ret != -1)
	{
		cout << "����: " << abs->PersonArray[ret].m_Name << "\t";
		cout << "�Ա�: " << (abs->PersonArray[ret].m_Sex==1 ? "��":"Ů") << "\t";
		cout << "����: " << abs->PersonArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->PersonArray[ret].m_Phone << "\t";
		cout << "סַ: " << abs->PersonArray[ret].m_Addr << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

//�޸���ϵ��;
void ModifyPerson(Addressbook *abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��: " << endl;
	string name;
	cin >> name;
	int ret = CheckPerson(abs, name);
	if(ret != -1)
	{
		cout << "����������: " << endl;
		string name;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		
		cout << "�������Ա�: " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������, ����������" << endl;
		}
		
		cout << "����������: " << endl;
		int age = 0;
		while(true)
		{
			cin >> age;
			if(age >= 0 && age <= 150)
			{
				abs->PersonArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "��������, ����������" << endl;
		}
		
		cout << "������绰: " << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		
		cout << "������סַ: " << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;
		
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

//�����ϵ��;
void ClearPerson(Addressbook *abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main(void)
{
	Addressbook abs;
	abs.m_Size = 0;
	
	int select = 0;
	
	while(true)
	{
		ShowMenu();
		
		cin >> select;
		switch(select)
		{
		case 1:		//1.�����ϵ��
			AddPerson(&abs);
			break;
		case 2:		//2.��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:		//3.ɾ����ϵ��
			DeletePerson(&abs);
			break;
		case 4:		//4.������ϵ��
			FindPerson(&abs);
			break;
		case 5:		//5.�޸���ϵ��
			ModifyPerson(&abs);
			break;
		case 6:		//6.�����ϵ��
			ClearPerson(&abs);
			break;
		case 0:		//0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;	
		}
	}
	return 0;
}
