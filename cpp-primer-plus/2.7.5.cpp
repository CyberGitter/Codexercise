#include <iostream>
using namespace std;

double convert(double lightyear);

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	double lightyear;
	cout<<"Enter the number of light years:";
	cin>>lightyear;
	cout<<"4.2 light years = "<<convert(lightyear)<<" astronomical units."<<endl;
	return 0;
}

double convert(double lightyear)
{
	return lightyear*63240;
}