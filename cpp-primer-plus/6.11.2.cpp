#include <iostream>

const int MAX=10;

int main()
{
    using namespace std;
    double donation[MAX]={0},total=0,average=0;
    int i=0,count=0;
    cout<<"��������ֵ�����10�������������ֵ�����������"<<endl;
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
        cout<<"��Щ���ֵ�ƽ��ֵΪ��"<<average<<endl;
        for (int j=0;j<i;j++)
        {
            if (donation[j]>average)
                count++;
        }
        cout<<"�����й���"<<count<<"�����ִ���ƽ��ֵ��"<<endl;
    }
    return 0;
}