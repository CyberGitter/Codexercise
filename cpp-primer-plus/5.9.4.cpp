#include <iostream>
#include <string>

int main()
{
	using namespace std;
	unsigned long int sale[12]={0},wholesale=0;
	const string hint[12]=
	{
		"请输入1月份的销售量：",
		"请输入2月份的销售量：",
		"请输入3月份的销售量：",
		"请输入4月份的销售量：",
		"请输入5月份的销售量：",
		"请输入6月份的销售量：",
		"请输入7月份的销售量：",
		"请输入8月份的销售量：",
		"请输入9月份的销售量：",
		"请输入10月份的销售量：",
		"请输入11月份的销售量：",
		"请输入12月份的销售量："
	};

	for (int i=0;i<12;i++)
	{
		cout<<hint[i];
		cin>>sale[i];
		wholesale+=sale[i];
	}

	cout<<"这一年的总销售量为："<<wholesale<<endl;

	return 0;
}