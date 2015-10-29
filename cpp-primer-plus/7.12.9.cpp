#include <iostream>
using namespace std;

double add(double x,double y);
double minus(double x,double y);
double multiple(double x,double y);
double calculate(double x,double y,double (*pf)(double,double));

int main()
{
	double (*pf[3])(double,double)={add,minus,multiple};
	cout<<"������һ�����֣��Կո�ָ������������ֵ�������ֹ����";
	double x=0;
	double y=0;
	while (cin>>x>>y)
	{
		for (int i=0;i<3;i++)
		{
			cout<<calculate(x,y,(*pf[i]))<<endl;
		}
		cout<<endl;
		cout<<"������һ�����֣��Կո�ָ������������ֵ�������ֹ����";
	}
	return 0;
}

double add(double x,double y)
{
	return x+y;
}

double minus(double x,double y)
{
	return x-y;
}

double multiple(double x,double y)
{
	return x*y;
}

double calculate(double x,double y,double (*pf)(double,double))
{
	return (*pf)(x,y);
}