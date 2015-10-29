#include <iostream>
#include <cctype>
#include <string>

int main()
{
    using namespace std;
    string word;
    long vowel_count=0,consonant_count=0,other_count=0;
    cout<<"Enter words (q to quit):\n";
    cin>>word;
    while (word!="q")
    {
        if (isalpha(word[0]))
        {
            switch (word[0])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': vowel_count++; break;
            default: consonant_count++;
            }
        }
        else other_count++;
        cin>>word;
    }
    cout<<vowel_count<<" words beginning with vowels\n"<<consonant_count<<" words beginning with consonants\n"<<other_count<<" others\n";
    return 0;
}