#pragma once
#include<iostream>
using namespace std;

struct Sales_data
{
	string bookNo;				//ISBN
	unsigned unit_sold = 0;		//������
	double sellingprice = 0.0;	//���ۼ�			����
	double saleprice = 0.0;		//ʵ�ۼ�
	double revenue = 0.0;		//������
	double discount = 0.0;		//�ۿ�
};