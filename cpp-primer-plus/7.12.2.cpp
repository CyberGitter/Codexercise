#include <iostream>
using namespace std;
const int MAX=10;

int fill_array(int ar[], int limit);
void show_array(const int ar[], int n);
double calculate(const int ar[], int n);

int main()
{
    int score[MAX]={0};
    int size=fill_array(score,MAX);
    show_array(score,size);
    cout<<"平均成绩为："<<calculate(score,size)<<endl;
    return 0;
}

int fill_array(int ar[], int limit)
{
    cout<<"请输入最多10个高尔夫成绩，以负数输入结束："<<endl;
    int temp;
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
        }//这里的微妙之处在于，如果输入一个小数，如3.1，则cin首先允许通过第一轮循环，读入3；然后在第二轮循环中遇到“.”从而报错
        else if (temp<0)
            break;
        ar[i]=temp;
    }
    return i;
}

void show_array(const int ar[], int n)
{
    if (n==0)
        cout<<"No score."<<endl;
    else
    {
        cout<<"所有成绩汇总如下："<<endl;
        for (int i=0;i<n;i++)
            cout<<"#"<<(i+1)<<":"<<ar[i]<<"  ";
        cout<<endl;
    }
}

double calculate(const int ar[], int n)
{
    if (n==0)
        return 0;
    else
    {
        double total=0;
        for (int i=0;i<n;i++)
            total+=ar[i];
        return total/n;
    }
}