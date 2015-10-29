#include <iostream.h>
#include <string.h>   //标准头文件cstring的老式实现
#include "9.7.1.golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strncpy(g.fullname, name, 39);
	g.fullname[39]='\0';
	g.handicap=hc;
}

int setglf(golf & g)
{
	cout<<"Please enter a name: ";
	cin.getline(g.fullname,Len);
	if (0==strlen(g.fullname))
		return 0;
	cin.get();
	cout<<"Please enter handicap value: ";
	cin>>g.handicap;
	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap=hc;
}

void showgolf(const golf & g)
{
	cout<<"Name: "<<g.fullname<<endl;
	cout<<"Handicap Value: "<<g.handicap<<endl;
}