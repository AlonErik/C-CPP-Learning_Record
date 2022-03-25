#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include "speaker.h"
using namespace std;

//�ݽ�����������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	
	//�˵�����
	void show_Menu();
	
	//�˳�ϵͳ
	void exit_System();
	
	//��������
	~SpeechManager();
	
	//��ʼ������
	void initSpeech();
	
	//����ѡ��
	void createSpeaker();
	
	//��ʼ����, �����������̿��ƺ���
	void startSpeech();
	
	//��ǩ
	void speechDraw();
	
	//����
	void speechContest();
	
	//��ʾ�������
	void showScore();
	
	//�����¼
	void saveRecord();
	
	//��ȡ��¼
	void loadRecord();
	
	//��ʾ�����¼
	void showRecord();
	
	//����ļ�
	void clearRecord();
	
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	
	//��������¼������
	map<int, vector<string>>m_Record;
	
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;
	
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;
	
	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;
	
	//��ű�ż���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;
	
	//��ű�������
	int m_Index;
};
