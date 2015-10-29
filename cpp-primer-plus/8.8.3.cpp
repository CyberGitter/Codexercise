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
		str[i]=toupper(str[i]);//这个toupper库函数比较搞笑的说，toupper(str[i])只是将小写的str[i]转换成大写的并复制到一个临时存储变量中，并不会直接修改str[i]
		i++;
	}
}