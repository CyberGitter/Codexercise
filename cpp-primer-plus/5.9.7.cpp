#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    const short ArSize=80;
    char test[ArSize];
    short number=0;
    cout<<"Enter words (to stop, type the word done):"<<endl;
    cin>>test;
    while (strcmp(test,"done"))
    {
        number++;
        cin>>test;
    }
    cout<<"You entered a total of "<<number<<" words."<<endl;
    return 0;
}