#include <iostream>
#include <fstream>
using namespace std;

// Use member function write( (char*)&var , sizeof(var) ) to write a binary file. 
void task01()
{
    ofstream out("out.txt", ios::binary);
    for (int i = 0; i < 10; ++i)
    {
        out.write((char *)&i, sizeof(i));
    }
    out.close();
}

//Use member function read( (char*)&var , sizeof(var) ) to read a binary file. 
void task02()
{
    int num = 0;
    ifstream in("out.txt");
    for (int i = 0; i < 10; ++i)
    {
        in.read((char *)&num, sizeof(i));
        cout << num << endl;
    }
    in.close();
}

int main()
{
    task01();
    task02();

    return 0;
}