#include<iostream>
#include<string>
using namespace std;

int main()
{
	string first_name, last_name;
	cout << "Please enter your first name and last name: ";
	cin >> first_name;
	cin >> last_name;
	cout << '\n'
		 << "Hello, "
		 << first_name << ' ' << last_name
		 << "... and goodbye!\n";

	return 0;
}
