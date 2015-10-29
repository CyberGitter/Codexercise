#include <iostream>
using namespace std;

double factorial(int n);

int main()
{
    cout<<"请输入一个非负的整数值（以负值结束程序）：";
    int n=0;
    while ((cin>>n)&&n>=0)
    {
        cout<<"阶乘为："<<factorial(n)<<endl;
        cout<<"请输入一个非负的整数值（以负值结束程序）：";
    }
    return 0;
}

double factorial(int n)
{
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}