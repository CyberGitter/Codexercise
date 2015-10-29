#include <iostream>
#include <iomanip>
#include "9.7.4.namesp.h"

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		for (int i=0;i<(n<4?n:4);i++)
			s.sales[i]=ar[i];
		for (int i=3;i>=n;i--)
			s.sales[i]=0;
		long double total=0;
		for (int i=0;i<(n<4?n:4);i++)
			total+=s.sales[i];
		s.average=total/(n<4?n:4);
		s.max=s.min=s.sales[0];
		for (int i=1;i<(n<4?n:4);i++)
		{
			s.max=s.max>=s.sales[i]?s.max:s.sales[i];
			s.min=s.min<=s.sales[i]?s.min:s.sales[i];
		}
	}

	void setSales(Sales & s)
	{
		for (int i=0;i<4;i++)
		{
			std::cout<<"Enter sale of Quarter "<<i+1<<": ";
			std::cin>>s.sales[i];
		}

		long double total=0;
		for (int i=0;i<4;i++)
			total+=s.sales[i];
		s.average=total/4;
		s.max=s.min=s.sales[0];
		for (int i=1;i<4;i++)
		{
			s.max=s.max>=s.sales[i]?s.max:s.sales[i];
			s.min=s.min<=s.sales[i]?s.min:s.sales[i];
		}
	}

	void showSales(const Sales & s)
	{
		using namespace std;
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		for (int i=0;i<4;i++)
			cout<<"sale of Quarter "<<i+1<<": "<<s.sales[i]<<endl;
		cout<<"average: "<<s.average<<endl;
		cout<<"max: "<<s.max<<endl;
		cout<<"min: "<<s.min<<endl;
	}
}