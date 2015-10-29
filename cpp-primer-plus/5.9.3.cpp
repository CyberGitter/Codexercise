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

	cout<<year<<"年后，Cleo的投资价值才能超过Daphne的投资价值，此时Cleo的投资价值为"<<c_invest<<"美元，"<<"Daphne的投资价值为"<<d_invest<<"美元。"<<endl;

	return 0;
}