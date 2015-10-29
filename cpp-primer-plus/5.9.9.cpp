#include <iostream>

int main()
{
    using namespace std;
    int row=0;
    cout<<"Enter number of rows: ";
    cin>>row;
    for (int i=1;i<=row;i++)
    {
        for (int j=1;j<=row-i;j++)
            cout<<'.';
        for (int j=1;j<=i;j++)
            cout<<'*';
        cout<<endl;
    }
    return 0;
}