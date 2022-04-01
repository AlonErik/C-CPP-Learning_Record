#pragma once
#include<iostream>
using namespace std;

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex i);

private:
	vector<Screen>screens{ Screen(24,80,' ') };
};

class Screen
{
public:
	friend void Window_mgr::clear(ScreenIndex);

	void some_member() const;
	typedef string::size_type pos;
	//using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}

	char get() const { return contents[cursor]; }	//��ʽ����
	inline char get(pos ht, pos wd) const;			//��ʾ����
	Screen& set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	Screen& set(pos r, pos col, char ch)
	{
		contents[r * width + col] = ch;
		return *this;
	}

	Screen &move(pos r, pos c)
	{
		pos row = r * width;		//�����е�λ��
		cursor = row * c;			//�����ڽ�����ƶ���ָ������
		return *this;
	}
	Screen& display(ostream& os)
	{
		do_display(os); 
		return *this;
	}
	const Screen &display(ostream&os) const
	{
		do_display(os); 
		return *this;
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr;		//��ʹ��const������Ҳ�ɱ��޸�
	void do_display(ostream& os) const { os << contents; }
};

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];	//���ظ����е��ַ�
}

void Screen::some_member() const
{
	++access_ctr;				//���ڼ�¼��Ա���������õĴ���
}

void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}