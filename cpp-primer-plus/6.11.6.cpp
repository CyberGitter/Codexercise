#include <iostream>
#include <string>
using namespace std;

struct patron
{
	string name;
	double donation;
};

int main()
{
	int number,count=0;
	cout<<"�������������Ŀ��";
	cin>>number;
	cin.get();
	patron* ps=new patron[number];
	patron* pt=new patron[number];
	for (int i=0;i<number;i++)
	{
		cout<<"�������"<<i+1<<"λ�����ߵ�������";
		getline(cin,ps[i].name);
		cout<<"�������"<<i+1<<"λ�����ߵĿ��";
		while (!(cin>>ps[i].donation))
		{
			cin.clear();
			while (cin.get()!='\n')
				continue;
			cout<<"Please enter a number: ";
		}
		cin.get();
	}
	cout<<endl<<endl<<"Grand Patrons"<<endl<<endl;
	for (int i=0;i<number;i++)
	{
		if (ps[i].donation>=10000)
		{
			cout<<"Name: "<<ps[i].name<<endl<<"Donation: "<<ps[i].donation<<endl;
			count++;
		}
		else
			pt[i-count]=ps[i];
	}
	if (count==0)
		cout<<"none"<<endl<<endl;
	cout<<endl<<"Patrons"<<endl<<endl;
	if (count==number)
		cout<<"none"<<endl;
	else
	{
		for (int i=0;i<number-count;i++)
			cout<<"Name: "<<pt[i].name<<endl<<"Donation: "<<pt[i].donation<<endl;
	}
	return 0;
}