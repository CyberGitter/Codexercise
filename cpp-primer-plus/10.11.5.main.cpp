#include <iostream>
#include <cctype>
#include "10.11.5.stack.h"

int main()
{
	using namespace std;
	Stack st;
	char ch;
	Item temp;
	long double sum=0;
	cout<<"Please enter A to add a customer structure, D to delete one, or Q to quit."<<endl;
	while (cin>>ch && toupper(ch)!='Q')
	{
		while (cin.get()!='\n')
			continue;
		if (!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':if (st.isfull())
					 cout<<"Stack already full\n";
				 else
				 {
					 cout<<"Enter a customer name to add: ";//可见toupper()函数是按值传递，它并不会改变ch实参值
					 cin.getline(temp.fullname, 35);
					 cout<<"Enter customer's payment: ";
					 cin>>temp.payment;
					 st.push(temp);
				 }
				 break;
		case 'D':
		case 'd':if (st.isempty())
					 cout<<"Stack already empty\n";
				 else
				 {
					 st.pop(temp);
					 sum+=temp.payment;
					 cout<<"The sum is: "<<sum<<endl;
				 }
		}
		cout<<endl;
		cout<<"Please enter A to add a customer structure, D to delete one, or Q to quit."<<endl;
	}
	cout<<"Bye.\n";
	return 0;
}