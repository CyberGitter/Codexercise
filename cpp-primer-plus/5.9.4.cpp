#include <iostream>
#include <string>

int main()
{
	using namespace std;
	unsigned long int sale[12]={0},wholesale=0;
	const string hint[12]=
	{
		"������1�·ݵ���������",
		"������2�·ݵ���������",
		"������3�·ݵ���������",
		"������4�·ݵ���������",
		"������5�·ݵ���������",
		"������6�·ݵ���������",
		"������7�·ݵ���������",
		"������8�·ݵ���������",
		"������9�·ݵ���������",
		"������10�·ݵ���������",
		"������11�·ݵ���������",
		"������12�·ݵ���������"
	};

	for (int i=0;i<12;i++)
	{
		cout<<hint[i];
		cin>>sale[i];
		wholesale+=sale[i];
	}

	cout<<"��һ�����������Ϊ��"<<wholesale<<endl;

	return 0;
}