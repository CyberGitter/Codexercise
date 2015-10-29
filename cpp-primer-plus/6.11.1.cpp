#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    cout<<"Enter text for analysis, and type @ to terminate input.\n";
    char ch;
    cin.get(ch);
    while (ch!='@')
    {
        if (!isdigit(ch))
        {
            if (isalpha(ch))
            {
                if (islower(ch))
                    ch=toupper(ch);
                else ch=tolower(ch);
            }
            cout<<ch;
        }
        cin.get(ch);
    }
    return 0;
}