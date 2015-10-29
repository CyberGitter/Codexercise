#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char first_name[20];
	char name[40];

	cout<<"Enter your first name: ";
	cin>>first_name;
	cout<<"Enter your last name: ";
	cin>>name;

	strncat_s(name, ", ", 39);
	name[39]='\0';
	strncat_s(name, first_name, 39);
	name[39]='\0';

	cout<<"Here's the information in a single string: "<<name<<endl;
	return 0;
}