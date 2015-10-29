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
    cout<<"ƽ���ɼ�Ϊ��"<<calculate(score,size)<<endl;
    return 0;
}

int fill_array(int ar[], int limit)
{
    cout<<"���������10���߶���ɼ����Ը������������"<<endl;
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
        }//�����΢��֮�����ڣ��������һ��С������3.1����cin��������ͨ����һ��ѭ��������3��Ȼ���ڵڶ���ѭ����������.���Ӷ�����
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
        cout<<"���гɼ��������£�"<<endl;
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