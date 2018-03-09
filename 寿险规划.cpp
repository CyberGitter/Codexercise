
#include <iostream.h>
#include <math.h>
#include <iomanip.h>
#include <fstream.h>

//假定张女士在70岁以后才可能死亡，最多活100岁。下面这个数组存储张女士在不同年龄死亡时所需要的年金现值
long double PA[31];

//下面这个数组存储这样的系数：只要把每月交的钱乘以这个系数，就可以得出在六十岁年底的终值。从第2个元素到第12个元素分别对应10-20年的年限
long double Fcoefficient[12];

//死亡年龄
int a;

//交钱年限
int n;

//循环计数器
int count;

//下面这个二维数组存储在不同的死亡年龄和交钱年限下每月需要交多少钱
long double money[31][12];

int main()
{
	//初始化两个数组
	for (a=71,count=1; a<=100; a++,count++)
	{
		PA[count]=30000/12*(1-pow(1.0025,-(a-60)*12))/0.0025;
	}
	for (n=10,count=1; n<=20; n++,count++)
	{
		Fcoefficient[count]=(pow(1.0025,12*n)-1)/0.0025*pow(1.0025,(30-n)*12);
	}

	//计算在不同的死亡年龄和交钱年限下每月需要交多少钱
	for (a=71; a<=100; a++)
		for (n=10; n<=20; n++)
		{
			money[a-70][n-9]=PA[a-70]/Fcoefficient[n-9];
		}


	//显示
	//首先显示第一行表头：不同的交钱年限
	cout<<"   ";   //空4格
	for (n=10; n<=20; n++)
		cout<<setw(10)<<n;
	cout<<endl;
	//然后开始显示表单
	for (a=71; a<=100; a++)
	{
		cout<<setw(3)<<a;
		for (n=10; n<=20; n++)
		{
			if (money[a-70][n-9]>2500)
			{
				cout<<"          ";
				continue;
			}
			cout<<setiosflags(ios::fixed)<<setprecision(2);
			cout<<setw(10)<<money[a-70][n-9];
		}
		cout<<endl;
	}


	//输出到文本文件
	ofstream outFile;
	outFile.open("寿险规划.txt");
	outFile<<"   ";   //空4格
	for (n=10; n<=20; n++)
		outFile<<setw(10)<<n;
	outFile<<endl;
	//然后开始显示表单
	for (a=71; a<=100; a++)
	{
		outFile<<setw(3)<<a;
		for (n=10; n<=20; n++)
		{
			if (money[a-70][n-9]>2500)
			{
				outFile<<"          ";
				continue;
			}
			outFile<<setiosflags(ios::fixed)<<setprecision(2);
			outFile<<setw(10)<<money[a-70][n-9];
		}
		outFile<<endl;
	}


	return 0;
}
