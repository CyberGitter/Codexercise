//注意：要打开的文件须存放在程序所属项目的目录下
//如：\Visual Studio 2005\Projects\project_name

#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE=60;

int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;

    cout<<"Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout<<"Could not open the file "<<filename<<endl<<"Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    long count=0;
    inFile.get(ch);
    while (inFile.good())
    {
        count++;
        inFile.get(ch);
    }
    if (inFile.eof())
        cout<<"End of file reached.\n";
    else if (inFile.fail())
        cout<<"Input terminated by data mismatch.\n";
    else
        cout<<"Input terminated for unknown reason.\n";
    if (count==0)
        cout<<"No data processed.\n";
    else
        cout<<"Items read: "<<count<<endl;
    inFile.close();
    return 0;
}