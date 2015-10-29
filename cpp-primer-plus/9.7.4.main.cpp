#include <iostream>
#include "9.7.4.namesp.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using namespace SALES;

	Sales s1,s2;
	setSales(s1);
	setSales(s2,s1.sales,4);
	cout<<endl;
	cout<<"s1:"<<endl;
	showSales(s1);
	cout<<endl;
	cout<<"s2:"<<endl;
	showSales(s2);

	return 0;
}