#include <iostream>

const double RATE1=0.10;
const double RATE2=0.15;
const double RATE3=0.20;

int main()
{
	using namespace std;
	long double income=0,tax=0;
	cout<<"请输入您的收入（输入负数或非数字则将结束）：";
	while ((cin>>income)&&(income>=0))
	{
		if (income<=5000)
			tax=0;
		else if ((income>5000)&&(income<=15000))
			tax=(income-5000)*RATE1;
		else if ((income>15000)&&(income<=35000))
			tax=10000*RATE1+(income-15000)*RATE2;
		else
			tax=10000*RATE1+20000*RATE2+(income-35000)*RATE3;
		cout<<"您需要缴纳的所得税为："<<tax<<" tvarps。"<<endl;
		cout<<"请输入您的收入（输入负数或非数字则将结束）：";
	}
	return 0;
}