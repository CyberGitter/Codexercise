#include <iostream>

int main()
{
	using namespace std;
	double number;
	long double sum=0;
	cout<<"请输入一个数字（输入0则表示结束程序）：";
	cin>>number;
	while (number)
	{
		sum+=number;
		cout<<"到目前为止，所有输入的累计和为："<<sum<<endl;
		cout<<"请再输入一个数字（输入0则表示结束程序）";
		cin>>number;
	}
	return 0;
}