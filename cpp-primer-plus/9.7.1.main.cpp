#include <iostream.h>
#include <string.h>   //��׼ͷ�ļ�cstring����ʽʵ��
#include "9.7.1.golf.h"
const int N=10;

golf g[N];

int main()
{
	int count=0;   //������
	char name[Len];
	int handicapvalue;

	//��ʾ��һ������
	cout<<"Please enter a fullname: ";
	cin.getline(name,Len);
	while ((count<N)&&(strlen(name)>0))
	{
		cout<<"Please enter a handicap value: ";
		cin>>handicapvalue;
		cin.get();
		setgolf(g[count], name, handicapvalue);
		count++;
		cout<<endl;
		cout<<"Please enter a fullname: ";
		cin.getline(name,Len);
	}
	cout<<endl<<endl;
	if (0==count)
		cout<<"None.";
	for (int i=0; i<count; i++)
	{
		cout<<endl;
		cout<<"Name: "<<g[i].fullname<<endl;
		cout<<"Handicap Value: "<<g[i].handicap<<endl;
	}



	return 0;
}