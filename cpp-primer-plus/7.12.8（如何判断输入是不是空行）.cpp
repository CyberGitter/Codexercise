#include <iostream>
#include <cstring>
using namespace std;

const int SLEN=30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
	cout<<"Enter class size: ";
	int class_size;
	cin>>class_size;
	while (cin.get()!='\n')
		continue;

	student * ptr_stu=new student[class_size];
	int entered=getinfo(ptr_stu, class_size);
	for (int i=0; i<entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3 (ptr_stu, entered);
	delete [] ptr_stu;
	cout<<"Done\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	int number=0;
	for (int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个学生的姓名：";
		cin.getline(pa[i].fullname,SLEN);
		if (0==strlen(pa[i].fullname))//判断输入是不是空行
			break;
		number++;
		cout<<"请输入第"<<i+1<<"个学生的爱好：";
		cin.getline(pa[i].hobby,SLEN);
		cout<<"请输入第"<<i+1<<"个学生的抽象等级：";
		while (!(cin>>pa[i].ooplevel))
		{
			cin.clear();
			while (cin.get()!='\n')
				continue;
			cout<<"Please enter a number: ";
		}
		cin.get();
	}
	return number;
}

void display1(student st)
{
	cout<<st.fullname<<endl;
	cout<<st.hobby<<endl;
	cout<<st.ooplevel<<endl;
}

void display2(const student * ps)
{
	cout<<ps->fullname<<endl;
	cout<<ps->hobby<<endl;
	cout<<ps->ooplevel<<endl;
}

void display3(const student pa[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<pa->fullname<<endl;
		cout<<pa->hobby<<endl;
		cout<<pa->ooplevel<<endl;
		pa++;
	}
}