#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
	char * str;
	int ct;
};

void set(stringy &,const char *);
void show(const stringy & str,int n=1);
void show(const char * str,int n=1);

int main()
{
	stringy beany;
	char testing[]="Reality isn't what it used to be. ";

	set(beany,testing);
	show(beany);
	show(beany,2);
	testing[0]='D';
	testing[1]='u';
	show(testing);
	show(testing,3);
	show("Done! ");
	return 0;
}

void set(stringy & str1,const char * str2)
{
	str1.ct=strlen(str2);
	str1.str=new char[str1.ct+1];
	strcpy(str1.str,str2);
}

void show(const stringy & str,int n)
{
	for (int i=0;i<n;i++)
		cout<<str.str<<endl;
}

void show(const char * str,int n)
{
	for (int i=0;i<n;i++)
		cout<<str<<endl;
}