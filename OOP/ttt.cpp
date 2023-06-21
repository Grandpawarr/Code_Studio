#include <iostream>
using namespace std;

int main()
{
    int *x=new int(20);
    int *y=new int(30);

    x=y;
    cout<<*x;
    
    return 0;
}
