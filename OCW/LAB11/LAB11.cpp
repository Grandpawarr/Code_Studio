#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
//再重新嘗試看看

// FILE INPUT AND OUTPUT STREAM: FSTREAM
int task01(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: ./lab10-6 <filename> <target> <replace>" << endl;
        return 1;
    }

    fstream out(argv[1], ios::in | ios::out);
    // means that the file can be operated in two modes.
    if (out.fail())
    {
        cout << "Cannot open the file " << argv[1] << endl;

        return 1;
    }
    /*1.First, the seekp() points to the character at position 5 in file lab10-4.txt.
    Later, the put() write the character i to the current position.
       2.In seekp(), there are three modes: ios::beg, ios::cur and ios::end. ios::beg
    indicates the stream points to the position at beginning of the file. */

    out.seekp(atoi(argv[2]), ios::beg);
    out.put(*argv[3]);

    return 0;
}

// POINTER
void task02()
{
    int n = 10;
    int *p = &n;

    cout << "The address of n is " << &n << endl;
    cout << "The value of p is " << p << endl;
    cout << "The address of p is " << &p << endl;
    cout << "The variable pointed by p is " << *p << endl;
}

void task022()
{
    int n = 40;
    int *p1 = 0, *p2 = 0;

    cout << "n = " << n << endl;

    p1 = &n;
    *p1 = 60;
    cout << "n = " << n << endl;

    p2 = p1;
    *p2 = 50;
    cout << "n = " << n << endl;
}

// NEW AND DELETE OPERATOR 
void task03(){
    int n=10;
    int *p1=new int;
    p1=&n;

    int *p2=new int (1024);

    cout<<"*p1 = "<<*p1<<endl;
    cout<<"*p2 = "<<*p2<<endl;

    delete p1,p2;
}

// DYNAMIC ARRAY
void task04(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int *vec=new int[n];
    for(int idx=0;idx<n;idx++){
        vec[idx]=idx;
    }
    for(int idx=0;idx<n;idx++){
        cout<<vec[idx]<<" ";
    }
    cout<<endl;

    delete []vec;

}


int main()
{
    // task022();
    //task03();
    task04();
    return 0;
}