#include <iostream>
using namespace std;

double factorial(int n);

int main()
{
    cout<<"������һ���Ǹ�������ֵ���Ը�ֵ�������򣩣�";
    int n=0;
    while ((cin>>n)&&n>=0)
    {
        cout<<"�׳�Ϊ��"<<factorial(n)<<endl;
        cout<<"������һ���Ǹ�������ֵ���Ը�ֵ�������򣩣�";
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