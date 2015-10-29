#include <iostream>
using namespace std;

double add(double x,double y);
double minus(double x,double y);
double multiple(double x,double y);
double calculate(double x,double y,double (*pf)(double,double));

int main()
{
	double (*pf[3])(double,double)={add,minus,multiple};
	cout<<"请输入一对数字（以空格分隔，输入非数字值则程序终止）：";
	double x=0;
	double y=0;
	while (cin>>x>>y)
	{
		for (int i=0;i<3;i++)
		{
			cout<<calculate(x,y,(*pf[i]))<<endl;
		}
		cout<<endl;
		cout<<"请输入一对数字（以空格分隔，输入非数字值则程序终止）：";
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