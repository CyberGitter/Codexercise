#include <iostream>
#include <string>

using namespace std;

struct car
{
    string make;
    unsigned short year;
};

int main()
{
    unsigned short number,i=0;
    cout<<"How many cars do you wish to catalog? ";
    cin>>number;
    cin.get();
    car* ps=new car[number];
    while (i<number)
    {
        cout<<"Car #"<<i+1<<":\nPlease enter the make: ";
        getline(cin,ps[i].make);
        cout<<"Please enter the year made: ";
        cin>>ps[i].year;
        cin.get();
        i++;
    }
    cout<<"Here is your collection:\n";
    for (i=0;i<number;i++)
    {
        cout<<ps[i].year<<' '<<ps[i].make<<endl;
    }

    return 0;
}