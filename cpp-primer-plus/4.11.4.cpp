#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string first_name;
	string name;

	cout<<"Enter your first name: ";
	cin>>first_name;
	cout<<"Enter your last name: ";
	cin>>name;

	name+=", ";
	name+=first_name;
	cout<<"Here's the information in a single string: "<<name<<endl;

	return 0;
}