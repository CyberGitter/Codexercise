#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void up(string &);

int main()
{
	string str;
	cout<<"Enter a string (q to quit): ";
	getline(cin,str);
	while(str!="q")
	{
		up(str);
		cout<<str<<endl;
		cout<<"Next string (q to quit): ";
		getline(cin,str);
	}
	cout<<"Bye."<<endl;
	return 0;
}

void up(string & str)
{
	int i=0;
	while(str[i])
	{
		str[i]=toupper(str[i]);//���toupper�⺯���Ƚϸ�Ц��˵��toupper(str[i])ֻ�ǽ�Сд��str[i]ת���ɴ�д�Ĳ����Ƶ�һ����ʱ�洢�����У�������ֱ���޸�str[i]
		i++;
	}
}