//static.cpp -- using a static local variable
#include <iostream>
#include <string>
using namespace std;//这个有些无稽的说，i don't know how, but it did it.如果我把这个声明只是分别嵌入到下面的两个函数中：main函数和strcount函数中，则编译会出现不少错误。把这句声明提出放到现在的位置，则一次编译通过

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