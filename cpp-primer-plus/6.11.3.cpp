//�������һֱ�����⣺����ȷѡ������ĸ֮�󣬱���Ҫ������Enter


#include <iostream>
using namespace std;
void showmenu();

int main()
{
    showmenu();
    char choice;
    cin>>choice;
    int i=1;
    while (i)
    {
        if (cin.get()==' '||cin.get()=='\t'||cin.get()=='\n')   //��ֹ������c��p��t��gΪ���ַ����ַ�������
        {
            switch (choice)
            {
            case 'c': cout<<"A lion is a carnivore.\n"; i=0; break;
            case 'p': cout<<"She is a pianist.\n"; i=0; break;
            case 't': cout<<"A maple is a tree.\n"; i=0; break;
            case 'g': cout<<"The StarCraft is a game.\n"; i=0; break;
            default:cin.clear();
                    while (cin.get()!='\n')
                        continue;
                    cout<<"Please enter a c, p, t, or g: ";
                    cin>>choice;
            }
        }
        else
        {
            cin.clear();
            while (cin.get()!='\n')
                continue;
            cout<<"Please enter a c, p, t, or g: ";
            cin>>choice;
        }
    }
    return 0;
}






void showmenu()
{
    cout<<"Please enter one of the following choices:"<<endl;
    cout<<"c) carnivore           p) pianist"<<endl;
    cout<<"t) tree                g) game"<<endl;
}