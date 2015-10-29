#include <iostream>

int main()
{
	using namespace std;
	long int small, big, sum=0;
	cout<<"请输入两个不同的整数（较小者在前）：";
	cin>>small>>big;
	for (;small<=big;small++)
		sum+=small;
	cout<<"二者之间所有的整数和为："<<sum<<endl;
	return 0;
}