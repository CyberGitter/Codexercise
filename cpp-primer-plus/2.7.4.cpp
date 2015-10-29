#include <iostream>
using namespace std;

int main()
{
	double ct;
	double convert(double ct);

	cout<<"Please enter a Celsius value:";
	cin>>ct;
	cout<<ct<<" degree Celsius is "<<convert(ct)<<" degrees Fahrenheit."<<endl;
	return 0;
}

double convert(double ct)
{
	return 1.8*ct+32.0;
}