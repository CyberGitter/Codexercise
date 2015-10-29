#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(const T arr[],const int n)
{
	T element=arr[0];
	for (int i=1;i<n;i++)
	{
		if (element<arr[i])
			element=arr[i];
	}
	return element;
}

//�о������constʹ��һֱ�ܻ��ҡ���

template <> char * maxn(char * const pstr[],const int n)
{
	char * ps=pstr[0];
	for (int i=1;i<n;i++)
	{
		if (strlen(ps)<strlen(pstr[i]))
			ps=pstr[i];
	}
	return ps;//���ﲻ��return (int *) ps;��Ϊ�����൱�ڰ�psǿ��ת��Ϊ��intָ�롣ֻ�������cout��ʱ����(int *) ps
}

int main()
{
	int arr1[6]={45,456,3,345,345,5322};
	double arr2[4]={4.643,56.3,345.45,67.4};
	char * pstr[5]=
	{
		"dfrety355 grgegeg",
		"erg48549g4rgiogjew",
		"dfgjgdfgsfg",
		"iergorigueoigu43849t  rguergiwrgwrwgrg",
		"rgrlg"
	};
	cout<<maxn(arr1,6)<<endl;
	cout<<maxn(arr2,4)<<endl;
	cout<<(int *)maxn(pstr,5)<<endl;
	return 0;
}