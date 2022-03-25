#include<iostream>
#include<ctime>
#include "speechManager.h"
using namespace std;

int main()
{
	//���������
	srand((unsigned int)time(NULL)); 
	
	//����������Ķ���
	SpeechManager sm;
	
	int choice = 0;		//�洢�û�ѡ��
	
	while(true)
	{
		sm.show_Menu();
		
		cout << "���������ѡ��: " << endl;
		cin >> choice;
		
		switch(choice)
		{
		case 1:			//��ʼ����
			sm.startSpeech();
			break;
		case 2:			//�鿴�����¼
			sm.showRecord();
			break;
		case 3:			//��ձ�����¼ 
			sm.clearRecord();
			break;
		case 0:			//�˳�ϵͳ
			sm.exit_System();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	system("pause");
	return 0;
}
