#include <iostream>
double calculate(double x, double y);

int main()
{
    using namespace std;
    cout<<"Enter two numbers (0 to quit): ";
    double x=0,y=0;
    cin>>x>>y;
    while ((x!=0)&&(y!=0))
    {
        cout<<"调和平均值为："<<calculate(x,y)<<endl;
        cout<<"Enter two numbers (0 to quit): ";
        cin>>x>>y;
    }
    return 0;
}

double calculate(double x, double y)
{
    return 2.0*x*y/(x+y);
}