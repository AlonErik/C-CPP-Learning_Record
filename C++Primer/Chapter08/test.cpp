#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<string>
#include<vector>
using namespace std;

istream& func(istream& ist)
{
	string v;
	while (ist >> v, !ist.eof())
	{
		if (ist.bad())
			throw runtime_error("IO������");
		if (ist.fail())
		{
			cerr << "���ݴ���, ������: " << endl;
			ist.clear();
			ist.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	ist.clear();
	return ist;
}

struct PersonInfo
{
	string name;
	vector<string> phones;
};

string format(const string& s) { return s; }

bool valid(const string& s)
{
	return true;
}

int main(int argc, char* argv[])
{
	//--------------------8.4--------------------
	/*ifstream ifs("text.txt");
	if (!ifs)
	{
		cerr << "�޷����ļ���" << endl;
		return -1;
	}
	string line;
	vector<string>v;
	while (ifs >> line)
		v.push_back(line);
	ifs.close();

	for (auto c : v)
		cout << c << endl;*/

	//--------------------8.9--------------------
	/*ostringstream osg;
	osg << "C++ Primer �����" << endl;
	istringstream ist(osg.str());
	func(ist);*/

	//--------------------8.10--------------------
	/*ifstream ifs("text.txt");
	if (!ifs)
	{
		cerr << "�޷����ļ���" << endl;
		return -1;
	}
	string line;
	vector<string>words;
	while (getline(ifs, line))
	{
		words.push_back(line);
	}
	ifs.close();
	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
	{
		istringstream line_str(*it);
		string word;
		while (line_str >> word)
			cout << word << " ";
		cout << endl;
	}*/

	//--------------------8.13--------------------
	string line, word;
	vector<PersonInfo>people;
	istringstream record;

	if (argc != 2)
	{
		cerr << "������ļ���" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}
	while (getline(in, line))
	{
		PersonInfo info;		//����һ������˼�¼���ݵĶ���
		record.clear();			//�ظ�ʹ���ַ�����ʱ, ÿ�ζ�Ҫ����clear
		record.str(line);		//����¼�󶨵��ն������
		record >> info.name;	//��ȡ����
		while (record >> word)	//��ȡ�绰����
			info.phones.push_back(word);
		people.push_back(info);
	}
	ostringstream os;
	for (const auto& entry : people)
	{
		ostringstream formatted, badNums;	//ÿ��ѭ���������Ķ���
		for (const auto& nums : entry.phones)
		{
			if (!valid(nums))
				//�������ַ�����ʽ����
				badNums << " " << nums;
			else
				//����ʽ�����ַ��� "д��"
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			os << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
	cout << os.str() << endl;

	return 0;
}