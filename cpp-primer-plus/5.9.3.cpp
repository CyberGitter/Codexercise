#include <iostream>

int main()
{
	using namespace std;

	double d_invest=100;
	double d_invest_original=d_invest;
	double c_invest=100;
	const double d_rate=0.1;
	const double c_rate=0.05;
	int year=0;

	while (!(c_invest>d_invest))
	{
		year++;
		d_invest+=d_invest_original*d_rate;
		c_invest+=c_invest*c_rate;
	}

	cout<<year<<"���Cleo��Ͷ�ʼ�ֵ���ܳ���Daphne��Ͷ�ʼ�ֵ����ʱCleo��Ͷ�ʼ�ֵΪ"<<c_invest<<"��Ԫ��"<<"Daphne��Ͷ�ʼ�ֵΪ"<<d_invest<<"��Ԫ��"<<endl;

	return 0;
}