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
			cout<<"�������"<<i+1<<"��"<<j+1<<"�·ݵ���������";
			cin>>sale[i][j];
            year_sale[i]+=sale[i][j];
        }
        cout<<"��"<<i+1<<"���������Ϊ��"<<year_sale[i]<<endl;
        wholesale+=year_sale[i];
    }
    cout<<"�������������Ϊ��"<<wholesale<<endl;

    return 0;
}