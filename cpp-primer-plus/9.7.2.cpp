//static.cpp -- using a static local variable
#include <iostream>
#include <string>
using namespace std;//�����Щ�޻���˵��i don't know how, but it did it.����Ұ��������ֻ�Ƿֱ�Ƕ�뵽��������������У�main������strcount�����У���������ֲ��ٴ��󡣰������������ŵ����ڵ�λ�ã���һ�α���ͨ��

void strcount(const string &);

int main()
{
	string input;

	cout<<"Enter a line: "<<endl;
	getline(cin,input);
	while (input!="")
	{
		strcount(input);
		cout<<"Enter next line (empty line to quit): "<<endl;
		getline(cin,input);
	}
	cout<<"Bye."<<endl;
	return 0;
}

void strcount(const string & str)
{
	static int total=0;
	int count=0;
	int i=0;
	cout<<"\""<<str<<"\" contains ";
	while (str[i])
	{
		count++;
		i++;
	}
	total+=count;
	cout<<count<<" characters\n";
	cout<<total<<" characters total\n";
}