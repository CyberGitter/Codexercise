#include <iostream>

const int MAX=10;

int main()
{
    using namespace std;
    double donation[MAX]={0},total=0,average=0;
    int i=0,count=0;
    cout<<"请输入数值（最多10个，以任意非数值输入结束）："<<endl;
    cout<<"Donation #1: ";
    while ((i<MAX)&&(cin>>donation[i]))
    {
        if (++i<MAX)
            cout<<"Donation #"<<i+1<<": ";
    }


    if (i==0)
        cout<<"No donation.\n";
    else
    {
        for (int j=0;j<i;j++)
            total+=donation[j];
        average=total/i;
        cout<<"这些数字的平均值为："<<average<<endl;
        for (int j=0;j<i;j++)
        {
            if (donation[j]>average)
                count++;
        }
        cout<<"数组中共有"<<count<<"个数字大于平均值。"<<endl;
    }
    return 0;
}