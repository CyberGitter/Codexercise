#include <iostream>

int main()
{
	using namespace std;
	long int small, big, sum=0;
	cout<<"������������ͬ����������С����ǰ����";
	cin>>small>>big;
	for (;small<=big;small++)
		sum+=small;
	cout<<"����֮�����е�������Ϊ��"<<sum<<endl;
	return 0;
}