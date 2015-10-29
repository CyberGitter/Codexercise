#include <iostream>
using namespace std;
const int MAX=50;

int fill_array(double ar[],int limit);
void show_array(const double ar[],int n);
void reverse_array(double ar[],int n);

int main()
{
    double arr[MAX]={0};
    cout<<"请输入double值（最多"<<MAX<<"个），输入非数字则结束。"<<endl;
    int size=fill_array(arr,MAX);
    show_array(arr,size);

    cout<<"反转数组："<<endl;
    reverse_array(arr,size);
    show_array(arr,size);

    cout<<"进一步反转数组中除第一个和最后一个元素之外的所有元素："<<endl;
    reverse_array(arr+1,size-2);//这里又有些微妙：反转的是刚才已被反转过一次的数组
    show_array(arr,size);

    return 0;
}

int fill_array(double ar[],int limit)
{
    double temp;
    int i;
    for (i=0;i<limit;i++)
    {
        cout<<"Enter value #"<<(i+1)<<": ";
        cin>>temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"Bad input; input process terminated.\n";
            break;
        }
        else if (temp<0)
            break;
        ar[i]=temp;
    }
    return i;
}

void show_array(const double ar[],int n)
{
    for (int i=0;i<n;i++)
        cout<<"Value #"<<(i+1)<<": "<<ar[i]<<endl;
}

void reverse_array(double ar[],int n)
{
    double temp=0;
    for (int i=0;i<n-1;i++,n--)
    {
        temp=ar[i];
        ar[i]=ar[n-1];
        ar[n-1]=temp;
    }
}