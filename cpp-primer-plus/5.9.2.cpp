#include <iostream>

int main()
{
	using namespace std;
	double number;
	long double sum=0;
	cout<<"������һ�����֣�����0���ʾ�������򣩣�";
	cin>>number;
	while (number)
	{
		sum+=number;
		cout<<"��ĿǰΪֹ������������ۼƺ�Ϊ��"<<sum<<endl;
		cout<<"��������һ�����֣�����0���ʾ��������";
		cin>>number;
	}
	return 0;
}