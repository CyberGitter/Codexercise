
#include <iostream.h>
#include <math.h>
#include <iomanip.h>
#include <fstream.h>

//下面这个常数是18岁年底所需要的（年金）现值（按年支出，先付费）
const long double PA=20000*(1-1/pow(1+0.05,4))/0.05*1.05;

//存款年限(1-16)
int n;

//下面这个数组存储这样一种系数：每月的支出乘以它，就得到18岁年底的终值；其中各个不同的元素对应不同的存款年限
long double Fcoefficient[17];

//下面这个数组存储对应于不同存款年限下，每月需支付的款额(0-4500)
long double y[17];

int main()
{
	//初始化系数数组
	for (n=1;n<=16;n++)
		Fcoefficient[n]=(pow(1+0.05/12,12*n)-1)/(0.05/12)*pow(1+0.05/12,12*(16-n));

	//计算每月需支付的款额
	for (n=1;n<=16;n++)
		y[n]=PA/Fcoefficient[n];

	//显示表单
	for (n=1; n<=16; n++)
	{
		cout<<setw(2)<<n;
		if (y[n]>4500)
		{
			cout<<"          "<<endl;
			continue;
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		cout<<setw(10)<<y[n]<<endl;
	}


	//输出到文本文件
	ofstream outFile;
	outFile.open("教育基金.txt");
	//输出表单
	for (n=1; n<=16; n++)
	{
		outFile<<setw(2)<<n;
		if (y[n]>4500)
		{
			outFile<<"          "<<endl;
			continue;
		}
		outFile<<setiosflags(ios::fixed)<<setprecision(2);
		outFile<<setw(10)<<y[n]<<endl;
	}

	return 0;

}
