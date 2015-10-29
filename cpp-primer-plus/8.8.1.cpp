#include <iostream>
using namespace std;

int count=0;
void show(const char *);
void show(const char *, int);

int main()
{
	const char test[]="Hello, world!";
	show(test);
	show(test,3);
	show(test,0);
	return 0;
}

void show(const char * str)
{
	cout<<str<<endl;
}

void show(const char * str, int n)
{
	count++;
	if (n)
		for (int i=0;i<count;i++)
			cout<<str<<endl;
}