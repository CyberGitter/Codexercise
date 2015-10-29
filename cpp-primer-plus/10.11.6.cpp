#include <iostream>

using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a=0, double b=0);
	void showmove() const;
	Move add(const Move & m) const;
	void reset(double a=0, double b=0);
};

Move::Move(double a, double b)
{      //如果类声明后面没有分号，则会在此提示“构造函数不能有返回类型”的错误
	x=a;
	y=b;
}

void Move::showmove() const
{
	cout<<"x="<<x<<endl<<"y="<<y<<endl;
}

Move Move::add(const Move & m) const
{
	Move temp;
	temp.x=x+m.x;
	temp.y=y+m.y;
	return temp;
}

void Move::reset(double a, double b)
{
	x=a;
	y=b;
}


int main()
{
	Move m1;
	cout<<"Show m1: "<<endl;
	m1.showmove();
	cout<<endl;
	cout<<"Enter x, y value to set m2: "<<endl;
	double x,y;
	cin>>x>>y;
	Move m2(x,y);
	m2.showmove();
	cout<<endl;
	cout<<"Show sum: ";
	m1.add(m2).showmove();
	cout<<endl;
	cout<<"Enter x, y value to reset m2: "<<endl;
	cin>>x>>y;
	m2.reset(x, y);
	m2.showmove();
	return 0;
}