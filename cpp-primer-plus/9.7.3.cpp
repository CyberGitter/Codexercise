#include <iostream>
#include <cstring>
#include <new>

struct chaff
{
	char dross[20];
	int slag;
};

const int BUF=512;
char buffer1[BUF];
char * buffer2=new char[BUF];

void get_chaff(chaff *);
void show_chaff(chaff *);

int main()
{
	using namespace std;

	//方法1
	chaff * ps1=new (buffer1) chaff[2];
	for (int i=0;i<=1;i++)
		get_chaff(ps1+i);
	cout<<endl;
	for (int i=0;i<2;i++)
	{
		cout<<"chaff "<<i+1<<":"<<endl;
		show_chaff(ps1+i);
	}

	cout<<endl<<endl;

	//方法2
	chaff * ps2=new (buffer2) chaff[2];
	for (int i=0;i<=1;i++)
		get_chaff(ps2+i);
	cout<<endl;
	for (int i=0;i<2;i++)
	{
		cout<<"chaff "<<i+1<<":"<<endl;
		show_chaff(ps2+i);
	}

	return 0;
}

void get_chaff(chaff * p)
{
	using namespace std;
	char input[20];
	cout<<"Enter dross: ";
	cin>>input;
	strcpy(p->dross,input);
	cout<<"Enter slag: ";
	cin>>p->slag;
}

void show_chaff(chaff * p)
{
	using namespace std;
	cout<<"dross: "<<p->dross<<endl;
	cout<<"slag: "<<p->slag<<endl;
}