#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string test;
    short number=0;
    cout<<"Enter words (to stop, type the word done):"<<endl;
    cin>>test;
    while (test!="done")
    {
        number++;
        cin>>test;
    }
    cout<<"You entered a total of "<<number<<" words."<<endl;
    return 0;
}