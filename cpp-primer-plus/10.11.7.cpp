#include <iostream>
#include <cstring>

using namespace std;

class Plorg
{
private:
	char name[20];
	int CI;
public:
	Plorg(const char * pname="Plorga", int pCI=50);
	void setCI(int n);
	void show();
};

Plorg::Plorg(const char * pname, int pCI)
{
	strncpy(name, pname, 19);
	name[19]='\0';
	CI=pCI;
}

void Plorg::setCI(int n)
{
	CI=n;
}

//我认为以上两个函数定义涉及到一个类方法定义的边界问题，即函数接受的形参是在函数定义内部由用户输入还是在函数外部由用户建立再传递给函数呢？

void Plorg::show()
{
	cout<<"Name: "<<name<<endl<<"CI: "<<CI<<endl;
}

int main()
{
	Plorg plorg1;
	cout<<"plorg1:"<<endl;
	plorg1.show();

	cout<<endl;

	cout<<"Enter name to create a new plorg: ";
	char tempname[20];
	cin.getline(tempname, 20);
	cout<<"Enter a CI value: ";
	int tempCI;
	cin>>tempCI;
	Plorg plorg2(tempname, tempCI);
	cout<<"plorg2:"<<endl;
	plorg2.show();

	cout<<endl;

	cout<<"Enter a CI value to reset plorg1's: ";
	int tempinteger;
	cin>>tempinteger;
	plorg1.setCI(tempinteger);
	cout<<"plorg1:"<<endl;
	plorg1.show();

	return 0;
}