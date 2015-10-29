#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person
{
private:
	static const int LIMIT=25;
	string lname;
	char fname[LIMIT];
public:
	Person() {lname=""; fname[0]='\0';}
	Person(const string &ln, const char * fn="Heyyou");
	void Show() const;
	void FormalShow() const;
};

Person::Person(const string & ln, const char * fn)
{
	lname=ln;
	strncpy(fname, fn, LIMIT-1);//警告："strncpy"被声明为否决的
	fname[LIMIT-1]='\0';        //注意这两行的LIMIT-1
}

void Person::Show() const
{
	cout<<fname<<" "<<lname<<endl;
}

void Person::FormalShow() const
{
	cout<<lname<<", "<<fname<<endl;
}

int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout<<endl;
	one.FormalShow();

	cout<<endl;

	two.Show();
	cout<<endl;
	two.FormalShow();

	cout<<endl;

	three.Show();
	cout<<endl;
	three.FormalShow();

	return 0;
}