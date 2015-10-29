#include <iostream>
using namespace std;
const int MAX=5;

//注意：end指针指向区间中最后一个元素后面的一个位置
double* fill_array(double ar[],int limit);
void show_array(const double ar[],const double* end);
void revalue(double r,double ar[],const double* end);

int main()
{
    cout<<"请输入最多5个double值（输入负数则结束）："<<endl;
    double properties[MAX]={0};
    double* end=fill_array(properties,MAX);
    show_array(properties,end);
    cout<<"Enter revaluation factor: ";
    double factor=0;
    cin>>factor;
    revalue(factor,properties,end);
    show_array(properties,end);
    cout<<"Done.\n";
    return 0;
}

double* fill_array(double ar[],int limit)
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
    return ar+i;
}

void show_array(const double ar[],const double* end)
{
    int i=1;
    for (const double* pt=ar;pt!=end;pt++,i++)
        cout<<"Property #"<<i<<": $"<<(*pt)<<endl;
}

void revalue(double r,double ar[],const double* end)
{
    for (double* pt=ar;pt!=end;pt++)
        (*pt)*=r;
}