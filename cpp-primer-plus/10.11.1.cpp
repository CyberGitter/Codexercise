#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class BankAccount
{
private:
	string name;
	string acctnum;
	double balance;
public:
	BankAccount();
	BankAccount(const std::string & client, const std::string & num, double bal=0.0);
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};

BankAccount::BankAccount()
{
	name="no name";
	acctnum="no number";
	balance=0.0;
}

BankAccount::BankAccount(const std::string & client, const std::string & num, double bal)
{
	name=client;
	acctnum=num;
	balance=bal;
}

void BankAccount::show(void) const
{
	cout<<"Name: "<<name<<endl;
	cout<<"Account Number: "<<acctnum<<endl;
	cout<<"Balance: "<<balance<<endl;
}

void BankAccount::deposit(double cash)
{
	if (cash<0)
		std::cerr<<"The amount of cash deposited can't be negative. Transaction is aborted."<<endl;
	else
		balance+=cash;
}

void BankAccount::withdraw(double cash)
{
	if (cash<0)
		std::cerr<<"The amount of cash withdrawed can't be negative. Transaction is aborted."<<endl;
	else
		balance-=cash;
}

int main()
{
	BankAccount BA1, BA2("ICBC", "123456");
	BA1.show();
	cout<<endl;
	BA2.show();
	cout<<endl;

	BA1.deposit(34);
	BA1.show();
	cout<<endl;

	BA2.withdraw(43);
	BA2.show();

	return 0;
}