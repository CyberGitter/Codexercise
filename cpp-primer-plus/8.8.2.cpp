#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar
{
	char name[30];
	double weight;
	int heat;
};

void setCandyBar(CandyBar & candybar,char * name="Millennuim Munch",double weight=2.85,int heat=350);
void show(const CandyBar &);

int main()
{
	CandyBar candybar;

	setCandyBar(candybar);
	show(candybar);

	char name[30];
	double weight;
	int heat;
	cout<<"Please enter a name: ";
	cin>>name;
	cout<<"Enter weight: ";
	cin>>weight;
	cout<<"Enter heat: ";
	cin>>heat;
	setCandyBar(candybar,name,weight,heat);
	show(candybar);

	return 0;
}

void setCandyBar(CandyBar & candybar,char * name,double weight,int heat)
{
	strncpy(candybar.name,name,29);
	candybar.name[29]='\0';
	candybar.weight=weight;
	candybar.heat=heat;
}

void show(const CandyBar & candybar)
{
	cout<<"Name: "<<candybar.name<<endl;
	cout<<"Weight: "<<candybar.weight<<endl;
	cout<<"Heat: "<<candybar.heat<<endl;
}