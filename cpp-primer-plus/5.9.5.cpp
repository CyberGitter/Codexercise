#include <iostream>

int main()
{
	using namespace std;
    long sale[3][12]={0};
    long year_sale[3]={0};
    long wholesale=0;

	for (int i=0;i<3;i++)
    {
		for (int j=0;j<12;j++)
		{
			cout<<"请输入第"<<i+1<<"年"<<j+1<<"月份的销售量：";
			cin>>sale[i][j];
            year_sale[i]+=sale[i][j];
        }
        cout<<"第"<<i+1<<"年的销售量为："<<year_sale[i]<<endl;
        wholesale+=year_sale[i];
    }
    cout<<"三年的总销售量为："<<wholesale<<endl;

    return 0;
}